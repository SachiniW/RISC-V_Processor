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

    `include "define.v"
    
    wire [31:0] sra_out;
    
    assign sra_out = $signed(in1) >>> in2[4:0];

    assign alu_out = (alu_op  == ALU_ADD)? in1+in2: //ADD
                     (alu_op  == ALU_SUB)? in1-in2: //SUB
                     (alu_op  == ALU_AND)? in1&in2: //AND
                     (alu_op  == ALU_OR)? in1|in2: //OR
                     (alu_op  == ALU_XOR)? in1^in2: //XOR
                     ((alu_op == ALU_SLT)&($signed(in1) < $signed(in2)))? 31'd1: //SLT
                     (alu_op  == ALU_SLL)? in1 << in2[4:0]: //SLL
                     ((alu_op == ALU_SLTU)&(in1 < in2))? 31'd1: //SLTU
                     (alu_op  == ALU_SRL)? in1 >> in2[4:0]: //SRL
                     (alu_op  == ALU_SRA)? sra_out: //SRA
                     //(alu_op == ALU_SRA) ? 
                       //     (($signed(in1[31:0])<0) ?(((32'hffffffff)<<(31-in2[4:0]))|(in1 >> in2[4:0])):
                        //    (in1 >> in2[4:0])) :
                     (alu_op  == ALU_COPY1)? in1: //COPY in1
                     (alu_op  == ALU_COPY2)? in2: //COPY in2  
                      32'd0;

    //initial begin
    //    $display("%b", $signed(32'hfffff82f) >>> 15);
    //end
endmodule
