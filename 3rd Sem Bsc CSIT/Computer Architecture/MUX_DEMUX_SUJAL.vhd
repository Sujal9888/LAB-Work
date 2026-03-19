 library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MUX_DEMUX_SUJAL is
    Port ( d      : in  STD_LOGIC_VECTOR(3 downto 0);  -- MUX input
           s      : in  STD_LOGIC_VECTOR(1 downto 0);  -- select line
           x      : in  STD_LOGIC;                     -- DEMUX input
           mux_out: out STD_LOGIC;                     -- MUX output
           demux_out: out STD_LOGIC_VECTOR(3 downto 0) -- DEMUX output
          );
end MUX_DEMUX_SUJAL;

architecture Behavioral of MUX_DEMUX_SUJAL is
begin
    -- 4:1 MUX
    mux_out <= d(0) when s="00" else
               d(1) when s="01" else
               d(2) when s="10" else
               d(3);

    -- 1:4 DEMUX
    process(x,s)
    begin
        demux_out <= "0000";
        case s is
            when "00" => demux_out(0) <= x;
            when "01" => demux_out(1) <= x;
            when "10" => demux_out(2) <= x;
            when "11" => demux_out(3) <= x;
            when others => null;
        end case;
    end process;
end Behavioral;
