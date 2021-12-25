`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/23/2021 19:06:30 AM
// Design Name: 
// Module Name: CorePipe.v
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
    `include "Control.v"
    `include "DataMemory.v"
    `include "ImmExtend.v"
    `include "InstMemory.v"
    `include "DataMemory.v"
    `include "PCSelect.v"
    `include "RegFile.v"
`endif


module CorePipe (
    input CLK,
    input RESET,
    output  [31:0]PRINT_VAL,
    output        PRINT_EN
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
wire        FLUSH, STALL;

// Fetch stage

reg DE_JUMP = 0;
reg DE_JUMPR = 0;
 
PCSelect PCSelect(
    .JUMP(DE_JUMP),
    .JUMPREG(DE_JUMPR),
    .BRANCH(BRNEN),
    .PC_PLUSFOUR(PC_PLUSFOUR),
    .JUMP_TARGET(JUMP_BRANCH_TARGET),
    .JUMPREG_TARGET(JUMPREG_TARGET),
    .BRANCH_TARGET(JUMP_BRANCH_TARGET),
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
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Decode stage


reg [31:0] MW_IR = 0;
reg MW_REGWRT = 0;

assign PC_PLUSFOUR = FD_PC + 32'd4;

RegFile RegFile (
    .CLK(CLK),
    .RESET(RESET),
    .WEN(MW_REGWRT),
    .RS1_SEL(FD_IR[19:15]),
    .RS2_SEL(FD_IR[24:20]),
    .RD_SEL(MW_IR[11:7]),
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

reg [31:0] DE_PC = 0; 
reg [31:0] DE_IR = 0;

reg [31:0] DE_PC_PLUSFOUR = 0; 
reg [31:0] DE_SRC1 = 0; 
reg [31:0] DE_SRC2 = 0; 
reg [31:0] DE_IMM_EXT = 0;

reg [2:0] DE_TYPE = 0;
//reg DE_JUMP = 0;
//reg DE_JUMPR = 0;
reg DE_BRN = 0;
reg DE_ALUSRC1 = 0;
reg DE_ALUSRC2 = 0;
reg [3:0] DE_ALUOP = 0;
reg DE_REGWRT = 0;
reg DE_MEMRD = 0;
reg DE_MEMWRT = 0;
reg DE_WRTSRC = 0;
reg DE_M2R = 0;

StallUnit StallUnit(
    .DE_SRC1(DE_IR[19:15]),
    .DE_SRC2(DE_IR[24:20]),
    .EM_RD(EM_IR[11:7]),
    .MW_RD(MW_IR[11:7]),
    .STALL_PROCESSOR(STALL),
    .TYPE(TYPE)  
);

always @(posedge CLK)
begin
    if (RESET) begin

        DE_PC <= 0;        
        DE_IR <= 0;    

        DE_PC_PLUSFOUR <= 0;
        DE_SRC1 <= 0;
        DE_SRC2 <= 0;
        DE_IMM_EXT <= 0;

        DE_TYPE <= 0;
        DE_JUMP <= 0; 
        DE_JUMPR <= 0;        
        DE_BRN <= 0;
        DE_ALUSRC1 <= 0;
        DE_ALUSRC2 <= 0;
        DE_ALUOP <= 0;
        DE_REGWRT <= 0;
        DE_MEMRD <= 0;
        DE_MEMWRT <= 0;
        DE_WRTSRC <= 0;
        DE_M2R <= 0;

    end
    else begin

        if (STALL)
        begin
            DE_PC <= DE_PC;
            DE_IR <= DE_IR;

            DE_PC_PLUSFOUR <= DE_PC_PLUSFOUR;
            if ((DE_IR[19:15]==MW_IR[11:7]) && MW_REGWRT) begin
                DE_SRC1 <= REG_IN;
            end
            else begin
                DE_SRC1 <= DE_SRC1;
            end 

            if ((DE_IR[24:20]==MW_IR[11:7]) && MW_REGWRT) begin
                DE_SRC2 <= REG_IN;
            end
            else begin
                DE_SRC2 <= DE_SRC2;
            end 

            DE_IMM_EXT <= DE_IMM_EXT;

            DE_TYPE <= DE_TYPE;
            DE_JUMP <= DE_JUMP; 
            DE_JUMPR <= DE_JUMPR; 
            DE_BRN <= DE_BRN;
            DE_ALUSRC1 <= DE_ALUSRC1;
            DE_ALUSRC2 <= DE_ALUSRC2;
            DE_ALUOP <= DE_ALUOP;
            DE_REGWRT <= DE_REGWRT;
            DE_MEMRD <= DE_MEMRD;
            DE_MEMWRT <= DE_MEMWRT;
            DE_WRTSRC <= DE_WRTSRC;
            DE_M2R <= DE_M2R; 

        end
        else
        begin
            DE_PC <= FD_PC;
            DE_IR <= FD_IR;

            DE_PC_PLUSFOUR <= PC_PLUSFOUR;
            DE_SRC1 <= SRC1;
            DE_SRC2 <= SRC2;
            DE_IMM_EXT <= IMM_EXT;

            if (FLUSH)
            begin
                DE_TYPE <= 0;
                DE_JUMP <= 0; 
                DE_JUMPR <= 0;        
                DE_BRN <= 0;
                DE_ALUSRC1 <= 0;
                DE_ALUSRC2 <= 0;
                DE_ALUOP <= 0;
                DE_REGWRT <= 0;
                DE_MEMRD <= 0;
                DE_MEMWRT <= 0;
                DE_WRTSRC <= 0;
                DE_M2R <= 0;
            end
            else
            begin
                DE_TYPE <= TYPE;
                DE_JUMP <= JUMP; 
                DE_JUMPR <= JUMPR; 
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
        end

        

    end
    
    //$write("\nInstruction : %08x \n" , INSTRUCTION);
end

// Execute stage

assign FLUSH = DE_JUMP || DE_JUMPR || BRNEN;

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

reg [31:0] EM_PC_PLUSFOUR = 0; 
reg [31:0] EM_SRC2 = 0; 
reg [31:0] EM_IR = 0;

reg [31:0] EM_ALUOUT = 0;

reg EM_REGWRT = 0;
reg EM_MEMRD = 0;
reg EM_MEMWRT = 0;
reg EM_WRTSRC = 0;
reg EM_M2R = 0;


always @(posedge CLK)
begin
    if (RESET) begin
        EM_PC_PLUSFOUR <= 0;
        EM_SRC2 <= 0;
        EM_IR <= 0;   

        EM_ALUOUT <= 0;

        EM_REGWRT <= 0;
        EM_MEMRD <= 0;
        EM_MEMWRT <= 0;
        EM_WRTSRC <= 0;
        EM_M2R <= 0;

    end
    else begin
        
        EM_PC_PLUSFOUR <= DE_PC_PLUSFOUR;
        EM_SRC2 <= DE_SRC2;


        EM_ALUOUT <= ALUOUT;

        if (STALL)
        begin
            EM_IR     <= 0 ; //changed
            EM_REGWRT <= 0;
            EM_MEMRD <= 0;
            EM_MEMWRT <= 0;
            EM_WRTSRC <= 0;
            EM_M2R <= 0;
        end
        else
        begin
            EM_IR <= DE_IR;
            EM_REGWRT <= DE_REGWRT;
            EM_MEMRD <= DE_MEMRD;
            EM_MEMWRT <= DE_MEMWRT;
            EM_WRTSRC <= DE_WRTSRC;
            EM_M2R <= DE_M2R;
        end


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
    .R_DATA(R_DATA),
    .PRINT_VAL(PRINT_VAL),
    .PRINT_EN(PRINT_EN)
);

// MW boundary

reg [31:0] MW_PC_PLUSFOUR = 0; 
//reg [31:0] MW_IR = 0;
reg [31:0] MW_ALUOUT = 0;

reg [31:0] MW_R_DATA = 0;

//reg MW_REGWRT = 0;
reg MW_WRTSRC = 0;
reg MW_M2R = 0;


always @(posedge CLK)
begin
    if (RESET) begin

        MW_PC_PLUSFOUR <= 0;
        MW_IR <= 0;
        MW_ALUOUT <= 0;

        MW_R_DATA <= 0;

        MW_REGWRT <= 0;
        MW_WRTSRC <= 0;
        MW_M2R <= 0;

    end
    else begin
        
        MW_PC_PLUSFOUR <= EM_PC_PLUSFOUR;
        MW_IR <= EM_IR;
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