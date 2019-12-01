module ROM_8_8(CS_n,OE_n, Address, DOUT);
parameter WORD_SIZE=8;
parameter WORD_NUMBER=8;
parameter Address_SIZE=3;
input CS_n;
input OE_n;
input [Address_SIZE-1:0] Address;
output [WORD_SIZE-1:0] DOUT;

reg [WORD_SIZE-1:0] DOUT;
reg [WORD_SIZE-1:0] ROM [0:WORD_NUMBER-1];

always @(OE_n)
        if ((CS_n==1'b0)&&(OE_n==1'b0)) 
        DOUT<=ROM[Address];
        else
        DOUT<=8'bz;
endmodule
