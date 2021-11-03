`timescale 1ns / 100ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2021 01:44:54 PM
// Design Name: 
// Module Name: BranchLogic_tb
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

module BranchLogic_tb;

localparam  BEQ = 3'b000,
            BNE = 3'b001,
            BLT = 3'b100,
            BGE = 3'b101,
            BLTU = 3'b110,
            BGEU = 3'b111;
    
    reg [31:0] src1; 
    reg [31:0] src2;  
    reg [2:0] func3;
    reg branch;
    wire brn_en;
    reg [31:0]  src1_ex   [0:7];
    reg [31:0]  src2_ex   [0:7];
    
    integer i;
    
    initial begin
        src1_ex[0]=32'h00000005;
        src2_ex[0]=32'h00000005;
        src1_ex[1]=32'hFFFFFFFB;
        src2_ex[1]=32'hFFFFFFFB;
        src1_ex[2]=32'h00000005;
        src2_ex[2]=32'h00000004;
        src1_ex[3]=32'h00000004;
        src2_ex[3]=32'h00000005;
        src1_ex[4]=32'hFFFFFFFB;
        src2_ex[4]=32'hFFFFFFFC;
        src1_ex[5]=32'hFFFFFFFC;
        src2_ex[5]=32'hFFFFFFFB;
        src1_ex[6]=32'h00000005;
        src2_ex[6]=32'hFFFFFFFB;
        src1_ex[7]=32'hFFFFFFFB;
        src2_ex[7]=32'h00000005;
    
    end
    

    BranchLogic UUT (
        .src1(src1),
        .src2(src2),
        .func3(func3),
        .branch(branch),
        .brn_en(brn_en)
    );

    initial begin
        src1 = 32'd0;
        src2 = 32'd0;
        func3 = 3'd0;
        branch = 1'b0;

        #20;
        
        ////////////////////////////////////////////////////////////////////////
        // non-branch instructions
        
//        func3 = BEQ;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
//        func3 = BNE;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
//        func3 = BLT;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
//        func3 = BGE;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
//        func3 = BLTU;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
//        func3 = BGEU;
//        for (i=0; i<8; i=i+1) begin
//            src1   <= src1_ex[i];      
//            src2   <= src2_ex[i];
//            #20;
//        end
        
        ////////////////////////////////////////////////////////////
        // branch instructions
        branch = 1'b1;
        
        func3 = BEQ;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
        func3 = BNE;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
        func3 = BLT;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
        func3 = BGE;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
        func3 = BLTU;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
        func3 = BGEU;
        for (i=0; i<8; i=i+1) begin
            src1   <= src1_ex[i];      
            src2   <= src2_ex[i];
            #20;
        end
        
    end

endmodule