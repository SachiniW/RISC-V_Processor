`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2021 10:28:30 AM
// Design Name: 
// Module Name: ControlMS.v
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