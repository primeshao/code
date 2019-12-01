`timescale 1ns/10ps
module test_ROM( );
    parameter WORD_SIZE=32;
  
    parameter Address_SIZE=10;
    reg OE_n;
    reg [Address_SIZE-1:0] Address;
    wire [WORD_SIZE-1:0]DOUT;
    
    ROM_1M u0(OE_n,Address,DOUT);

   initial 
   begin
     OE_n=1'b1;//禁止ROM
     
     {u0.u0_3.ROM[0],u0.u0_2.ROM[0],u0.u0_1.ROM[0],u0.u0_0.ROM[0]}=32'h00230010;//第0组首地址10'b00_0000_0000输入数据32'h00230010
     {u0.u1_3.ROM[0],u0.u1_2.ROM[0],u0.u1_1.ROM[0],u0.u1_0.ROM[0]}=32'h00230011;//第1组首地址10'b01_0000_0000输入数据32'h00230011
     {u0.u2_3.ROM[0],u0.u2_2.ROM[0],u0.u2_1.ROM[0],u0.u2_0.ROM[0]}=32'h00230012;//第2组首地址10'b10_0000_0000输入数据32'h00230012
     {u0.u3_3.ROM[0],u0.u3_2.ROM[0],u0.u3_1.ROM[0],u0.u3_0.ROM[0]}=32'h00230013;//第3组首地址10'b11_0000_0000输入数据32'h00230013
     
      #10;
      Address=10'b00_0000_0000;
      #10;
      OE_n=1'b0;//读ROM
      #100;
      OE_n=1'b1;//禁止ROM
      Address=10'b01_0000_0000;
      #10;
      OE_n=1'b0;//读ROM
      #100;
      OE_n=1'b1;//禁止ROM
      Address=10'b10_0000_0000;
      #10;
      OE_n=1'b0;//读ROM
      #100;
      OE_n=1'b1;//禁止ROM
      Address=10'b11_0000_0000;
      #10;
      OE_n=1'b0;//读ROM
  end
endmodule
