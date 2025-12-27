library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BIT4BAS_SUJAL is
    port(
        M : in  std_logic;                      
        A, B : in  std_logic_vector(3 downto 0);
        Sum : out std_logic_vector(3 downto 0);
        Cout, OVERFLOW : out std_logic
    );
end BIT4BAS_SUJAL;

architecture easy of BIT4BAS_SUJAL is
begin
    process(A, B, M)
        variable result_ext : signed(4 downto 0);
    begin
        if M = '0' then
            result_ext := signed('0' & A) + signed('0' & B);
        else
            result_ext := signed('0' & A) - signed('0' & B);
        end if;

        Sum      <= std_logic_vector(result_ext(3 downto 0));
        Cout     <= result_ext(4);
        OVERFLOW <= result_ext(4) xor result_ext(3);
    end process;
end easy; 
