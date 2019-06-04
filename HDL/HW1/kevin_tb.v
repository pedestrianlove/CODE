module kevin_tb;
        parameter delay_sec=5;

        wire out_G,out_D,out_B;
        reg [3:0]in;
        integer i;

        initial begin
            //Give initial value.
            in=0;
            for(i=0;i<16;i=i+1)
	    	begin
                	
			#delay_sec
                	$display("time=%4d,in=%b,out_G=%b,out_D=%b,out_B=%b",$time,in,out_G,out_D,out_B);

                	if((out_G|out_D|out_B)===1'bx||
                	((in==1||in==5||in==6||in==7||in==9||in==10||in==12||in==14)&&(out_G&out_D&out_B)==0)||
                	((in!=1&&in!=5&&in!=6&&in!=7&&in!=9&&in!=10&&in!=12&&in!=14)&&(out_G|out_D|out_B)==1))
                    	begin
                        	$display("You got wrong answer!!");
                    	end
                	in=in+1;
            	end
            $display("Congratulations!!");
            $finish;
        end

        kevin_G kg
        (
            .in(in),
            .out(out_G)
        );
        kevin_D kd
        (
            .in(in),
            .out(out_D)
        );
        kevin_B kb
        (
            .in(in),
            .out(out_B)
        );

endmodule
