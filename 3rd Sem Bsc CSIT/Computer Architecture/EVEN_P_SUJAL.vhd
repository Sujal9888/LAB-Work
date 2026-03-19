library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity EVEN_P_SUJAL is
    Port ( data : in STD_LOGIC_VECTOR(3 downto 0);
           parity_in : in STD_LOGIC;
           parity_gen : out STD_LOGIC;
           error : out STD_LOGIC);
end EVEN_P_SUJAL;

architecture Behavioral of EVEN_P_SUJAL is
begin
    -- Generator
    parity_gen <= data(0) XOR data(1) XOR data(2) XOR data(3);

    -- Checker (even parity)
    error <= data(0) XOR data(1) XOR data(2) XOR data(3) XOR parity_in;
end Behavioral;
