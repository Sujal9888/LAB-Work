library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity PARITY_SUJAL is
    Port (
        data       : in  STD_LOGIC_VECTOR(3 downto 0);
        parity_in  : in  STD_LOGIC;
        mode       : in  STD_LOGIC;  -- 0 = Even, 1 = Odd
        parity_gen : out STD_LOGIC;
        error      : out STD_LOGIC
    );
end PARITY_SUJAL;

architecture Behavioral of PARITY_SUJAL is
    signal temp        : STD_LOGIC;
    signal parity_calc : STD_LOGIC;
begin

    -- XOR of all data bits
    temp <= data(0) XOR data(1) XOR data(2) XOR data(3);

    -- Select Even or Odd parity
    parity_calc <= temp        when mode = '0' else
                   NOT temp;   -- Odd parity

    -- Output parity bit
    parity_gen <= parity_calc;

    -- Error detection
    error <= parity_calc XOR parity_in;

end Behavioral;
