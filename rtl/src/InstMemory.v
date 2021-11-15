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
    
reg [31:0]  I_MEM   [0:256];

initial $readmemh("instruction_memory.mem" , I_MEM);

// initial begin
//     I_MEM[0] = 32'hfe010113;    //addi	sp,sp,-32
//     I_MEM[1] = 32'h02010413;   //addi	s0,sp,32
//     I_MEM[2] = 32'ha9478793;    //addi	a5,a5,-1388  # 0x10af8
//     I_MEM[3] = 32'h00178713;    //addi	a4,a5,1
//     I_MEM[4] = 32'h00f707b3;    //add	a5,a4,a5


//     I_MEM[5] = 32'h00271713;    //slli	a4,a4,0x2
//     I_MEM[6] = 32'h01045793;    //srli	a5,s0,0x10

// end

assign INST = ($signed(PC)<0) ? 32'd0 :I_MEM[(PC>>2)];


endmodule



