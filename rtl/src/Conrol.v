`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2021 10:28:30 AM
// Design Name: 
// Module Name: Control
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


module Control(
input [31:0] INS,
output [16:0]CTRL_SIG
);


`include "define.v"

wire [11:0] INS_ARR;

assign INS_ARR = {INS[30],INS[14:12],INS[6:0]};


                                                 //type | jump | jumpR | branch |   aluop   |   aluSrc1   |   aluSrc2   | memRd | memWrt | m2r | wrtSrc | regWrt
assign control_sig = (INS_ARR[6:0] == LUI)      ? {  U ,    0  ,   0   ,   0    , ALU_COPY2 , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //LUI
                     (INS_ARR[6:0] == AUIPC)    ? {  U ,    0  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_PC  , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //AUIPC
                     (INS_ARR[6:0] == JAL)      ? {  J ,    1  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   0    ,   1   }:   //JAL
                     (INS_ARR[9:0] == JALR)     ? {  I ,    0  ,   1   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   0    ,   1   }:   //JALR
                     (INS_ARR[6:0] == BRANCH)   ? {  B ,    0  ,   0   ,   1    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   0    ,   0   }:   //BEQ , BNE , BLT  , BGE , BLTU , BGEU
                     (INS_ARR[9:0] == LW)       ? {  I ,    0  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM ,   1    ,  0    ,  1  ,   1    ,   1   }:   //LW
                     (INS_ARR[9:0] == SW)       ? {  S ,    0  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  1    ,  0  ,   0    ,   0   }:   //SW
                     (INS_ARR[9:0] == ADDI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //ADDI
                     (INS_ARR[9:0] == SLTI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLTI
                     (INS_ARR[9:0] == SLTIU)    ? {  I ,    0  ,   0   ,   0    ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLTIU
                     (INS_ARR[9:0] == XORI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //XORI
                     (INS_ARR[9:0] == ORI)      ? {  I ,    0  ,   0   ,   0    ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //ORI
                     (INS_ARR[9:0] == ANDI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //ANDI
                     (INS_ARR      == SLLI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLLI
                     (INS_ARR      == SRLI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SRLI
                     (INS_ARR      == SRAI)     ? {  I ,    0  ,   0   ,   0    ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_IMM ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SRAI
                     (INS_ARR      == ADD)      ? {  R ,    0  ,   0   ,   0    ,  ALU_ADD  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //ADD
                     (INS_ARR      == SUB)      ? {  R ,    0  ,   0   ,   0    ,  ALU_SUB  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SUB
                     (INS_ARR      == SLL)      ? {  R ,    0  ,   0   ,   0    ,  ALU_SLL  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLL
                     (INS_ARR      == SLT)      ? {  R ,    0  ,   0   ,   0    ,  ALU_SLT  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLT
                     (INS_ARR      == SLTU)     ? {  R ,    0  ,   0   ,   0    ,  ALU_SLTU , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SLTU
                     (INS_ARR      == XOR)      ? {  R ,    0  ,   0   ,   0    ,  ALU_XOR  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //XOR
                     (INS_ARR      == SRL)      ? {  R ,    0  ,   0   ,   0    ,  ALU_SRL  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SRL
                     (INS_ARR      == SRA)      ? {  R ,    0  ,   0   ,   0    ,  ALU_SRA  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //SRA
                     (INS_ARR      == OR)       ? {  R ,    0  ,   0   ,   0    ,  ALU_OR   , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //OR
                     (INS_ARR      == AND)      ? {  R ,    0  ,   0   ,   0    ,  ALU_AND  , ALUSRC1_RS1 , ALUSRC2_RS2 ,   0    ,  0    ,  0  ,   1    ,   1   }:   //AND      
                      17'b0;                                                         

endmodule
