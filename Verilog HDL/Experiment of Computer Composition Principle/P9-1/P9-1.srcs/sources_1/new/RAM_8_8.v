module RAM_8_8(clk,CS_n,RD,WR,Address,DIN,DOUT);
parameter WORD_SIZE=8;
parameter WORD_NUMBER=8;
parameter Address_SIZE=3;
input clk;
input CS_n;
input RD,WR;
input [Address_SIZE-1:0] Address;
input [WORD_SIZE-1:0] DIN;
output [WORD_SIZE-1:0] DOUT;

reg [WORD_SIZE-1:0] DOUT;
reg [WORD_SIZE-1:0] RAM [0:WORD_NUMBER-1];

always @(posedge clk)
        if (WR==1'b1) 
begin
if ((CS_n==1'b0)&&(RD==1'b0))
RAM[Address]<=DIN;
end
        else if (RD==1'b1) 
begin
if ((CS_n==1'b0)&&(WR==1'b0))
                       DOUT<=RAM[Address];
end
endmodule
