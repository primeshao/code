module ROM_1M(OE_n,addr,DOUT);
    parameter ON = 1'b0;
    
    input  OE_n;
    input  [9:0]addr;
    output  [31:0]DOUT;    
    
    wire [31:0]DOUT; 
    wire [31:0]d0,d1,d2,d3;
    wire [1:0]sel;
    wire [3:0]out8;
    wire [2:0]a;
    wire [7:0]h1,h2,h3,h4;
    wire [7:0]h11,h12,h13,h14;
    wire [7:0]h21,h22,h23,h24;
    wire [7:0]h31,h32,h33,h34;
    //片选
    decode3_8 u(.a(a),.y(out8));
    //第0组
    ROM_256_8 u0_0(.CS_n(out8[0]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h1));  
    ROM_256_8 u0_1(.CS_n(out8[0]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h2));
    ROM_256_8 u0_2(.CS_n(out8[0]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h3));
    ROM_256_8 u0_3(.CS_n(out8[0]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h4));
    //第1组
    ROM_256_8 u1_0(.CS_n(out8[1]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h11));  
    ROM_256_8 u1_1(.CS_n(out8[1]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h12));
    ROM_256_8 u1_2(.CS_n(out8[1]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h13));
    ROM_256_8 u1_3(.CS_n(out8[1]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h14));
    //第2组
    ROM_256_8 u2_0(.CS_n(out8[2]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h21));  
    ROM_256_8 u2_1(.CS_n(out8[2]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h22));
    ROM_256_8 u2_2(.CS_n(out8[2]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h23));
    ROM_256_8 u2_3(.CS_n(out8[2]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h24));
    //第3组
    ROM_256_8 u3_0(.CS_n(out8[3]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h31));  
    ROM_256_8 u3_1(.CS_n(out8[3]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h32));
    ROM_256_8 u3_2(.CS_n(out8[3]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h33));
    ROM_256_8 u3_3(.CS_n(out8[3]),.OE_n(OE_n),.Address(addr[7:0]),.DOUT(h34));
    
   
    assign sel=addr[9:8];//4选1，选择信号
    assign a={1'b0,addr[9:8]}; //3_8译码器输入信号
     
    //拼接各组输出数据
    assign d0={h4,h3,h2,h1};
    assign d1={h14,h13,h12,h11};
    assign d2={h24,h23,h22,h21};
    assign d3={h34,h33,h32,h31};
    //选择输出
    mux_4_1 mux4_1_u(d0,d1,d2,d3,sel,DOUT);
endmodule