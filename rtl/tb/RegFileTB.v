`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sanjula Thiranjaya
// 
// Create Date: 10/30/2021 11:39:57 AM
// Design Name: 
// Module Name: RegFileTB
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


module RegFileTB();

    integer i;
    integer j;

    localparam CLK_PERIOD = 10;
    localparam ADDR_WIDTH = 5;
    localparam DATA_WIDTH = 32;

    reg                  CLK = 0;
    reg                  RESET;
    reg                  WEN;
    reg  [ADDR_WIDTH-1:0]RS1_SEL;
    reg  [ADDR_WIDTH-1:0]RS2_SEL;
    reg  [ADDR_WIDTH-1:0]RD_SEL;
    reg  [DATA_WIDTH-1:0]WB_DATA;
    wire [DATA_WIDTH-1:0]SRC1_DOUT;
    wire [DATA_WIDTH-1:0]SRC2_DOUT;

    RegFile UUT(CLK,RESET,WEN,RS1_SEL,RS2_SEL,RD_SEL,WB_DATA,SRC1_DOUT,SRC2_DOUT);

    initial begin
    forever begin
        #(CLK_PERIOD/2);
        CLK <= ~CLK;
    end
    end
    
    initial begin
        RESET       <= 1;
        WEN         <= 0;
        RS1_SEL     <= 5'd0;   
        RS2_SEL     <= 5'd0;
        RD_SEL      <= 5'd0;
        WB_DATA     <= 32'h0;

        #(CLK_PERIOD*10);
        RESET       <= 0;

        //WRITE PORT TEST
        for (i=0; i<32; i=i+1) begin
            WEN         <= 1;      
            RD_SEL      <= i;
            WB_DATA     <= i*13; 
            #(CLK_PERIOD*1);
        end
        
        WEN <= 0;

        //READ PORT TEST
        for (j=0; j<15; j=j+1) begin
            #(CLK_PERIOD*1);
            RS1_SEL      <= j;      
            RS2_SEL      <= 31-j;    
        end

        //ZERO REGISTER TEST
        #(CLK_PERIOD*5);
        WEN             <= 1;      
        RD_SEL          <= 0;
        WB_DATA         <= 23; 
        #(CLK_PERIOD*1);
        WB_DATA         <= 50; 
        #(CLK_PERIOD*1);
        WB_DATA         <= 73; 
        #(CLK_PERIOD*1);
        WEN             <= 0;

    end

endmodule
