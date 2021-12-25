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
`define VERILATE
`ifdef VERILATE
    /* verilator lint_off DECLFILENAME */
    /* verilator lint_off WIDTH */
    /* verilator lint_off UNUSED */
    /* verilator lint_off MODDUP */
    /* verilator lint_off IMPLICIT */

    `include "ALU.v"
    `include "BranchLogic.v"
    `include "ControlMS.v"
    `include "DataMemory.v"
    `include "ImmExtend.v"
    `include "InstMemory.v"
    `include "DataMemory.v"
    `include "PCSelect.v"
    `include "RegFile.v"
`endif

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
        WF_JUMP <= EM_JUMP;
        WF_JUMPR <= EM_JUMPR;
        WF_JUMP_BRANCH_TARGET <= EM_JUMP_BRANCH_TARGET;
        WF_JUMPREG_TARGET <= EM_JUMPREG_TARGET;
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
    .BRANCH_TARGET(EM_JUMP_BRANCH_TARGET),
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