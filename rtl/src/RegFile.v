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
    parameter ADDR_WIDTH = 5, DATA_WIDTH = 32)
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
    
    
    reg [DATA_WIDTH-1:0] REG [1:31];
    integer i;

    //WRITE PORT
    always @(posedge CLK) begin
        if (RESET) begin
            for (i = 1; i < 32 ;i=i+1) begin
                if (i==2) REG[i] <= 32'h1000000;
                else if (i==3) REG[i] <= 32'h2000000;
                else  REG[i]  <= $unsigned(32'd0);
            end
        end 
        else if (WEN & (RD_SEL != 5'h0)) begin
            REG[RD_SEL] <= WB_DATA; 
        end
        
		`ifndef VERILATE
			$timeformat(-9,0,"ns");
			$write("RegisterFile \t");
			$write("time := %0t \n", $time);	
			$write("Reg00(00) := %08x \t", REG[0]);
			$write("Reg01(ra) := %08x \t", REG[1]);
			$write("Reg02(sp) := %08x \t", REG[2]);
			$write("Reg03(gp) := %08x \n", REG[3]);
			$write("Reg04(tp) := %08x \t", REG[4]);
			$write("Reg05(t0) := %08x \t", REG[5]);
			$write("Reg06(t1) := %08x \t", REG[6]);
			$write("Reg07(t2) := %08x \n", REG[7]);
			$write("Reg08(s0) := %08x \t", REG[8]);
			$write("Reg09(s1) := %08x \t", REG[9]);
			$write("Reg10(a0) := %08x \t", REG[10]);
			$write("Reg11(a1) := %08x \n", REG[11]);
			$write("Reg12(a2) := %08x \t", REG[12]);
			$write("Reg13(a3) := %08x \t", REG[13]);
			$write("Reg14(a4) := %08x \t", REG[14]);
			$write("Reg15(a5) := %08x \n", REG[15]);
			$write("Reg16(a6) := %08x \t", REG[16]);
			$write("Reg17(a7) := %08x \t", REG[17]);
			$write("Reg18(s2) := %08x \t", REG[18]);
			$write("Reg19(s3) := %08x \n", REG[19]);
			$write("Reg20(s4) := %08x \t", REG[20]);
			$write("Reg21(s5) := %08x \t", REG[21]);
			$write("Reg22(s6) := %08x \t", REG[22]);
			$write("Reg23(s7) := %08x \n", REG[23]);
			$write("Reg24(s8) := %08x \t", REG[24]);
			$write("Reg25(s9) := %08x \t", REG[25]);
			$write("Reg26(sA) := %08x \t", REG[26]);
			$write("Reg27(sB) := %08x \n", REG[27]);
			$write("Reg28(t3) := %08x \t", REG[28]);
			$write("Reg29(t4) := %08x \t", REG[29]);
			$write("Reg30(t5) := %08x \t", REG[30]);
			$write("Reg31(t6) := %08x \n", REG[31]);
		`endif 
        
    end

    //READ PORTS
     assign SRC1_DOUT = (RS1_SEL ==  5'h0) ? 32'h0 : ((RS1_SEL == RD_SEL) ? WB_DATA : REG[RS1_SEL]);
     assign SRC2_DOUT = (RS2_SEL ==  5'h0) ? 32'h0 : ((RS2_SEL == RD_SEL) ? WB_DATA : REG[RS2_SEL]);

    //assign SRC1_DOUT = (RS1_SEL ==  5'h0) ? 32'h0 : REG[RS1_SEL];
    //assign SRC2_DOUT = (RS2_SEL ==  5'h0) ? 32'h0 : REG[RS2_SEL];

endmodule