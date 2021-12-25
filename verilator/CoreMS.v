/* verilator lint_off DECLFILENAME */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */

module CoreMS (
    input CLK,
    input RESET,
    output  [31:0]PRINT_VAL,
    output        PRINT_EN
);

`include "define.v"

wire [31:0] INSTRUCTION;
wire [2:0] TYPE;
wire STALL, JUMP, JUMPR, BRN, ALUSRC1,ALUSRC2, MEMRD, MEMWRT, M2R, WRTSRC, REGWRT, MEMSKIP;
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


// Pre Fetch boundary

reg EF_BRNEN = 0;
reg WF_JUMP = 0;
reg WF_JUMPR = 0;
reg [31:0] WF_JUMP_BRANCH_TARGET = 0;
reg [31:0] WF_JUMPREG_TARGET = 0;

always @(posedge CLK)
begin
    if (RESET) begin
        EF_BRNEN <= 0;
        WF_JUMP <= 0;
        WF_JUMPR <= 0;
        WF_JUMP_BRANCH_TARGET <= 0;
        WF_JUMPREG_TARGET <= 0;
    end
    else begin
        EF_BRNEN <= BRNEN;
        WF_JUMP <= MW_JUMP;
        WF_JUMPR <= MW_JUMPR;
        WF_JUMP_BRANCH_TARGET <= MW_JUMP_BRANCH_TARGET;
        WF_JUMPREG_TARGET <= MW_JUMPREG_TARGET;
    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end
// Fetch stage
 
PCSelect PCSelect(
    .JUMP(WF_JUMP),
    .JUMPREG(WF_JUMPR),
    .BRANCH(EF_BRNEN),
    .PC_PLUSFOUR(PC_PLUSFOUR),
    .JUMP_TARGET(WF_JUMP_BRANCH_TARGET),
    .JUMPREG_TARGET(WF_JUMPREG_TARGET),
    .BRANCH_TARGET(WF_JUMP_BRANCH_TARGET),
    .NEXT_PC(PC_sig)
);

InstMemory InstMemory(
    .PC(PC_sig),    
    .INST(INSTRUCTION)  
);


// FD boundary

reg [31:0] FD_PC = -4;
reg [31:0] FD_IR = 0;

always @(posedge CLK)
begin
    if (RESET) begin
        FD_PC <= -4;
        FD_IR <= 0;  
    end
    else begin
        if (STALL)
        begin
            FD_PC <= FD_PC;
            FD_IR <= FD_IR;
        end
        else
        begin
            FD_PC <= PC_sig;
            FD_IR <= INSTRUCTION;
        end
    end
    //$write("\nInstruction : %08x \n" , FD_IR);
end

// Decode stage

assign PC_PLUSFOUR = FD_PC + 32'd4;

RegFile RegFile (
    .CLK(CLK),
    .RESET(RESET),
    .WEN(REGWRT),
    .RS1_SEL(FD_IR[19:15]),
    .RS2_SEL(FD_IR[24:20]),
    .RD_SEL(FD_IR[11:7]),
    .WB_DATA(REG_IN),
    .SRC1_DOUT(SRC1),
    .SRC2_DOUT(SRC2)
    );

ImmExtend ImmExtend(
    .INS(FD_IR),
    .TYPE(TYPE), 
    .IMM_EXT(IMM_EXT)
    );

ControlMS ControlMS(
    .CLK(CLK),
    .RESET(RESET),
    .IR(FD_IR),
    .INS(INSTRUCTION),
    .CS_STALL(STALL),
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
    .CS_REGWRT(REGWRT),
    .CS_MEMSKIP(MEMSKIP)
);

// DE boundry

reg [31:0] DE_PC = 0; 
reg [31:0] DE_IR = 0;

reg [31:0] DE_PC_PLUSFOUR = 0; 
reg [31:0] DE_SRC1 = 0; 
reg [31:0] DE_SRC2 = 0; 
reg [31:0] DE_IMM_EXT = 0; 


always @(posedge CLK)
begin
    if (RESET) begin

        DE_PC <= 0;       
        DE_IR <= 0;    

        DE_PC_PLUSFOUR <= 0;
        DE_SRC1 <= 0;
        DE_SRC2 <= 0;
        DE_IMM_EXT <= 0;

    end
    else begin

        DE_PC <= FD_PC;
        DE_IR <= FD_IR;

        DE_PC_PLUSFOUR <= PC_PLUSFOUR;
        DE_SRC1 <= SRC1;
        DE_SRC2 <= SRC2;
        DE_IMM_EXT <= IMM_EXT;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Execute stage

assign JUMP_BRANCH_TARGET = DE_PC + DE_IMM_EXT; 
assign JUMPREG_TARGET = DE_SRC1 + DE_IMM_EXT;

BranchLogic BranchLogic(
    .src1(DE_SRC1), 
    .src2(DE_SRC2),  
    .func3(DE_IR[14:12]),
    .branch(BRN),  
    .brn_en(BRNEN)
    );

assign ALU_IN1 = (ALUSRC1 == ALUSRC1_RS1)? DE_SRC1: DE_PC;      // MUX1
assign ALU_IN2 = (ALUSRC2 == ALUSRC2_RS2)? DE_SRC2: DE_IMM_EXT;  // MUX2

ALU ALU(
    .in1(ALU_IN1),
    .in2(ALU_IN2), 
    .alu_op(ALUOP), 
    .alu_out(ALUOUT)
    );

// EM boundary

reg [31:0] EM_PC_PLUSFOUR = 0; 
reg [31:0] EM_SRC2 = 0; 
reg [31:0] EM_IR = 0;

reg [31:0] EM_ALUOUT = 0;

reg EM_JUMP = 0;
reg EM_JUMPR = 0;
reg [31:0] EM_JUMP_BRANCH_TARGET = 0;
reg [31:0] EM_JUMPREG_TARGET = 0;

always @(posedge CLK)
begin
    if (RESET) begin
        EM_PC_PLUSFOUR <= 0;
        EM_SRC2 <= 0;
        EM_IR <= 0;   

        EM_ALUOUT <= 0;

        EM_JUMP <= 0;
        EM_JUMPR <= 0;
        EM_JUMP_BRANCH_TARGET <= 0;
        EM_JUMPREG_TARGET <= 0;

    end
    else begin
        
        EM_PC_PLUSFOUR <= DE_PC_PLUSFOUR;
        EM_SRC2 <= DE_SRC2;
        EM_IR <= DE_IR;

        EM_ALUOUT <= ALUOUT;
        
        EM_JUMP <= JUMP;
        EM_JUMPR <= JUMPR;
        EM_JUMP_BRANCH_TARGET <= JUMP_BRANCH_TARGET;
        EM_JUMPREG_TARGET <= JUMPREG_TARGET;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Memory Access stage

DataMemory DataMemory(
    .CLK(CLK),
    .RESET(RESET),
    .MRd(MEMRD),
    .MWrt(MEMWRT),
    .FUNC3(EM_IR[14:12]),
    .IN_ADDR(EM_ALUOUT),
    .W_DATA(EM_SRC2),
    .R_DATA(R_DATA),
    .PRINT_VAL(PRINT_VAL),
    .PRINT_EN(PRINT_EN)
);

// MW boundary

reg [31:0] MW_PC_PLUSFOUR = 0; 
reg [31:0] MW_ALUOUT = 0;

reg [31:0] MW_R_DATA = 0;

reg MW_JUMP = 0;
reg MW_JUMPR = 0;
reg [31:0] MW_JUMP_BRANCH_TARGET = 0;
reg [31:0] MW_JUMPREG_TARGET = 0;


always @(posedge CLK)
begin
    if (RESET) begin

        MW_PC_PLUSFOUR <= 0;
        MW_ALUOUT <= 0;

        MW_R_DATA <= 0;

        MW_JUMP <= 0;
        MW_JUMPR <= 0;
        MW_JUMP_BRANCH_TARGET <= 0;
        MW_JUMPREG_TARGET <= 0;

    end
    else begin
        
        MW_PC_PLUSFOUR <= EM_PC_PLUSFOUR;
        MW_ALUOUT <= EM_ALUOUT;

        MW_R_DATA <= R_DATA;

        MW_JUMP <= EM_JUMP;
        MW_JUMPR <= EM_JUMPR;
        MW_JUMP_BRANCH_TARGET <= EM_JUMP_BRANCH_TARGET;
        MW_JUMPREG_TARGET <= EM_JUMPREG_TARGET;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Write Back stage

// assign REG_IN = (WRTSRC) ? ((M2R) ? MW_R_DATA : MW_ALUOUT) : MW_PC_PLUSFOUR; // MUX3 and MUX4
assign REG_IN = (WRTSRC) ? ((M2R) ? MW_R_DATA : ((MEMSKIP) ? EM_ALUOUT : MW_ALUOUT)) : ((MEMSKIP) ? EM_PC_PLUSFOUR : MW_PC_PLUSFOUR); // MUX3 and MUX4 and MEM SKIP MUX


endmodule


module ALU(
    input [31:0] in1, //rs1
    input [31:0] in2, //rs2 or imm 
    input [3:0] alu_op, // inst[] 
    output [31:0] alu_out
    );

    `include "define.v"
    
    wire [31:0] sra_out;
    
    assign sra_out = $signed(in1) >>> in2[4:0];

    assign alu_out = (alu_op  == ALU_ADD)? in1+in2: //ADD
                     (alu_op  == ALU_SUB)? in1-in2: //SUB
                     (alu_op  == ALU_AND)? in1&in2: //AND
                     (alu_op  == ALU_OR)? in1|in2: //OR
                     (alu_op  == ALU_XOR)? in1^in2: //XOR
                     ((alu_op == ALU_SLT)&($signed(in1) < $signed(in2)))? 31'd1: //SLT
                     (alu_op  == ALU_SLL)? in1 << in2[4:0]: //SLL
                     ((alu_op == ALU_SLTU)&(in1 < in2))? 31'd1: //SLTU
                     (alu_op  == ALU_SRL)? in1 >> in2[4:0]: //SRL
                     (alu_op  == ALU_SRA)? sra_out: //SRA
                     //(alu_op == ALU_SRA) ? 
                       //     (($signed(in1[31:0])<0) ?(((32'hffffffff)<<(31-in2[4:0]))|(in1 >> in2[4:0])):
                        //    (in1 >> in2[4:0])) :
                     (alu_op  == ALU_COPY1)? in1: //COPY in1
                     (alu_op  == ALU_COPY2)? in2: //COPY in2  
                      32'd0;

    //initial begin
    //    $display("%b", $signed(32'hfffff82f) >>> 15);
    //end	
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


