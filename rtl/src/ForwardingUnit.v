`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/25/2021 10:29:06 AM
// Design Name: 
// Module Name: StallUnit.v
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
 /* verilator lint_off UNUSED */

module ForwardingUnit(
    input [4:0] DE_RS1,
    input [4:0] DE_RS2,
    input [4:0] EM_RD,
    input [4:0] MW_RD,
    
    input EM_REGWRT,
    input EM_M2R,
    input EM_WRTSRC,
    input MW_REGWRT,
    input MW_M2R,
    input MW_WRTSRC,

    output [2:0] FWD_MUX1,
    output [2:0] FWD_MUX2  
);


wire RS1_EM_RD_EQUAL, RS1_MW_RD_EQUAL, RS2_EM_RD_EQUAL, RS2_MW_RD_EQUAL;

assign RS1_EM_RD_EQUAL = (DE_RS1==EM_RD) && (DE_RS1!= 5'd0) && (EM_REGWRT==1'd1);
assign RS1_MW_RD_EQUAL = (DE_RS1==MW_RD) && (DE_RS1!= 5'd0) && (MW_REGWRT==1'd1);
assign RS2_EM_RD_EQUAL = (DE_RS2==EM_RD) && (DE_RS2!= 5'd0) && (EM_REGWRT==1'd1);
assign RS2_MW_RD_EQUAL = (DE_RS2==MW_RD) && (DE_RS2!= 5'd0) && (MW_REGWRT==1'd1);


assign FWD_MUX1 = (RS1_EM_RD_EQUAL && (EM_M2R==1'd0) && (EM_WRTSRC==1'd1) )? 3'd1: //EM_ALU_OUT
                 (RS1_EM_RD_EQUAL && (EM_M2R==1'd1) && (EM_WRTSRC==1'd1) )? 3'd2: //R_DATA
                 (RS1_EM_RD_EQUAL && (EM_M2R==1'd0) && (EM_WRTSRC==1'd0) )? 3'd3: //EM_PC+4
                 (RS1_MW_RD_EQUAL)? 3'd4: // WB_DATA
                 3'd0; //default DE_SRC1


assign FWD_MUX2 = (RS2_EM_RD_EQUAL && (EM_M2R==1'd0) && (EM_WRTSRC==1'd1) )? 3'd1: //EM_ALU_OUT
                 (RS2_EM_RD_EQUAL && (EM_M2R==1'd1) && (EM_WRTSRC==1'd1) )? 3'd2: //R_DATA
                 (RS2_EM_RD_EQUAL && (EM_M2R==1'd0) && (EM_WRTSRC==1'd0) )? 3'd3: //EM_PC+4
                 (RS2_MW_RD_EQUAL)? 3'd4: // WB_DATA
                 3'd0; //default DE_SRC2

endmodule
