	component architecture is
		port (
			btn_export              : in  std_logic_vector(3 downto 0) := (others => 'X'); -- export
			clk_clk                 : in  std_logic                    := 'X';             -- clk
			db_readdata             : out std_logic_vector(7 downto 0);                    -- readdata
			en_writeresponsevalid_n : out std_logic;                                       -- writeresponsevalid_n
			led_export              : out std_logic_vector(3 downto 0);                    -- export
			reset_reset_n           : in  std_logic                    := 'X';             -- reset_n
			rs_writeresponsevalid_n : out std_logic;                                       -- writeresponsevalid_n
			rs232_rxd               : in  std_logic                    := 'X';             -- rxd
			rs232_txd               : out std_logic;                                       -- txd
			rw_writeresponsevalid_n : out std_logic                                        -- writeresponsevalid_n
		);
	end component architecture;

	u0 : component architecture
		port map (
			btn_export              => CONNECTED_TO_btn_export,              --   btn.export
			clk_clk                 => CONNECTED_TO_clk_clk,                 --   clk.clk
			db_readdata             => CONNECTED_TO_db_readdata,             --    db.readdata
			en_writeresponsevalid_n => CONNECTED_TO_en_writeresponsevalid_n, --    en.writeresponsevalid_n
			led_export              => CONNECTED_TO_led_export,              --   led.export
			reset_reset_n           => CONNECTED_TO_reset_reset_n,           -- reset.reset_n
			rs_writeresponsevalid_n => CONNECTED_TO_rs_writeresponsevalid_n, --    rs.writeresponsevalid_n
			rs232_rxd               => CONNECTED_TO_rs232_rxd,               -- rs232.rxd
			rs232_txd               => CONNECTED_TO_rs232_txd,               --      .txd
			rw_writeresponsevalid_n => CONNECTED_TO_rw_writeresponsevalid_n  --    rw.writeresponsevalid_n
		);

