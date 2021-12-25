`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2021 01:02:54 PM
// Design Name: 
// Module Name: PCSelect.v
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

module PCSelect (
    input         JUMP,
    input         JUMPREG,
    input         BRANCH,
    input   [31:0]PC_PLUSFOUR,
    input   [31:0]JUMP_TARGET,
    input   [31:0]JUMPREG_TARGET,
    input   [31:0]BRANCH_TARGET,
    output  [31:0]NEXT_PC
);
    assign NEXT_PC = (JUMP) ? JUMP_TARGET: 
                     (JUMPREG) ? JUMPREG_TARGET:
                     (BRANCH) ? BRANCH_TARGET : PC_PLUSFOUR;

endmodule




