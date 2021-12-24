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

    integer i;

    ALU UUT (
        .in1(in1),
        .in2(in2),
        .alu_op(alu_op),
        .alu_out(alu_out)
    );

    initial begin
        in1 = 32'hfffff82f;
        in2 = 32'hfffff82f;
        alu_op = 4'd9;

        #20;

        /*
        for (i=0; i<12; i=i+1) begin
            in1        <= 32'd26;      
            in2        <= 32'd13;
            alu_op     <= i; 
            #20;
        end */
    end

endmodule