module test_BoothMultiplier();
    reg clk;
    reg start;
    parameter N=4;
    reg [0:N] x,y;
    wire  [0:N*2] z;
    wire finished;
    BoothMultiplier u0(clk,start,x,y,z,finished);
    always #10 clk=~clk;
    initial 
    begin
        clk=0;
        x=5'b01011;
        y=5'b10111;
        start=1'b0;
        #40;
       start=1'b1;
       #200;
      start=1'b0;
       x=5'b10111;
       y=5'b10110;
       #40;
       start=1'b1;
       #200;
     start=1'b0;
       x=5'b10001;
       y=5'b11100;
       $stop;
    end
endmodule
