`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/23/2021 19:06:30 AM
// Design Name: 
// Module Name: CoreMS.v
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module CoreMS (
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

// Fetch stage
 
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

InstMemory InstMemory(
    .PC(PC_sig),    // check
    .INST(INSTRUCTION)  
);


// FD boundary

reg [31:0] FD_PC = -4;
reg [31:0] FD_IR = 0;

always @(posedge CLK)
begin
    if (RESET) begin
        FD_PC <= -4;
        FD_IR <= 0;  // check
    end
    else begin
        FD_PC <= PC_sig;
        
        FD_IR <= INSTRUCTION;
    end
    
    $write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Decode stage

assign PC_PLUSFOUR = FD_PC + 32'd4;

RegFile RegFile (
    .CLK(CLK),
    .RESET(RESET),
    .WEN(MW_REGWRT),
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

Control Control(
    .INS(FD_IR),
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

// DE boundry

reg [31:0] DE_PC = -8; //check
reg [31:0] DE_IR=0;

reg [31:0] DE_PC_PLUSFOUR = -8; //check
reg [31:0] DE_SRC1; //check
reg [31:0] DE_SRC2; //check
reg [31:0] DE_IMM_EXT; //check

reg DE_BRN;
reg DE_ALUSRC1;
reg DE_ALUSRC2;
reg [3:0] DE_ALUOP;
reg DE_REGWRT;
reg DE_MEMRD;
reg DE_MEMWRT;
reg DE_WRTSRC;
reg DE_M2R;

always @(posedge CLK)
begin
    if (RESET) begin

        DE_PC <= DE_PC;        //check
        DE_IR <= 0;    // check

        DE_PC_PLUSFOUR <= PC_PLUSFOUR;
        DE_SRC1 <= SRC1;
        DE_SRC2 <= SRC2;
        DE_IMM_EXT <= IMM_EXT;
        
        DE_BRN <= BRN;
        DE_ALUSRC1 <= ALUSRC1;
        DE_ALUSRC2 <= ALUSRC2;
        DE_ALUOP <= ALUOP;
        DE_REGWRT <= REGWRT;
        DE_MEMRD <= MEMRD;
        DE_MEMWRT <= MEMWRT;
        DE_WRTSRC <= WRTSRC;
        DE_M2R <= M2R;

    end
    else begin

        DE_PC <= FD_PC;
        DE_IR <= FD_IR;

        DE_PC_PLUSFOUR <= PC_PLUSFOUR;
        DE_SRC1 <= SRC1;
        DE_SRC2 <= SRC2;
        DE_IMM_EXT <= IMM_EXT;

        DE_BRN <= BRN;
        DE_ALUSRC1 <= ALUSRC1;
        DE_ALUSRC2 <= ALUSRC2;
        DE_ALUOP <= ALUOP;
        DE_REGWRT <= REGWRT;
        DE_MEMRD <= MEMRD;
        DE_MEMWRT <= MEMWRT;
        DE_WRTSRC <= WRTSRC;
        DE_M2R <= M2R;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Execute stage

assign JUMP_BRANCH_TARGET = DE_PC + DE_IMM_EXT; //temp
assign JUMPREG_TARGET = DE_SRC1 + DE_IMM_EXT; //temp

BranchLogic BranchLogic(
    .src1(DE_SRC1), 
    .src2(DE_SRC2),  
    .func3(DE_IR[14:12]),
    .branch(DE_BRN),  
    .brn_en(BRNEN)
    );

assign ALU_IN1 = (DE_ALUSRC1 == ALUSRC1_RS1)? DE_SRC1: DE_PC;      // MUX1
assign ALU_IN2 = (DE_ALUSRC2 == ALUSRC2_RS2)? DE_SRC2: DE_IMM_EXT;  // MUX2

ALU ALU(
    .in1(ALU_IN1),
    .in2(ALU_IN2), 
    .alu_op(DE_ALUOP), 
    .alu_out(ALUOUT)
    );

// EM boundary

reg [31:0] EM_PC_PLUSFOUR = -8; //check
reg [31:0] EM_SRC2; //check
reg [31:0] EM_IR;

reg [31:0] EM_ALUOUT;

reg EM_REGWRT;
reg EM_MEMRD;
reg EM_MEMWRT;
reg EM_WRTSRC;
reg EM_M2R;


always @(posedge CLK)
begin
    if (RESET) begin
        EM_PC_PLUSFOUR <= DE_PC_PLUSFOUR;
        EM_SRC2 <= DE_SRC2;
        EM_IR <= DE_IR;    // check

        EM_ALUOUT <= ALUOUT;

        EM_REGWRT <= DE_REGWRT;
        EM_MEMRD <= DE_MEMRD;
        EM_MEMWRT <= DE_MEMWRT;
        EM_WRTSRC <= DE_WRTSRC;
        EM_M2R <= DE_M2R;

    end
    else begin
        
        EM_PC_PLUSFOUR <= DE_PC_PLUSFOUR;
        EM_SRC2 <= DE_SRC2;
        EM_IR <= DE_IR;

        EM_ALUOUT <= ALUOUT;

        EM_REGWRT <= DE_REGWRT;
        EM_MEMRD <= DE_MEMRD;
        EM_MEMWRT <= DE_MEMWRT;
        EM_WRTSRC <= DE_WRTSRC;
        EM_M2R <= DE_M2R;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Memory Access stage

DataMemory DataMemory(
    .CLK(CLK),
    .RESET(RESET),
    .MRd(EM_MEMRD),
    .MWrt(EM_MEMWRT),
    .FUNC3(EM_IR[14:12]),
    .IN_ADDR(EM_ALUOUT),
    .W_DATA(EM_SRC2),
    .R_DATA(R_DATA)
);

// MW boundary

reg [31:0] MW_PC_PLUSFOUR = -8; //check
reg [31:0] MW_ALUOUT;

reg [31:0] MW_R_DATA;

reg MW_REGWRT;
reg MW_WRTSRC;
reg MW_M2R;


always @(posedge CLK)
begin
    if (RESET) begin

        MW_PC_PLUSFOUR <= EM_PC_PLUSFOUR;
        MW_ALUOUT <= EM_ALUOUT;

        MW_R_DATA <= R_DATA;

        MW_REGWRT <= EM_REGWRT;
        MW_WRTSRC <= EM_WRTSRC;
        MW_M2R <= EM_M2R;

    end
    else begin
        
        MW_PC_PLUSFOUR <= EM_PC_PLUSFOUR;
        MW_ALUOUT <= EM_ALUOUT;

        MW_R_DATA <= R_DATA;

        MW_REGWRT <= EM_REGWRT;
        MW_WRTSRC <= EM_WRTSRC;
        MW_M2R <= EM_M2R;

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Write Back stage

assign REG_IN = (MW_WRTSRC) ? ((MW_M2R) ? MW_R_DATA : MW_ALUOUT) : MW_PC_PLUSFOUR; // MUX3 and MUX4

endmodule