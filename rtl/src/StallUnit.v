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

module StallUnit(
    input [4:0] DE_SRC1,
    input [4:0] DE_SRC2,
    input [4:0] EM_RD,
    input [4:0] MW_RD,
    input [2:0] TYPE,
    input EM_REGWRT,
    input MW_REGWRT,
    output STALL_PROCESSOR  
);
`include "define.v" 

wire STALL1, STALL2;

wire CHECK_SRC1_EM, CHECK_SRC2_EM, CHECK_SRC1_MW, CHECK_SRC2_MW;

assign CHECK_SRC1_EM = (DE_SRC1==EM_RD) && (DE_SRC1!= 5'd0);// && (EM_REGWRT==1'd1);
assign CHECK_SRC1_MW = (DE_SRC1==MW_RD) && (DE_SRC1!= 5'd0);// && (MW_REGWRT==1'd1);
assign CHECK_SRC2_EM = (DE_SRC2==EM_RD) && (DE_SRC2!= 5'd0);// && (EM_REGWRT==1'd1);
assign CHECK_SRC2_MW = (DE_SRC2==MW_RD) && (DE_SRC2!= 5'd0);// && (MW_REGWRT==1'd1);



assign STALL1 = ((TYPE==R)||(TYPE==S)||(TYPE==B)||(TYPE==U))&& (CHECK_SRC1_EM || CHECK_SRC1_MW || CHECK_SRC2_EM || CHECK_SRC2_MW) ? 1'b1: 1'b0;
assign STALL2 = (TYPE==I) && (CHECK_SRC1_EM || CHECK_SRC1_MW)  ? 1'b1: 1'b0;

// assign STALL_PROCESSOR  = ((TYPE==R)|(TYPE==S)|(TYPE==B))? (( (((DE_SRC1==EM_RD)|(DE_SRC2==EM_RD))&&(EM_RD!= 5'd0)) | (((DE_SRC1==MW_RD)|(DE_SRC2==MW_RD))&&(MW_RD!= 5'd0)) ) ? 1'b1: 1'b0):
//                           (TYPE==I) ? (((((DE_SRC1==EM_RD)&&(EM_RD!= 5'd0))|((DE_SRC1==MW_RD)&&(MW_RD!= 5'd0)))) ? 1'b1:1'b0):
//                           1'b0;


//assign STALL_PROCESSOR  = ( (((DE_SRC1==EM_RD)|(DE_SRC2==EM_RD))&&(EM_RD!= 5'd0)) | (((DE_SRC1==MW_RD)|(DE_SRC2==MW_RD))&&(MW_RD!= 5'd0)) ) ? 1'b1: 1'b0; //test

assign STALL_PROCESSOR = STALL1||STALL2;

endmodule
