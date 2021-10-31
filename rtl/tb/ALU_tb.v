`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: ALU_tb
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

module ALU_tb;
    reg [31:0] in1,in2;
    reg [3:0] alu_op;
    wire [31:0] alu_out;

   
    ALU UUT (
        .in1(in1),
        .in2(in2),
        .alu_op(alu_op),
        .alu_out(alu_out)
    );

    initial begin
        in1 = 32'b11111111111111111111111111111110;
        //in2 = 32'b11111111111111111111111111111111;
        in2 = 32'd14;
        alu_op = 4'd11;
    end

endmodule