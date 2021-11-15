`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/04/2021 10:53:30 AM
// Design Name: 
// Module Name: Core.v
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
    .IN_ADDR(ALUOUT),
    .W_DATA(SRC2),
    .R_DATA(R_DATA)
);

assign REG_IN = (WRTSRC) ? ((M2R) ? R_DATA : ALUOUT) : PC_PLUSFOUR;

endmodule