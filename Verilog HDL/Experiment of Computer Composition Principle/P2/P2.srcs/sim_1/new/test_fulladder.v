`timescale 1ns/100ps
module test_fulladder();
        reg my_a,my_b,my_cin;
        wire my_sum,my_cout;
        reg clk;
        fulladder u0(.a(my_a),.b(my_b),.cin(my_cin),.sout(my_sum),.cout(my_cout));
        always #10 clk=~clk;
        initial
        begin
                clk=1'b0;
                                my_a=1'b0;my_b=1'b0;my_cin=1'b0;
                #100;
                                my_a=1'b0;my_b=1'b0;my_cin=1'b1;
                #100;
                                my_a=1'b0;my_b=1'b1;my_cin=1'b0;
                #100;
                                my_a=1'b0;my_b=1'b1;my_cin=1'b1;
                #100;
                                my_a=1'b1;my_b=1'b0;my_cin=1'b0;
                #100;
                                my_a=1'b1;my_b=1'b0;my_cin=1'b1;
                #100;
                                my_a=1'b1;my_b=1'b1;my_cin=1'b0;
                #100;
                                my_a=1'b1;my_b=1'b1;my_cin=1'b1;
                #100;
        end
endmodule
