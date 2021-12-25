`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2021 10:29:06 AM
// Design Name: 
// Module Name: InstMemory.v
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


module InstMemory (
    input [31:0] PC,
    output [31:0] INST  
);
    
reg [31:0]  I_MEM   [0:25'h1ffffff];


initial $readmemh("instruction_memory.mem" , I_MEM);

assign INST = ($signed(PC)<0) ? 32'd0 :I_MEM[(PC>>2)];

endmodule

