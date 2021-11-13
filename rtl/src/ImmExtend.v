`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2021 09:44:01 AM
// Design Name: 
// Module Name: ImmExtend
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


module ImmExtend(
    input [31:0] INS,
    input [2:0] TYPE, 
    output [31:0] IMM_EXT
    );

    `include "define.v"

    assign IMM_EXT[0] =     (TYPE  == I)? INS[20]: 
                            (TYPE  == S)? INS[7]: 
                            ((TYPE  == B)|(TYPE  == U)|(TYPE  == J))? 1'd0: 
                             1'd0;

    assign IMM_EXT[4:1] =   ((TYPE  == I)|(TYPE  == J))? INS[24:21]: 
                            ((TYPE  == S)|(TYPE  == B))? INS[11:8]: 
                            (TYPE  == U)? 4'd0: 
                             4'd0;

    assign IMM_EXT[10:5] =  ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == J))? INS[30:25]: 
                            (TYPE  == U)? 6'd0: 
                             6'd0;                         

    assign IMM_EXT[11] =    ((TYPE  == I)|(TYPE  == S))? INS[31]:  
                            (TYPE  == B)? INS[7]: 
                            (TYPE  == U)? 1'd0: 
                            (TYPE  == J)? INS[20]: 
                             1'd0;

    assign IMM_EXT[19:12] = ((TYPE  == I)|(TYPE  == S)|(TYPE  == B))? {8{INS[31]}}: 
                            (TYPE  == U)? INS[19:12]: 
                            (TYPE  == J)? INS[19:12]: 
                             8'd0; 

    assign IMM_EXT[30:20] = ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == J))? {11{INS[31]}}: 
                            (TYPE  == U)? INS[30:20]:  //changed
                             11'd0;

    assign IMM_EXT[31] =    ((TYPE  == I)|(TYPE  == S)|(TYPE  == B)|(TYPE  == U)|(TYPE  == J))? INS[31]: 
                             1'd0;                                                     
	
endmodule
