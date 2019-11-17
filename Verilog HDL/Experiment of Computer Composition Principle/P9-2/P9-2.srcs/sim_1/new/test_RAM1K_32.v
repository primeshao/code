`timescale 1ns/100ps
module test_RAM1K_32();
//��ʼ������
reg clk,DMWr;
    reg [11:2]addr;
    reg [31:0]DIN;
    wire [31:0]DOUT;
    //���� RAM1K_32ģ��
    RAM1K_32 u0(clk,DMWr,addr,DIN,DOUT);
    //����ʱ���ź�
    always #50 clk=~clk;
    initial
    begin
    clk=1'b0;
    
    //д����
    #100;
    DMWr=1;
    DIN = 32'b01011101000101110101110010111001;
    addr=10'b1001001000;
    
    //������
    #100;
    DMWr=0;
    addr=10'b1001001000;
    end
endmodule

