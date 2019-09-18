//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/09/13 16:22:33
// Design Name: 
// Module Name: h_adder
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


module h_adder(a,b,co,so);
    output co,so;
    input a,b;
    wire a,b,co,so,bbar;
    and and2(co,a,b);
    not not1(bbar,b);
    xnor xnor2(so,a,bbar);
endmodule

