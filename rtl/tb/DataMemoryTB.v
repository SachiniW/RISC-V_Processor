`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sanjula Thiranjaya
// 
// Create Date: 11/03/2021 11:01:57 AM
// Design Name: 
// Module Name: DataMemoryTB
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


module DataMemoryTB();

    integer i;
    integer j;

    localparam CLK_PERIOD = 10;

    reg         CLK = 0;
    reg         RESET;
    reg         MRd;
    reg         MWrt;
    reg   [31:0]ADDR;
    reg   [31:0]W_DATA;
    wire  [31:0]R_DATA;

    DataMemory UUT(CLK,RESET,MRd,MWrt,ADDR,W_DATA,R_DATA);

    initial begin
    forever begin
        #(CLK_PERIOD/2);
        CLK = ~CLK;
    end
    end
    
    initial begin
        RESET   = 1;
        MRd     = 0;
        MWrt    = 0;
        ADDR    = 0;
        W_DATA  = 0;
   
    
    
        #(CLK_PERIOD*10);
        RESET       = 0;
    
        //WRITE PORT TEST
        for (i=0; i<128; i=i+4) begin
            MWrt        = 1;      
            ADDR        = i;
            W_DATA      = (i/4)*13; 
            #(CLK_PERIOD*1);
        end
        
        MWrt = 0;
        #(CLK_PERIOD*1);
    
        //READ PORT TEST
        for (j=0; j<60; j=j+4) begin
            #(CLK_PERIOD/2)
            MRd       = 1;      
            ADDR      = j; 
            #(CLK_PERIOD*1);   
        end
    
        MRd = 0;
    
    end

endmodule
