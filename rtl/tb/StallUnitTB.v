`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: StallUnit_tb
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

module StallUnit_tb;
    reg [31:0] DE_IR = ;
    reg [31:0] EM_IR = ;
    reg [31:0] MW_IR = ;

    integer i;

    StallUnit StallUnit(
    .DE_SRC1(DE_IR[19:15]),
    .DE_SRC2(DE_IR[24:20]),
    .EM_RD(EM_IR[11:7]),
    .MW_RD(MW_IR[11:7]),
    .STALL_PROCESSOR(STALL),
    .TYPE(TYPE)  
);

    initial begin
        //in1 = 32'hfffff82f;
        //in2 = 32'hfffff82f;
        //alu_op = 4'd9;

        #20;

        /*
        for (i=0; i<12; i=i+1) begin
            in1        <= 32'd26;      
            in2        <= 32'd13;
            alu_op     <= i; 
            #20;
        end */
    end

endmodule