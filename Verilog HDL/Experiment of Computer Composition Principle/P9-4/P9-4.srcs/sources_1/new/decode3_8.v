module decode3_8(a,y);
input [2:0]a;
output reg [7:0]y;
always @(a)
    case (a)
        3'b000:y<=8'b1111_1110;
        3'b001:y<=8'b1111_1101;
        3'b010:y<=8'b1111_1011;
        3'b011:y<=8'b1111_0111;
        default:y<=8'bz;
    endcase
endmodule
