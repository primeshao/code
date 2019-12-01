module test_ROM( );
parameter WORD_SIZE=8;
parameter WORD_NUMBER=8;
parameter Address_SIZE=3;
reg CS_n,OE_n;
reg [Address_SIZE-1:0] Address;
wire [WORD_SIZE-1:0] DOUT;
ROM_8_8 u0(CS_n,OE_n,Address,DOUT);
    initial
    begin
    CS_n=1'b1;
    OE_n=1'b1;//½ûÖ¹ROM
    #10;
    //×°ÈëROMÄÚÈÝ
    u0.ROM[0]=8'h0c;
    u0.ROM[1]=8'h34;
    u0.ROM[2]=8'h56;
    u0.ROM[3]=8'h21;
    u0.ROM[4]=8'h23;
    u0.ROM[5]=8'h00;
    u0.ROM[6]=8'h04;
    u0.ROM[7]=8'h00;
    
    #10;
    Address=3'b111;
    CS_n=1'b0;
    OE_n=1'b0;//¶ÁROM
    
    #10
    CS_n=1'b1;
    OE_n=1'b1;//½ûÖ¹ROM
    
    #10;
    Address=3'b001;
    CS_n=1'b0;
    OE_n=1'b0;//¶ÁROM

    #10;
    $finish;
end
endmodule
