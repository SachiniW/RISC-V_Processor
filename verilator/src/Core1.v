module Core (
    input CLK,
    input RESET
);

`include "define.v"

wire [31:0] INSTRUCTION;
wire [2:0] TYPE;
wire JUMP, JUMPR, BRN, ALUSRC1,ALUSRC2, MEMRD, MEMWRT, M2R, WRTSRC, REGWRT;
wire [3:0] ALUOP;
wire BRNEN;
wire [31:0] JUMP_BRANCH_TARGET;
wire [31:0] JUMPREG_TARGET;
wire [31:0] PC_PLUSFOUR;
wire [31:0] SRC1, SRC2, IMM_EXT;
wire [2:0] FUNC3;
wire [31:0] PC_sig;
wire [31:0] REG_IN;
wire [31:0] ALUOUT;
wire [31:0] R_DATA; 
wire [31:0] ALU_IN1;
wire [31:0] ALU_IN2;
 
PCSelect PCSelect(
    .JUMP(JUMP),
    .JUMPREG(JUMPR),
    .BRANCH(BRNEN),
    .PC_PLUSFOUR(PC_PLUSFOUR),
    .JUMP_TARGET(JUMP_BRANCH_TARGET),
    .JUMPREG_TARGET(JUMPREG_TARGET),
    .BRANCH_TARGET(JUMP_BRANCH_TARGET),
    .NEXT_PC(PC_sig)
);

BranchLogic BranchLogic(
    .src1(SRC1), 
    .src2(SRC2),  
    .func3(INSTRUCTION[14:12]),
    .branch(BRN),  
    .brn_en(BRNEN)
    );

assign JUMP_BRANCH_TARGET = PC + IMM_EXT; //temp
assign JUMPREG_TARGET = SRC1 + IMM_EXT; //temp

reg [31:0] PC = -4;

always @(posedge CLK)
begin
    if (RESET) begin
        PC <= -4;
    end
    else begin
        PC <= PC_sig;
    end
    
    $write("\nInstruction : %08x \n" , INSTRUCTION);
end

assign PC_PLUSFOUR = PC + 32'd4;

InstMemory InstMemory(
    .PC(PC),
    .INST(INSTRUCTION)  
);

ImmExtend ImmExtend(
    .INS(INSTRUCTION),
    .TYPE(TYPE), 
    .IMM_EXT(IMM_EXT)
    );

Control Control(
    .INS(INSTRUCTION),
    .CS_TYPE(TYPE),
    .CS_JUMP(JUMP),
    .CS_JUMPR(JUMPR),
    .CS_BRANCH(BRN),
    .CS_ALUOP(ALUOP),
    .CS_ALUSRC1(ALUSRC1),
    .CS_ALUSRC2(ALUSRC2),
    .CS_MEMRD(MEMRD),
    .CS_MEMWRT(MEMWRT),
    .CS_M2R(M2R),
    .CS_WRTSRC(WRTSRC),
    .CS_REGWRT(REGWRT)
);

RegFile RegFile (
    .CLK(CLK),
    .RESET(RESET),
    .WEN(REGWRT),
    .RS1_SEL(INSTRUCTION[19:15]),
    .RS2_SEL(INSTRUCTION[24:20]),
    .RD_SEL(INSTRUCTION[11:7]),
    .WB_DATA(REG_IN),
    .SRC1_DOUT(SRC1),
    .SRC2_DOUT(SRC2)
    );

assign ALU_IN1 = (ALUSRC1 == ALUSRC1_RS1)? SRC1: PC;
assign ALU_IN2 = (ALUSRC2 == ALUSRC2_RS2)? SRC2: IMM_EXT;

ALU ALU(
    .in1(ALU_IN1),
    .in2(ALU_IN2), 
    .alu_op(ALUOP), 
    .alu_out(ALUOUT)
    );


DataMemory DataMemory(
    .CLK(CLK),
    .RESET(RESET),
    .MRd(MEMRD),
    .MWrt(MEMWRT),
    .FUNC3(INSTRUCTION[14:12]),
    .IN_ADDR(ALUOUT),
    .W_DATA(SRC2),
    .R_DATA(R_DATA)
);

assign REG_IN = (WRTSRC) ? ((M2R) ? R_DATA : ALUOUT) : PC_PLUSFOUR;

endmodule

module ALU(
    input [31:0] in1, //rs1
    input [31:0] in2, //rs2 or imm 
    input [3:0] alu_op, // inst[] 
    output [31:0] alu_out
    );

    `include "define.v"

    assign alu_out = (alu_op  == ALU_ADD)? in1+in2: //ADD
                     (alu_op  == ALU_SUB)? in1-in2: //SUB
                     (alu_op  == ALU_AND)? in1&in2: //AND
                     (alu_op  == ALU_OR)? in1|in2: //OR
                     (alu_op  == ALU_XOR)? in1^in2: //XOR
                     ((alu_op == ALU_SLT)&($signed(in1) < $signed(in2)))? 31'd1: //SLT
                     (alu_op  == ALU_SLL)? in1 << in2[4:0]: //SLL
                     ((alu_op == ALU_SLTU)&(in1 < in2))? 31'd1: //SLTU
                     (alu_op  == ALU_SRL)? in1 >> in2[4:0]: //SRL
                     (alu_op  == ALU_SRA)? $signed(in1[31:0]) >>> in2[4:0]: //SRA
                     (alu_op  == ALU_COPY1)? in1: //COPY in1
                     (alu_op  == ALU_COPY2)? in2: //COPY in2  
                      32'd0;

	
