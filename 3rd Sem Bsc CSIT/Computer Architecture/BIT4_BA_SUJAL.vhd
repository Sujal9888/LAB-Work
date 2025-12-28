library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BIT4_BA_SUJAL is
    port(
        A, B : in  std_logic_vector(3 downto 0);
        Sum : out std_logic_vector(3 downto 0);
        Cout, OVERFLOW : out std_logic
    );
end BIT4_BA_SUJAL;

architecture easy of BIT4_BA_SUJAL is
begin
    process(A, B)
        variable result_ext : signed(4 downto 0);
    begin
        -- Only addition
        result_ext := signed('0' & A) + signed('0' & B);

        -- Assign outputs
        Sum      <= std_logic_vector(result_ext(3 downto 0));
        Cout     <= result_ext(4);
        OVERFLOW <= result_ext(4) xor result_ext(3);
    end process;
end easy;

