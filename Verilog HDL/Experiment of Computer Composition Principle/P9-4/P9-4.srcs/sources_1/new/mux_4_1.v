module mux_4_1(d0,d1,d2,d3,sel,d 
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
          2'b00: d<=d0; 
          2'b01: d<=d1;
          2'b10: d<=d2; 
          2'b11: d<=d3; 
          default:d<=32'bz;
       endcase
endmodule