endmodule

module BranchLogic(
    input [31:0] src1, 
    input [31:0] src2,  
    input [2:0] func3,
    input branch,  
    output brn_en
    );

    `include "define.v"

    wire w_equal;
    wire w_signed;
    wire w_unsigned;

    assign w_equal = (src1 == src2) ? 1'b1 : 1'b0;
    assign w_signed = ($signed(src1) < $signed(src2)) ? 1'b1 : 1'b0;
    assign w_unsigned = (src1 < src2) ? 1'b1 : 1'b0;

    assign brn_en = branch & (
                        ((func3 == BEQ) & (w_equal)) |
                        ((func3 == BNE) & (~w_equal)) |
                        ((func3 == BLT) & (w_signed)) |
                        ((func3 == BGE) & (~w_signed)) |
                        ((func3 == BLTU) & (w_unsigned)) |
                        ((func3 == BGEU) & (~w_unsigned)) );

	
endmodule


module Control(
    input [31:0] INS,
    output [2:0] CS_TYPE,
    output       CS_JUMP,
    output       CS_JUMPR,
    output       CS_BRANCH,
    output [3:0] CS_ALUOP,
    output       CS_ALUSRC1,
    output       CS_ALUSRC2,
    output       CS_MEMRD,
    output       CS_MEMWRT,
    output       CS_M2R,
    output       CS_WRTSRC,
    output       CS_REGWRT
);


`include "define.v"

wire [10:0] INS_ARR;
wire [16:0] control_sig;

assign CS_TYPE      = control_sig[16:14];
assign CS_JUMP      = control_sig[13];
assign CS_JUMPR     = control_sig[12];
assign CS_BRANCH    = control_sig[11];
assign CS_ALUOP     = control_sig[10:7];
assign CS_ALUSRC1   = control_sig[6];
assign CS_ALUSRC2   = control_sig[5];
assign CS_MEMRD     = control_sig[4];
assign CS_MEMWRT    = control_sig[3];
assign CS_M2R       = control_sig[2];
assign CS_WRTSRC    = control_sig[1];
assign CS_REGWRT    = control_sig[0];

assign INS_ARR = {INS[30],INS[14:12],INS[6:0]};


                                                 //type | jump | jumpR | branch |   aluop   |   aluSrc1   |   aluSrc2   | memRd | memWrt | m2r  | wrtSrc | regWrt
