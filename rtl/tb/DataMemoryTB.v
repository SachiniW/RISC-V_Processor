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
    integer k;

    localparam CLK_PERIOD = 10;

    reg         CLK = 0;
    reg         RESET;
    reg         MRd;
    reg         MWrt;
    reg   [2:0] FUNC3;
    reg   [31:0]ADDR;
    reg   [31:0]W_DATA;
    wire  [31:0]R_DATA;

    DataMemory UUT(CLK,RESET,MRd,MWrt,FUNC3,ADDR,W_DATA,R_DATA);

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
        //FUNC3 = 3'b010; //change function to test
   
    
    
        #(CLK_PERIOD*10);
        RESET       = 0;

        //code to test signed/unsigned
            FUNC3 = 3'b001;//change function to test
            MWrt        = 1; 
            ADDR        = 0;
            W_DATA      = 8'b11110000; 
            #(CLK_PERIOD*2);
             
        //WRITE PORT TEST
        for (i=1; i<128; i=i+1) begin
            FUNC3 = 3'b000;//change function to test
            MWrt        = 1;      
            ADDR        = i;
            W_DATA      = (i*((-1)**i))*13; 
            #(CLK_PERIOD*2);
        end

        MWrt = 0;
        #(CLK_PERIOD*1);
    
        //READ PORT TEST
        for (j=0; j<60; j=j+1) begin
            FUNC3 = 3'b001;
            #(CLK_PERIOD/2)
            MRd       = 1;      
            ADDR      = j; 
            #(CLK_PERIOD*1);   
        end
    
        MRd = 0;
    
    end

endmodule
