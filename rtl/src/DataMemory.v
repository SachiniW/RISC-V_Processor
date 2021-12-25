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
    input   [2:0] FUNC3,
    input   [31:0]IN_ADDR,
    input   [31:0]W_DATA,
    output  [31:0]R_DATA,
    output  [31:0]PRINT_VAL,
    output        PRINT_EN
);

    localparam F3LB  = 3'b000;
    localparam F3LH  = 3'b001;
    localparam F3LW  = 3'b010;
    localparam F3LBU = 3'b100;
    localparam F3LHU = 3'b101;
    
    localparam F3SW = 3'b010;
    localparam F3SH = 3'b001;
    localparam F3SB = 3'b000;
    
    reg [31:0]  D_MEM   [0:25'h1ffffff]; 

    integer i;
    wire [31:0]ADDR;
    wire [1:0]BYTE;
    wire HALFWORD;

    wire [31:0]LW;
    wire [15:0]LH;
    wire [ 7:0]LB;
    wire [31:0]LHU;
    wire [31:0]LBU;

    wire [31:0] BYTE_DATA ;
    wire [31:0] HALFWORD_DATA ;
    wire [31:0] BYTE_WR;
    wire [31:0] HALF_WR;

    assign ADDR     = IN_ADDR >> 2;
    assign BYTE     = IN_ADDR % 4;
    assign HALFWORD = IN_ADDR % 2;

    assign BYTE_DATA     = ~((32'hFF000000) >> ((3-BYTE)*8)); 
    assign HALFWORD_DATA = ~((32'hFFFF0000) >> ((1-HALFWORD)*16));

    assign BYTE_WR = BYTE_DATA & D_MEM[ADDR]; 
    assign HALF_WR = HALFWORD_DATA & D_MEM[ADDR];

    initial $readmemh("instruction_memory.mem" , D_MEM);

    always @(posedge CLK) begin
        if (!RESET && MWrt) begin
            if      (FUNC3 == F3SW)  D_MEM[ADDR] <=  W_DATA;
            else if (FUNC3 == F3SB)  D_MEM[ADDR] <= (W_DATA[7:0]  << BYTE*8)      | BYTE_WR ;
            else if (FUNC3 == F3SH)  D_MEM[ADDR] <= (W_DATA[15:0] << HALFWORD*16) | HALF_WR ;
        end
    end

    //assign PRINT_VAL = D_MEM[32'h3800040c]; // @[Core.scala 347:17]
    assign PRINT_VAL = W_DATA; // @[Core.scala 347:17]
    assign PRINT_EN = (ADDR == 32'h3800040c) && MWrt; // @[Core.scala 348:65]

    assign LW     = D_MEM[ADDR];

    assign LH     = ((HALFWORD == 1'b0)  && MRd) ? $signed(LW[15:0])   :  
                    ((HALFWORD == 1'b1)  && MRd) ? $signed(LW[31:16])  :  
                    32'h0;
                    
    assign LB     = ((BYTE == 2'd0)  && MRd) ? $signed(LW[7:0]) : 
                    ((BYTE == 2'd1)  && MRd) ? $signed(LW[15:8])  :  
                    ((BYTE == 2'd2)  && MRd) ? $signed(LW[23:16]) :  
                    ((BYTE == 2'd3)  && MRd) ? $signed(LW[31:24]):  
                    32'h0;

    assign LHU    = ((HALFWORD == 1'b0)  && MRd) ? LW[15:0]   :  
                    ((HALFWORD == 1'b1)  && MRd) ? LW[31:16]  :  
                    32'h0;
                    
    assign LBU    = ((BYTE == 2'd0)  && MRd) ? LW[7:0]   : 
                    ((BYTE == 2'd1)  && MRd) ? LW[15:8]  :  
                    ((BYTE == 2'd2)  && MRd) ? LW[23:16] :  
                    ((BYTE == 2'd3)  && MRd) ? LW[31:24] :  
                    32'h0;
 
    assign R_DATA = ((FUNC3 == F3LW)  && MRd) ? LW  :  //LW
                    ((FUNC3 == F3LB)  && MRd && ($signed(LB)>= 0)) ? LB :  //LB
                    ((FUNC3 == F3LB)  && MRd && ($signed(LB) < 0)) ? 32'hFFFFFF00 + LB :  //LB
                    ((FUNC3 == F3LH)  && MRd && ($signed(LH)>= 0)) ? LH  :  //LH
                    ((FUNC3 == F3LH)  && MRd && ($signed(LH) < 0)) ? 32'hFFFF0000 + LH :  //LH
                    ((FUNC3 == F3LBU) && MRd) ? LBU :  //LBU
                    ((FUNC3 == F3LHU) && MRd) ? LHU :  //LHU
                    32'h0;


endmodule