assign control_sig = (INS_ARR[6:0] == LUI)      ? {  U ,  1'b0 ,  1'b0 ,  1'b0  , ALU_COPY2 , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //LUI
                     (INS_ARR[6:0] == AUIPC)    ? {  U ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_PC  , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //AUIPC
                     (INS_ARR[6:0] == JAL)      ? {  J ,  1'b1 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b0  , 1'b1  }:   //JAL
                     (INS_ARR[9:0] == JALR)     ? {  I ,  1'b0 ,  1'b1 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b0  , 1'b1  }:   //JALR
                     (INS_ARR[6:0] == BRANCH)   ? {  B ,  1'b0 ,  1'b0 ,  1'b1  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b0  , 1'b0  }:   //BEQ , BNE , BLT  , BGE , BLTU , BGEU
                     (INS_ARR[9:0] == LW)       ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b1  ,  1'b0 , 1'b1  ,  1'b1  , 1'b1  }:   //LW
                     (INS_ARR[9:0] == LB)       ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b1  ,  1'b0 , 1'b1  ,  1'b1  , 1'b1  }:   //LB
                     (INS_ARR[9:0] == LH)       ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b1  ,  1'b0 , 1'b1  ,  1'b1  , 1'b1  }:   //LH
                     (INS_ARR[9:0] == LBU)      ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b1  ,  1'b0 , 1'b1  ,  1'b1  , 1'b1  }:   //LBU
                     (INS_ARR[9:0] == LHU)      ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b1  ,  1'b0 , 1'b1  ,  1'b1  , 1'b1  }:   //LHU
                     (INS_ARR[9:0] == SW)       ? {  S ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b1 , 1'b0  ,  1'b0  , 1'b0  }:   //SW
                     (INS_ARR[9:0] == SB)       ? {  S ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b1 , 1'b0  ,  1'b0  , 1'b0  }:   //SW
                     (INS_ARR[9:0] == SH)       ? {  S ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b1 , 1'b0  ,  1'b0  , 1'b0  }:   //SW
                     (INS_ARR[9:0] == ADDI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //ADDI
                     (INS_ARR[9:0] == SLTI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLTI
                     (INS_ARR[9:0] == SLTIU)    ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLTIU
                     (INS_ARR[9:0] == XORI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //XORI
                     (INS_ARR[9:0] == ORI)      ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //ORI
                     (INS_ARR[9:0] == ANDI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //ANDI
                     (INS_ARR      == SLLI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLLI
                     (INS_ARR      == SRLI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SRLI
                     (INS_ARR      == SRAI)     ? {  I ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_IMM , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SRAI
                     (INS_ARR      == ADD)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //ADD
                     (INS_ARR      == SUB)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SUB  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SUB
                     (INS_ARR      == SLL)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLL
                     (INS_ARR      == SLT)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLT
                     (INS_ARR      == SLTU)     ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SLTU
                     (INS_ARR      == XOR)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //XOR
                     (INS_ARR      == SRL)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SRL
                     (INS_ARR      == SRA)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //SRA
                     (INS_ARR      == OR)       ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //OR
                     (INS_ARR      == AND)      ? {  R ,  1'b0 ,  1'b0 ,  1'b0  ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_RS2 , 1'b0  ,  1'b0 , 1'b0  ,  1'b1  , 1'b1  }:   //AND      
                      17'b0;                                                         

endmodule

module DataMemory(
    input         CLK,
    input         RESET,
    input         MRd,
    input         MWrt,
    input   [2:0] FUNC3,
    input   [31:0]IN_ADDR,
    input   [31:0]W_DATA,
    output  [31:0]R_DATA
);

    localparam F3LB  = 3'b000;
    localparam F3LH  = 3'b001;
    localparam F3LW  = 3'b010;
    localparam F3LBU = 3'b100;
    localparam F3LHU = 3'b101;
    
    localparam F3SW = 3'b010;
    localparam F3SH = 3'b001;
    localparam F3SB = 3'b000;
    
    reg [31:0]  D_MEM   [0:511]; 

    integer i;
    wire [31:0]ADDR;
    wire [1:0]BYTE;
    wire HALFWORD;

    wire [31:0]LW;
    wire [15:0]LH;
    wire [ 7:0]LB;
    wire [31:0]LHU;
    wire [31:0]LBU;

    wire [31:0] BYTE_DATA ;
    wire [31:0] HALFWORD_DATA ;
    wire [31:0] BYTE_WR;
    wire [31:0] HALF_WR;

    assign ADDR     = IN_ADDR >> 2;
    assign BYTE     = IN_ADDR % 4;
    assign HALFWORD = IN_ADDR % 2;

    assign BYTE_DATA     = ~((32'hFF000000) >> ((3-BYTE)*8)); 
    assign HALFWORD_DATA = ~((32'hFFFF0000) >> ((1-HALFWORD)*16));

    assign BYTE_WR = BYTE_DATA & D_MEM[ADDR]; 
    assign HALF_WR = HALFWORD_DATA & D_MEM[ADDR];

    always @(posedge CLK) begin
        if (RESET) begin
            for (i = 0; i<512; i=i+1) begin
                D_MEM[i] <= 32'h0;
            end
        end
        else if (MWrt) begin
            if      (FUNC3 == F3SW)  D_MEM[ADDR] <=  W_DATA;
            else if (FUNC3 == F3SB)  D_MEM[ADDR] <= (W_DATA[7:0]  << BYTE*8)      | BYTE_WR ;
            else if (FUNC3 == F3SH)  D_MEM[ADDR] <= (W_DATA[15:0] << HALFWORD*16) | HALF_WR ;
        end
    end

    assign LW     = D_MEM[ADDR];

    assign LH     = ((HALFWORD == 1'b0)  && MRd) ? $signed(LW[15:0])   :  
                    ((HALFWORD == 1'b1)  && MRd) ? $signed(LW[31:16])  :  
                    32'h0;
                    
    assign LB     = ((BYTE == 2'd0)  && MRd) ? $signed(LW[7:0]) : 
                    ((BYTE == 2'd1)  && MRd) ? $signed(LW[15:8])  :  
                    ((BYTE == 2'd2)  && MRd) ? $signed(LW[23:16]) :  
                    ((BYTE == 2'd3)  && MRd) ? $signed(LW[31:24]):  
                    32'h0;

    assign LHU    = ((HALFWORD == 1'b0)  && MRd) ? LW[15:0]   :  
                    ((HALFWORD == 1'b1)  && MRd) ? LW[31:16]  :  
                    32'h0;
                    
    assign LBU    = ((BYTE == 2'd0)  && MRd) ? LW[7:0]   : 
                    ((BYTE == 2'd1)  && MRd) ? LW[15:8]  :  
                    ((BYTE == 2'd2)  && MRd) ? LW[23:16] :  
                    ((BYTE == 2'd3)  && MRd) ? LW[31:24] :  
                    32'h0;
 
    assign R_DATA = ((FUNC3 == F3LW)  && MRd) ? LW  :  //LW
                    ((FUNC3 == F3LB)  && MRd && ($signed(LB)>= 0)) ? LB :  //LB
                    ((FUNC3 == F3LB)  && MRd && ($signed(LB) < 0)) ? 32'hFFFFFF00 + LB :  //LB
                    ((FUNC3 == F3LH)  && MRd && ($signed(LH)>= 0)) ? LH  :  //LH
                    ((FUNC3 == F3LH)  && MRd && ($signed(LH) < 0)) ? 32'hFFFF0000 + LH :  //LH
                    ((FUNC3 == F3LBU) && MRd) ? LBU :  //LBU
                    ((FUNC3 == F3LHU) && MRd) ? LHU :  //LHU
                    32'h0;


endmodule

module ImmExtend(
    input [31:0] INS,
    input [2:0] TYPE, 
    output [31:0] IMM_EXT
    );

    `include "define.v"

    assign IMM_EXT[0] =     (TYPE  == I)? INS[20]: 
                            (TYPE  == S)? INS[7]: 
                            ((TYPE  == B)|(TYPE  == U)|(TYPE  == J))? 1'd0: 
                             1'd0;

    assign IMM_EXT[4:1] =   ((TYPE  == I)|(TYPE  == J))? INS[24:21]: 
                            ((TYPE  == S)|(TYPE  == B))? INS[11:8]: 
                            (TYPE  == U)? 4'd0: 
                             4'd0;

    assign IMM_EXT[10:5] =  ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == J))? INS[30:25]: 
                            (TYPE  == U)? 6'd0: 
                             6'd0;                         

    assign IMM_EXT[11] =    ((TYPE  == I)|(TYPE  == S))? INS[31]:  
                            (TYPE  == B)? INS[7]: 
                            (TYPE  == U)? 1'd0: 
                            (TYPE  == J)? INS[20]: 
                             1'd0;

    assign IMM_EXT[19:12] = ((TYPE  == I)|(TYPE  == S)|(TYPE  == B))? {8{INS[31]}}: 
                            (TYPE  == U)? INS[19:12]: 
                            (TYPE  == J)? INS[19:12]: 
                             8'd0; 

    assign IMM_EXT[30:20] = ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == J))? {11{INS[31]}}: 
                            (TYPE  == U)? INS[30:20]: 
                             11'd0;

    assign IMM_EXT[31] =    ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == U)|(TYPE  == J))? INS[31]: 
                             1'd0;                                                     
	
endmodule
module InstMemory (
    input [31:0] PC,
    output [31:0] INST  
);
    
reg [31:0]  I_MEM   [0:256];


initial $readmemh("instruction_memory.mem" , I_MEM);

assign INST = ($signed(PC)<0) ? 32'd0 :I_MEM[(PC>>2)];

endmodule

module PCSelect (
    input         JUMP,
    input         JUMPREG,
    input         BRANCH,
    input   [31:0]PC_PLUSFOUR,
    input   [31:0]JUMP_TARGET,
    input   [31:0]JUMPREG_TARGET,
    input   [31:0]BRANCH_TARGET,
    output  [31:0]NEXT_PC
);
    assign NEXT_PC = (JUMP) ? JUMP_TARGET: 
                     (JUMPREG) ? JUMPREG_TARGET:
                     (BRANCH) ? BRANCH_TARGET : PC_PLUSFOUR;

endmodule

module RegFile #(
    parameter ADDR_WIDTH = 5, DATA_WIDTH = 32)
    (
    input                   CLK,
    input                   RESET,
    input                   WEN,
    input   [ADDR_WIDTH-1:0]RS1_SEL,
    input   [ADDR_WIDTH-1:0]RS2_SEL,
    input   [ADDR_WIDTH-1:0]RD_SEL,
    input   [DATA_WIDTH-1:0]WB_DATA,
    output  [DATA_WIDTH-1:0]SRC1_DOUT,
    output  [DATA_WIDTH-1:0]SRC2_DOUT
    );
    
    
    reg [DATA_WIDTH-1:0] REG [1:31];
    integer i;

    //WRITE PORT
    always @(posedge CLK) begin
        if (RESET) begin
            for (i = 1; i <32 ;i=i+1) begin
                REG[i]  <= $unsigned(32'd0);
            end
        end 
        else if (WEN & (RD_SEL != 5'h0)) begin
            REG[RD_SEL] <= WB_DATA; 
        end

    //READ PORTS
    assign SRC1_DOUT = (RS1_SEL ==  5'h0) ? 32'h0 : REG[RS1_SEL];
    assign SRC2_DOUT = (RS2_SEL ==  5'h0) ? 32'h0 : REG[RS2_SEL];

endmodule