library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity EN_DN_SUJAL is
    Port ( d_in   : in  STD_LOGIC_VECTOR(3 downto 0);  -- 4-to-2 Encoder input
           a_in   : in  STD_LOGIC_VECTOR(1 downto 0);  -- 2-to-4 Decoder input
           enc_out: out STD_LOGIC_VECTOR(1 downto 0);  -- Encoder output
           dec_out: out STD_LOGIC_VECTOR(3 downto 0)); -- Decoder output
end EN_DN_SUJAL;

architecture Behavioral of EN_DN_SUJAL is
begin
    -- 4-to-2 Encoder
    process(d_in)
    begin
        case d_in is
            when "0001" => enc_out <= "00";
            when "0010" => enc_out <= "01";
            when "0100" => enc_out <= "10";
            when "1000" => enc_out <= "11";
            when others => enc_out <= "00";
        end case;
    end process;

    -- 2-to-4 Decoder
    process(a_in)
    begin
        case a_in is
            when "00" => dec_out <= "0001";
            when "01" => dec_out <= "0010";
            when "10" => dec_out <= "0100";
            when "11" => dec_out <= "1000";
            when others => dec_out <= "0000";
        end case;
    end process;
end Behavioral;
