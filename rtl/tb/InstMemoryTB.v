`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: InstMemoryTB
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

module InstMemoryTB;
    reg [31:0] PC = 0;
    wire [31:0] INST;

    integer i;

    InstMemory UUT (PC,INST);

    initial begin
        for (i=0; i<7; i=i+1) begin
            PC = i; 
            #20;
        end
    end

endmodule