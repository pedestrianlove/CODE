`define IDLE 1'd0
`define SUM 1'd1
module ADD(clk , rst , start , data , en , addr , fin , result);

    parameter datawidth = 3;
    parameter memwidth = 3;

    input clk , rst , start;
    input [datawidth - 1 : 0] data;
    output en , fin;
    output [memwidth - 1 : 0] addr;
    output [datawidth - 1 : 0] result;

    reg state , next_state;
    reg [memwidth - 1 : 0] num , next_num;
    reg [memwidth - 1 : 0] leng , next_leng;
    reg [datawidth - 1 : 0] ans , next_ans;

    always@(posedge rst or posedge clk)begin
        if(rst == 1'b1)begin
            state <= `IDLE;
            num <= 3'd7;
            leng <= 3'd0;
            ans <= 3'd0;
        end
        else begin
            state <= next_state;
            num <= next_num;
            leng <= next_leng;
            ans <= next_ans;
        end
    end

    always@(*)begin
        next_num = num + 3'd1;
        next_leng = leng;
        next_ans = ans;
        next_state = state;
        case(state)
            `IDLE:begin
                next_state = (start == 1'b1)? `SUM : `IDLE;
                next_num = (start == 1'b1)? 3'd0 : 3'd7;
                next_leng = (start == 1'b1)? data : leng;
            end
            `SUM:begin
                next_ans = (num < leng)? ans + data : ans;
            end
        endcase
    end

    assign en = 1'b1;
    assign addr = num;
    assign fin = (start == 1'b1 && num == leng)? 1'b1 : 1'b0;
    assign result = (fin == 1'b1)? ans : 3'd0;

endmodule