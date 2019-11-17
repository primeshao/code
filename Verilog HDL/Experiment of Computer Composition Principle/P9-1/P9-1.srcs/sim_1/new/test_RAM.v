`timescale 1ns/100ps
module test_RAM(  );
parameter WORD_SIZE=8;
parameter Address_SIZE=3;
reg clk,CS_n,RD,WR;
reg [Address_SIZE-1:0] Address;
reg [WORD_SIZE-1:0] DIN;
wire [WORD_SIZE-1:0] DOUT;
RAM_8_8 u0(clk,CS_n,RD,WR,Address,DIN,DOUT);
    always #5 clk=~clk;
    initial
    begin
    clk=1'b0;
    CS_n=1'b1;RD=1'b0;WR=1'b0;//����SRAM
    #10;
    CS_n=1'b0;//ѡ��SRAM
    #10;
    Address=3'b000;//ѡ�е�ַΪ000�ĵ�Ԫ
    #10;
    DIN=8'b0000_0001;//����0000_0001
    #10;
    RD=1'b0;WR=1'b1;//д��
    #10;
    RD=1'b0;WR=1'b0;//д���
    
    #10;
    Address=3'b001;//ѡ�е�ַΪ001�ĵ�Ԫ
    #10;
    DIN=8'b0000_0001;//����0000_0001
    #10;
    RD=1'b0;WR=1'b1;//д��
    #10;
    RD=1'b0;WR=1'b0;//д���

        #10;
        Address=3'b000;//ѡ�е�ַΪ000�ĵ�Ԫ
        #10;        
        RD=1'b1;WR=1'b0;//����
        #10;
        RD=1'b0;WR=1'b0;//�����
        
        #10;
        Address=3'b001;//ѡ�е�ַΪ001�ĵ�Ԫ
        #10;        
        RD=1'b1;WR=1'b0;//����
        #10;
        RD=1'b0;WR=1'b0;//�����
         $stop;
         end
endmodule
