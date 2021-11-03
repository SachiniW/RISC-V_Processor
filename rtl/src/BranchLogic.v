`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2021 09:44:01 AM
// Design Name: 
// Module Name: BranchLogic
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


module BranchLogic(
    input [4:0] src1, 
    input [4:0] src2,  
    input [2:0] func3,
    input branch,  
    output brn_en
    );

    `include "define.v"

    assign brn_en = branch & (
                        ((func3 == BEQ) & (src1==src2)) |
                        ((func3 == BNE) & (src1!=src2)) |
                        ((func3 == BLT) & (src1<src2)) |
                        ((func3 == BGE) & (src1>=src2)) |
                        ((func3 == BLTU) & (src1<src2)) |
                        ((func3 == BGEU) & (src1>=src2)) );

	
endmodule
