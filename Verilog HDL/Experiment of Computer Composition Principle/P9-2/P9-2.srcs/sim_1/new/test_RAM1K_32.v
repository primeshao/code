`timescale 1ns/100ps
module test_RAM1K_32();
//初始化参数
reg clk,DMWr;
    reg [11:2]addr;
    reg [31:0]DIN;
    wire [31:0]DOUT;
    //调用 RAM1K_32模块
    RAM1K_32 u0(clk,DMWr,addr,DIN,DOUT);
    //产生时钟信号
    always #50 clk=~clk;
    initial
    begin
    clk=1'b0;
    
    //写数据
    #100;
    DMWr=1;
    DIN = 32'b01011101000101110101110010111001;
    addr=10'b1001001000;
    
    //读数据
    #100;
    DMWr=0;
    addr=10'b1001001000;
    end
endmodule

