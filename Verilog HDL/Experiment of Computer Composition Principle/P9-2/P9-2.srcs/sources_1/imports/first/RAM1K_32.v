module RAM1K_32(clk,DMWr,addr,DIN,DOUT);
    parameter ON = 1'b0;
    input clk;    
    input  DMWr;
    input  [11:2]addr;
    input  [31:0]DIN;
    output [31:0]DOUT;    
    wire RD,WR;
    wire [7:0]RAM1K_32_CS_n;    
    wire [7:0]h01,h02,h03,h04;
    wire [7:0]h11,h12,h13,h14;
    wire [7:0]h21,h22,h23,h24;
    wire [7:0]h31,h32,h33,h34;
    wire [31:0]d0,d1,d2,d3;
    wire [1:0]sel;
    wire [2:0]a;
    //获得读写信号
    assign RD=!DMWr;
    assign WR=DMWr; 
    //获得译码器选择信号  
    assign sel=addr[11:10]; 
    //获得多路器选择信号
    assign a={1'b0,sel};
    //3-8译码器产生片选信号RAM1K_32_CS_n    
    decode3_8 u(.a(a),.y(RAM1K_32_CS_n));
    //第一组
    RAM256_8 u0_0(.clk(clk),.CS_n(RAM1K_32_CS_n[0]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[7:0]),.DOUT(h01));  
    RAM256_8 u0_1(.clk(clk),.CS_n(RAM1K_32_CS_n[0]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[15:8]),.DOUT(h02));
    RAM256_8 u0_2(.clk(clk),.CS_n(RAM1K_32_CS_n[0]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[23:16]),.DOUT(h03));
    RAM256_8 u0_3(.clk(clk),.CS_n(RAM1K_32_CS_n[0]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[31:24]),.DOUT(h04));
    //第二组
    RAM256_8 u1_0(.clk(clk),.CS_n(RAM1K_32_CS_n[1]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[7:0]),.DOUT(h11));  
    RAM256_8 u1_1(.clk(clk),.CS_n(RAM1K_32_CS_n[1]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[15:8]),.DOUT(h12));
    RAM256_8 u1_2(.clk(clk),.CS_n(RAM1K_32_CS_n[1]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[23:16]),.DOUT(h13));
    RAM256_8 u1_3(.clk(clk),.CS_n(RAM1K_32_CS_n[1]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[31:24]),.DOUT(h14));
    //第三组
    RAM256_8 u2_0(.clk(clk),.CS_n(RAM1K_32_CS_n[2]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[7:0]),.DOUT(h21));  
    RAM256_8 u2_1(.clk(clk),.CS_n(RAM1K_32_CS_n[2]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[15:8]),.DOUT(h22));
    RAM256_8 u2_2(.clk(clk),.CS_n(RAM1K_32_CS_n[2]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[23:16]),.DOUT(h23));
    RAM256_8 u2_3(.clk(clk),.CS_n(RAM1K_32_CS_n[2]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[31:24]),.DOUT(h24));
    //第四组    
    RAM256_8 u3_0(.clk(clk),.CS_n(RAM1K_32_CS_n[3]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[7:0]),.DOUT(h31));  
    RAM256_8 u3_1(.clk(clk),.CS_n(RAM1K_32_CS_n[3]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[15:8]),.DOUT(h32));
    RAM256_8 u3_2(.clk(clk),.CS_n(RAM1K_32_CS_n[3]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[23:16]),.DOUT(h33));
    RAM256_8 u3_3(.clk(clk),.CS_n(RAM1K_32_CS_n[3]),.RD(RD),.WR(WR),.Address(addr[9:2]),.DIN(DIN[31:24]),.DOUT(h34));       
    //拼接各组输出数据
    assign d0={h04,h03,h02,h01};
    assign d1={h14,h13,h12,h11};
    assign d2={h24,h23,h22,h21};
    assign d3={h34,h33,h32,h31};
    //选择输出
    mux4_1 mux4_1_u(d0,d1,d2,d3,sel,DOUT);
endmodule