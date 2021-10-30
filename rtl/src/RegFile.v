`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sanjula Thiranjaya
// 
// Create Date: 10/30/2021 11:35:36 AM
// Design Name: 
// Module Name: RegFile
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


module RegFile #(
    //fixed parameters
    localparam ADDR_WIDTH = 5,
    localparam DATA_WIDTH = 32) 
    (
    input                   CLK,
    input                   RESET,
    input                   WEN,
    input   [ADDR_WIDTH-1:0]RS1_SEL,
    input   [ADDR_WIDTH-1:0]RS2_SEL,
    input   [ADDR_WIDTH-1:0]RD_SEL,
    input   [DATA_WIDTH-1:0]WB_DATA,
    output  [DATA_WIDTH-1:0]SRC1_DOUT,
    output  [DATA_WIDTH-1:0]SRC2_DOUT
    );

    reg [DATA_WIDTH-1:0] REG [0:31];
    integer i;

    //WRITE PORT
    always @(posedge CLK) begin
        if (RESET) begin
            for (i = 0; i <32 ;i=i+1) begin
                REG[i]  <= 32'h0;
            end
        end 
        else if (WEN & (RD_SEL != 5'h0)) begin
            REG[RD_SEL] <= WB_DATA; 
        end
    end

    //READ PORTS
    assign SRC1_DOUT = (RS1_SEL ==  5'h0) ? 32'h0 : REG[RS1_SEL];
    assign SRC2_DOUT = (RS2_SEL ==  5'h0) ? 32'h0 : REG[RS2_SEL];

endmodule