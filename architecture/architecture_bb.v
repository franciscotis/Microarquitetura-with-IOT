
module architecture (
	btn_export,
	clk_clk,
	db_readdata,
	en_writeresponsevalid_n,
	led_export,
	reset_reset_n,
	rs_writeresponsevalid_n,
	rs232_rxd,
	rs232_txd,
	rw_writeresponsevalid_n);	

	input	[3:0]	btn_export;
	input		clk_clk;
	output	[7:0]	db_readdata;
	output		en_writeresponsevalid_n;
	output	[3:0]	led_export;
	input		reset_reset_n;
	output		rs_writeresponsevalid_n;
	input		rs232_rxd;
	output		rs232_txd;
	output		rw_writeresponsevalid_n;
endmodule
