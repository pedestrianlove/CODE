`define UP 5'd2
`define DOWN 5'd4
`define LEFT 5'd3
`define RIGHT 5'd1

module adderSubtractor(a, b, cin, cout, sum) ;
    parameter n = 5;
    input [n - 1 : 0] a, b;
    input cin;
    output [n - 1 : 0] sum;
    output cout;

endmodule

module TBT(clk, rst, start, data, en, addr, fin, result);
    input clk, rst, start;
    input [4 : 0] data;
    output en, fin;
    output [4 : 0] addr, result;

endmodule