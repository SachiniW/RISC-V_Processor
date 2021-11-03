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