module ControlMS(
    input        CLK,
    input        RESET,
    input [31:0] IR,
    input [31:0] INS,
    output       CS_STALL,
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
    output       CS_REGWRT,
    output       CS_MEMSKIP
);


`include "define.v"

wire [10:0] INS_ARR;
reg [18:0] CTRL_SIG = { 1'b1 ,  18'd0 };

wire [31:0] INSTRUCTION;

reg [2:0] state = FETCH; 

assign INSTRUCTION = (state==DECODE) ? INS : IR;

assign CS_STALL     = CTRL_SIG[18];
assign CS_TYPE      = CTRL_SIG[17:15];
assign CS_JUMP      = CTRL_SIG[14];
assign CS_JUMPR     = CTRL_SIG[13];
assign CS_BRANCH    = CTRL_SIG[12];
assign CS_ALUOP     = CTRL_SIG[11:8];
assign CS_ALUSRC1   = CTRL_SIG[7];
assign CS_ALUSRC2   = CTRL_SIG[6];
assign CS_MEMRD     = CTRL_SIG[5];
assign CS_MEMWRT    = CTRL_SIG[4];
assign CS_M2R       = CTRL_SIG[3];
assign CS_WRTSRC    = CTRL_SIG[2];
assign CS_REGWRT    = CTRL_SIG[1];
assign CS_MEMSKIP   = CTRL_SIG[0];

assign INS_ARR = {INSTRUCTION[30],INSTRUCTION[14:12],INSTRUCTION[6:0]};

  

always @(posedge CLK)
begin
    if (RESET)
    begin
        state <= FETCH;
        CTRL_SIG <= { 1'b1 ,  18'd0 };
    end
    else
    begin
        case (state)
            FETCH:begin
                CTRL_SIG <= { 1'b0 ,  18'd0 };
                state <= DECODE;
            end
            DECODE:begin
                if (INS_ARR[6:0] == LUI)         CTRL_SIG <= { 1'b1 ,  U ,  15'b0 };   //LUI
                else if (INS_ARR[6:0] == AUIPC)  CTRL_SIG <= { 1'b1 ,  U ,  15'b0 };   //AUIPC
                else if (INS_ARR[6:0] == JAL)    CTRL_SIG <= { 1'b1 ,  J ,  15'b0 };   //JAL
                else if (INS_ARR[9:0] == JALR)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //JALR
                else if (INS_ARR[6:0] == BRANCH) CTRL_SIG <= { 1'b1 ,  B ,  15'b0 };   //BEQ , BNE , BLT  , BGE , BLTU , BGEU
                else if (INS_ARR[9:0] == LW)     CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //LW
                else if (INS_ARR[9:0] == LB)     CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //LB
                else if (INS_ARR[9:0] == LH)     CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //LH
                else if (INS_ARR[9:0] == LBU)    CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //LBU
                else if (INS_ARR[9:0] == LHU)    CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //LHU
                else if (INS_ARR[9:0] == SW)     CTRL_SIG <= { 1'b1 ,  S ,  15'b0 };   //SW
                else if (INS_ARR[9:0] == SB)     CTRL_SIG <= { 1'b1 ,  S ,  15'b0 };   //SB
                else if (INS_ARR[9:0] == SH)     CTRL_SIG <= { 1'b1 ,  S ,  15'b0 };   //SH
                else if (INS_ARR[9:0] == ADDI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //ADDI
                else if (INS_ARR[9:0] == SLTI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //SLTI
                else if (INS_ARR[9:0] == SLTIU)  CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //SLTIU
                else if (INS_ARR[9:0] == XORI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //XORI
                else if (INS_ARR[9:0] == ORI)    CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //ORI
                else if (INS_ARR[9:0] == ANDI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //ANDI
                else if (INS_ARR      == SLLI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //SLLI
                else if (INS_ARR      == SRLI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //SRLI
                else if (INS_ARR      == SRAI)   CTRL_SIG <= { 1'b1 ,  I ,  15'b0 };   //SRAI
                else if (INS_ARR      == ADD)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //ADD
                else if (INS_ARR      == SUB)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SUB
                else if (INS_ARR      == SLL)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SLL
                else if (INS_ARR      == SLT)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SLT
                else if (INS_ARR      == SLTU)   CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SLTU
                else if (INS_ARR      == XOR)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //XOR
                else if (INS_ARR      == SRL)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SRL
                else if (INS_ARR      == SRA)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //SRA
                else if (INS_ARR      == OR)     CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //OR
                else if (INS_ARR      == AND)    CTRL_SIG <= { 1'b1 ,  R ,  15'b0 };   //AND
                else                             CTRL_SIG <= { 1'b1 ,  18'd0 }; 
                state <= EXECUTE;

            end
            EXECUTE:begin
                if (INS_ARR[6:0] == LUI)    
                begin
                    CTRL_SIG <= { 1'b1 , 6'd0  , ALU_COPY2 , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LUI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[6:0] == AUIPC)  
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0 ,  ALU_ADD  , ALUSRC1_PC  , ALUSRC2_IMM , 6'd0 };   //AUIPC
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[6:0] == JAL)    
                begin
                    CTRL_SIG <= { 1'b1 , 3'd0,  1'd1,  2'd0 ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //JAL
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == JALR)   
                begin
                    CTRL_SIG <= { 1'b1 ,  4'd0,  1'd1,  1'd0 ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //JALR
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[6:0] == BRANCH) 
                begin
                    CTRL_SIG <= { 1'b1 ,  5'd0 , 1'b1 ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //BEQ , BNE , BLT  , BGE , BLTU , BGEU
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LW)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LW
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == LB)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LB
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == LH)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LH
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == LBU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LBU
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == LHU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //LHU
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == SW)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SW
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == SB)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SB
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == SH)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SH
                    state <= MEMORY_ACCESS;
                end
                else if (INS_ARR[9:0] == ADDI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //ADDI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == SLTI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SLTI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == SLTIU)  
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SLTIU
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == XORI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //XORI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == ORI)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //ORI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == ANDI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //ANDI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SLLI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SLLI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SRLI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SRLI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SRAI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_IMM , 6'd0 };   //SRAI
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == ADD)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //ADD
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SUB)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SUB  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SUB
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SLL)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SLL
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SLT)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SLT
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SLTU)   
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SLTU
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == XOR)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //XOR
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SRL)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SRL
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == SRA)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //SRA
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == OR)     
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //OR
                    state <= WRITE_BACK;
                end
                else if (INS_ARR      == AND)    
                begin
                    CTRL_SIG <= { 1'b1 ,  6'd0  ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_RS2 , 6'd0 };   //AND
                    state <= WRITE_BACK;
                end
                else                             
                begin
                    CTRL_SIG <= { 1'b1 ,  18'd0 };
                    state <= FETCH;
                end
            end

            MEMORY_ACCESS:begin
                if (INS_ARR[9:0] == LW)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b1  ,  1'b0 , 4'd0 };   //LW
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == LB)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b1  ,  1'b0 , 4'd0 };   //LB
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == LH)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b1  ,  1'b0 , 4'd0 };   //LH
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == LBU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b1  ,  1'b0 , 4'd0 };   //LBU
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == LHU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b1  ,  1'b0 , 4'd0 };   //LHU
                    state <= WRITE_BACK;
                end
                else if (INS_ARR[9:0] == SW)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b0  ,  1'b1 , 4'd0 };   //SW
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == SB)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b0  ,  1'b1 , 4'd0 };   //SB
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == SH)     
                begin
                    CTRL_SIG <= { 1'b1 ,  12'd0  , 1'b0  ,  1'b1 , 4'd0 };   //SH
                    state <= FETCH;
                end
                else                             
                begin
                    CTRL_SIG <= { 1'b1 ,  18'd0 };
                    state <= FETCH;
                end
            end
            WRITE_BACK:begin
                if (INS_ARR[6:0] == LUI)    
                begin
                    CTRL_SIG <= { 1'b1 , 14'd0  , 1'b0  ,  1'b1  , 1'b1 , 1'd1 };   //LUI
                    state <= FETCH;
                end
                else if (INS_ARR[6:0] == AUIPC)  
                begin
                    CTRL_SIG <= { 1'b1 , 14'd0  , 1'b0  ,  1'b1  , 1'b1 , 1'd1 };   //AUIPC
                    state <= FETCH;
                end
                else if (INS_ARR[6:0] == JAL)    
                begin
                    CTRL_SIG <= { 1'b1 , 14'd0  , 1'b0  ,  1'b0  , 1'b1 , 1'd1 };   //JAL
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == JALR)   
                begin
                    CTRL_SIG <= { 1'b1 , 14'd0  , 1'b0  ,  1'b0  , 1'b1 , 1'd1 };   //JALR
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LW)     
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd1 , 1'd1 , 1'd1 , 1'd0 };   //LW
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LB)     
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd1 , 1'd1 , 1'd1 , 1'd0 };   //LB
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LH)     
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd1 , 1'd1 , 1'd1 , 1'd0 };   //LH
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LBU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd1 , 1'd1 , 1'd1 , 1'd0 };   //LBU
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == LHU)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd1 , 1'd1 , 1'd1 , 1'd0 };   //LHU
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == ADDI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1  , 1'd1 };   //ADDI
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == SLTI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1  , 1'd1 };   //SLTI
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == SLTIU)  
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SLTIU
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == XORI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //XORI
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == ORI)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //ORI
                    state <= FETCH;
                end
                else if (INS_ARR[9:0] == ANDI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //ANDI
                    state <= FETCH;
                end
                else if (INS_ARR      == SLLI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SLLI
                    state <= FETCH;
                end
                else if (INS_ARR      == SRLI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SRLI
                    state <= FETCH;
                end
                else if (INS_ARR      == SRAI)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SRAI
                    state <= FETCH;
                end
                else if (INS_ARR      == ADD)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //ADD
                    state <= FETCH;
                end
                else if (INS_ARR      == SUB)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SUB
                    state <= FETCH;
                end
                else if (INS_ARR      == SLL)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SLL
                    state <= FETCH;
                end
                else if (INS_ARR      == SLT)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SLT
                    state <= FETCH;
                end
                else if (INS_ARR      == SLTU)   
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SLTU
                    state <= FETCH;
                end
                else if (INS_ARR      == XOR)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //XOR
                    state <= FETCH;
                end
                else if (INS_ARR      == SRL)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SRL
                    state <= FETCH;
                end
                else if (INS_ARR      == SRA)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //SRA
                    state <= FETCH;
                end
                else if (INS_ARR      == OR)     
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //OR
                    state <= FETCH;
                end
                else if (INS_ARR      == AND)    
                begin
                    CTRL_SIG <= { 1'b1 ,  14'd0 , 1'd0 , 1'd1 , 1'd1 , 1'd1 };   //AND
                    state <= FETCH;
                end
                else                             
                begin
                    CTRL_SIG <= { 1'b1 ,  18'd0 };
                    state <= FETCH;
                end
            end
            default: begin
                CTRL_SIG <= { 1'b1 ,  18'd0 };
                state <= FETCH;
            end
        endcase
    end
    

end                                                     

endmodule



module DataMemory(
    input         CLK,
    input         RESET,
    input         MRd,
    input         MWrt,
    input   [2:0] FUNC3,
    input   [31:0]IN_ADDR,
    input   [31:0]W_DATA,
    output  [31:0]R_DATA,
    output  [31:0]PRINT_VAL,
    output        PRINT_EN
);

    localparam F3LB  = 3'b000;
    localparam F3LH  = 3'b001;
    localparam F3LW  = 3'b010;
    localparam F3LBU = 3'b100;
    localparam F3LHU = 3'b101;
    
    localparam F3SW = 3'b010;
    localparam F3SH = 3'b001;
    localparam F3SB = 3'b000;
    
    reg [31:0]  D_MEM   [0:25'h1ffffff]; 

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

    initial $readmemh("instruction_memory.mem" , D_MEM);

    always @(posedge CLK) begin
        if (!RESET && MWrt) begin
            if      (FUNC3 == F3SW)  D_MEM[ADDR] <=  W_DATA;
            else if (FUNC3 == F3SB)  D_MEM[ADDR] <= (W_DATA[7:0]  << BYTE*8)      | BYTE_WR ;
            else if (FUNC3 == F3SH)  D_MEM[ADDR] <= (W_DATA[15:0] << HALFWORD*16) | HALF_WR ;
        end
    end

    //assign PRINT_VAL = D_MEM[32'h3800040c]; // @[Core.scala 347:17]
    assign PRINT_VAL = W_DATA; // @[Core.scala 347:17]
    assign PRINT_EN = (ADDR == 32'h3800040c) && MWrt; // @[Core.scala 348:65]

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
    
reg [31:0]  I_MEM   [0:25'h1ffffff];


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
            for (i = 1; i < 32 ;i=i+1) begin
                if (i==2) REG[i] <= 32'h1000000;
                else if (i==3) REG[i] <= 32'h2000000;
                else  REG[i]  <= $unsigned(32'd0);
            end
        end 
        else if (WEN & (RD_SEL != 5'h0)) begin
            REG[RD_SEL] <= WB_DATA; 
        end
        
    end

    //READ PORTS
    assign SRC1_DOUT = (RS1_SEL ==  5'h0) ? 32'h0 : REG[RS1_SEL];
    assign SRC2_DOUT = (RS2_SEL ==  5'h0) ? 32'h0 : REG[RS2_SEL];

endmodule