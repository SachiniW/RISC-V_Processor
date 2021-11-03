`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: ImmExtendTB
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

module ImmExtendTB;
    reg [31:0] INS;
    reg [31:0] TYPE;
    wire [31:0]  IMM_EXT;

    integer i;

    ImmExtend UUT (INS,TYPE,IMM_EXT);

    initial begin
        INS = 32'b10101111001010110101110011111011; // 
        for (i=0; i<5; i=i+1) begin
            TYPE = i; 
            #20;
        end
    end

endmodule