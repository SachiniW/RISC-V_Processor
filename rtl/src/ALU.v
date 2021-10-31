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
    output reg [31:0] alu_out
    );

	always @(*)
		begin
			case(alu_op)
				4'd0: alu_out <= in1 + in2; //ADD
				4'd1: alu_out <= in1 - in2; //SUB
				4'd2: alu_out <= in1 & in2; //AND
				4'd3: alu_out <= in1 | in2; //OR
				4'd4: alu_out <= in1 ^ in2; //XOR
			    4'd5:begin //SLT
			        if ($signed(in1) < $signed(in2)) alu_out <= 31'd1; 
			        else           alu_out <= 31'd0;     
			        end 
				4'd6: alu_out <= in1 << in2[4:0]; //SLL
				4'd7:begin //SLTU
			        if (in1 < in2) alu_out <= 31'd1; 
                    else           alu_out <= 31'd0;     
                    end 								
				4'd8: alu_out <= in1 >> in2[4:0]; //SRL
				4'd9: alu_out <= $signed(in1[31:0]) >>> in2[4:0]; //SRA
                4'd10: alu_out <= in1; //COPY in1
                4'd11: alu_out <= in2; //COPY in2  				
				default: alu_out <= alu_out;
			endcase
		end	
		
endmodule
