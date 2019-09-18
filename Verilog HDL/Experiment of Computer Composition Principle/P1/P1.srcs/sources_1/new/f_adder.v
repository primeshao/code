//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/09/13 16:21:09
// Design Name: 
// Module Name: f_adder
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


module f_adder(ain,bin,cin,cout,sum);
    output cout,sum;
    input ain,bin,cin;
    wire ain,bin,cin,cout,sum;
    wire d,e,f;
    h_adder u0(ain,bin,d,e);
    h_adder u1(e,cin,f,sum);
    or2a u2(d,f,cout);
endmodule

