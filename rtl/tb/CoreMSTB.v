`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: CoreMSTB
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

module CoreMSTB;

    localparam CLK_PERIOD = 10;

    reg CLK = 0;
    reg RESET = 0;

    initial begin
    forever begin
        #(CLK_PERIOD/2);
        CLK <= ~CLK;
    end
    end

    CoreMS CoreMS(
        .CLK(CLK),
        .RESET(RESET)
    );
    
    initial begin
        #(CLK_PERIOD);
        RESET = 1;
        #(CLK_PERIOD*6);

        RESET = 0;

        #(CLK_PERIOD*800);
        $finish;
    end


endmodule

