`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2021 10:28:30 AM
// Design Name: 
// Module Name: DataMemory.v
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


module DataMemory(
    input         CLK,
    input         RESET,
    input         MRd,
    input         MWrt,
    input   [31:0]IN_ADDR,
    input   [31:0]W_DATA,
    output  [31:0]R_DATA
);
    
    reg [31:0]  D_MEM   [0:511]; 

    integer i;
    wire [31:0]ADDR;

    assign ADDR = IN_ADDR >> 2;

    always @(posedge CLK) begin
        if (RESET) begin
            for (i = 0; i<512; i=i+1) begin
                D_MEM[i] <= 32'h0;
            end
        end
        else if (MWrt) begin
            D_MEM[ADDR] <= W_DATA;
        end
    end

    assign R_DATA = (MRd) ? D_MEM[ADDR] : 32'h0;


endmodule