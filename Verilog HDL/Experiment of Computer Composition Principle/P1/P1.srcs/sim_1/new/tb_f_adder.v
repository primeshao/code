//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/09/13 16:25:36
// Design Name: 
// Module Name: tb_f_adder
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


`timescale 1ns/100ps
module tb_f_adder();
    reg a,b,cin;
    wire cout,sum;
    f_adder u0(a,b,cin,cout,sum);
    initial
begin
    #100;   a=1'b0;b=1'b0;cin=1'b0;
   #100;    a=1'b0;b=1'b1;cin=1'b0;
   #100;    a=1'b1;b=1'b0;cin=1'b0;
   #100;    a=1'b1;b=1'b1;cin=1'b0;
   #100;    a=1'b0;b=1'b0;cin=1'b1;
   #100;    a=1'b0;b=1'b1;cin=1'b1;
   #100;    a=1'b1;b=1'b0;cin=1'b1;
   #100;    a=1'b1;b=1'b1;cin=1'b1;
    end
endmodule

