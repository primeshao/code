`timescale 10ns/120ps
module test_SignManitudeMultiplier();
        reg clk;
        reg start;
        parameter N=31;
        reg [0:N] x,y;
        wire [0:N*2] z;
        wire finished;
        SignMagnitudeMultiplier u0(clk,start,x,y,z,finished);
        always #10 clk=~clk;
        initial 
        begin
            clk=0;
            start=1'b0; 
            x=32'h00_00_00_04;
            y=32'h00_00_00_02;
            #40;
            start=1'b1;
            #700;
            start=1'b0;
            x=32'h00_00_00_10;
            y=32'h00_00_00_10;
             #40
             start=1'b1;
             #700;
            start=1'b0; 
            x=32'h00_00_00_02;
            y=32'h00_00_00_04;
            #40;
            start=1'b1;
            $stop;  
         end
endmodule
