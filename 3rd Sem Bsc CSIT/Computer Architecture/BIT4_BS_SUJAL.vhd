library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BIT4_BS_SUJAL is
    port(
        A, B : in  std_logic_vector(3 downto 0);
        Diff : out std_logic_vector(3 downto 0);
        Borrow, Overflow: out std_logic
    );
end BIT4_BS_SUJAL;

architecture easy of BIT4_BS_SUJAL is
begin
    process(A, B)
        variable result_ext : signed(4 downto 0);
    begin
        -- Binary subtraction
         result_ext := resize(signed(A), 5) - resize(signed(B), 5);

        -- Assign outputs
        Diff     <= std_logic_vector(result_ext(3 downto 0));
        Borrow   <= result_ext(4);
        Overflow <= result_ext(4) xor result_ext(3);
    end process;
end easy;

