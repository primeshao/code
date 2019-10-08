`timescale 1ns/100ps
module test_adder();
    reg clk_1Hz;
    reg [3:0]a,b;
    reg cin;
    wire [3:0]s;
    wire cout;
    parallel_adder u0(a,b,cin,s,cout);
    always #10 clk_1Hz = ~clk_1Hz ;
    initial
    begin
    clk_1Hz=0;
        #20;
        a=4'b0000;b=4'b0000;cin=1'b0;
        #20;
        a=4'b0000;b=4'b0001;cin=1'b0;
        #20;
        b=4'b1111;cin=1'b1;
        #20;
        a=4'b1101;b=4'b0100;
        #20;
        a=4'b0000;b=4'b1001;cin=1'b0;
        #20;
        a=4'b1000;b=4'b0110;
    end
endmodule
