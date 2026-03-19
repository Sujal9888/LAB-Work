library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CU_SUJAL is
    Port ( clk       : in  STD_LOGIC;
           reset     : in  STD_LOGIC;
           state_out : out STD_LOGIC_VECTOR(1 downto 0));
end CU_SUJAL;

architecture Behavioral of CU_SUJAL is
    type state_type is (S0, S1, S2, S3);
    signal state : state_type;
begin
    process(clk, reset)
    begin
        if reset='1' then
            state <= S0;
        elsif rising_edge(clk) then
            case state is
                when S0 => state <= S1;
                when S1 => state <= S2;
                when S2 => state <= S3;
                when S3 => state <= S0;
            end case;
        end if;
    end process;

    -- output state code
    state_out <= "00" when state=S0 else
                 "01" when state=S1 else
                 "10" when state=S2 else
                 "11";
end Behavioral;
