`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2021 09:44:01 AM
// Design Name: 
// Module Name: ALU
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


module ALU(
    input [31:0] in1, //rs1
    input [31:0] in2, //rs2 or imm 
    input [3:0] alu_op, // inst[] 
    output [31:0] alu_out
    );


    assign alu_out = (alu_op  == 4'd0)? in1+in2: //ADD
                     (alu_op  == 4'd1)? in1-in2: //SUB
                     (alu_op  == 4'd2)? in1&in2: //AND
                     (alu_op  == 4'd3)? in1|in2: //OR
                     (alu_op  == 4'd4)? in1^in2: //XOR
                     ((alu_op == 4'd5)&($signed(in1) < $signed(in2)))? 31'd1: //SLT
                     (alu_op  == 4'd6)? in1 << in2[4:0]: //SLL
                     ((alu_op == 4'd7)&(in1 < in2))? 31'd1: //SLTU
                     (alu_op  == 4'd8)? in1 >> in2[4:0]: //SRL
                     (alu_op  == 4'd9)? $signed(in1[31:0]) >>> in2[4:0]: //SRA
                     (alu_op == 4'd10)? in1: //COPY in1
                     (alu_op == 4'd11)? in2: //COPY in2  
                      32'd0;

	
endmodule
