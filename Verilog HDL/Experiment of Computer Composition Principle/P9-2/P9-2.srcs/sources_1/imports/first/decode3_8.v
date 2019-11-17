`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/04/05 20:39:52
// Design Name: 
// Module Name: decode3_8
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


module decode3_8(a,y);
input [2:0]a;
output reg [7:0]y;
always @(a)
    case (a)
        3'b000:y<=8'b1111_1110;
        3'b001:y<=8'b1111_1101;
        3'b010:y<=8'b1111_1011;
        3'b011:y<=8'b1111_0111;
        3'b100:y<=8'b1110_1111;
        3'b101:y<=8'b1101_1111;
        3'b110:y<=8'b1011_1111;
        3'b111:y<=8'b0111_1111;
        default:y<=8'bz;
    endcase
endmodule

