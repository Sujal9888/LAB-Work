library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;  -- for arithmetic

entity ALU_SUJAL is
    Port ( 
        A, B    : in  STD_LOGIC_VECTOR(3 downto 0);
        sel     : in  STD_LOGIC_VECTOR(1 downto 0);  -- operation select
        result  : out STD_LOGIC_VECTOR(3 downto 0)
    );
end ALU_SUJAL;

architecture Behavioral of ALU_SUJAL is
begin
    process(A,B,sel)
        variable tempA, tempB, tempResult : unsigned(3 downto 0);
    begin
        tempA := unsigned(A);
        tempB := unsigned(B);
        case sel is
            when "00" => tempResult := tempA + tempB;   -- addition
            when "01" => tempResult := tempA - tempB;   -- subtraction
            when "10" => tempResult := tempA AND tempB; -- AND
            when "11" => tempResult := tempA OR tempB;  -- OR
            when others => tempResult := (others => '0');
        end case;
        result <= std_logic_vector(tempResult);  -- convert back to std_logic_vector
    end process;
end Behavioral;
