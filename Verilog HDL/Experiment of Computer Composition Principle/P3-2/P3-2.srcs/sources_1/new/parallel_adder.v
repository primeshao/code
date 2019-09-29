module parallel_adder(a,b,cin,s,cout);
    parameter N=4;//������λ��
    input wire [N-1:0]a;//����
    input wire [N-1:0]b;//������
    input wire cin;//��λ����
    output wire [N-1:0]s;//��
    output wire cout;//��λ���
    wire[N:0] g,p,c;
    assign c[0]=cin;
    assign p=a^b;
    assign g=a&b;
    assign c[1]=g[0]|(p[0]&c[0]);
    assign c[2]=g[1]|(p[1]&(g[0]|(p[0]&c[0])));
    assign c[3]=g[2]|(p[2]&(g[1]|(p[1]&(g[0]|(p[0]&c[0])))));
    assign c[4]=g[3]|(p[3]&(g[2]|(p[2]&(g[1]|(p[1]&(g[0]|(p[0]&c[0])))))));
    assign s=p^c[3:0];
    assign cout=c[4];
endmodule