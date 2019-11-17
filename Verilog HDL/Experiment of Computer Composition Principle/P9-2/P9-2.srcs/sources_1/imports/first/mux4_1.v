`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/04/05 19:32:06
// Design Name: 
// Module Name: mux4_1
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


module mux4_1(d0,d1,d2,d3,sel,d 
    );
     parameter data_width=32;
     input [data_width-1:0] d0;
     input [data_width-1:0] d1;
     input [data_width-1:0] d2;
     input [data_width-1:0] d3;
     input [1:0] sel;
     output reg [data_width-1:0] d;
     always @(*)
       case (sel)
          3'b00: d<=d0; 
          3'b01: d<=d1;
          3'b10: d<=d2; 
          3'b11: d<=d3; 
          default:d<=32'bz;
       endcase
endmodule
