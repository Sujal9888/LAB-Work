library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity OVERFLOW_SUJAL is
    port(
        A, B : in  std_logic_vector(3 downto 0);
        OVERFLOW : out std_logic
    );
end entity OVERFLOW_SUJAL;

architecture behavioral of OVERFLOW_SUJAL is

begin
    process(A, B)
        variable sum : std_logic_vector(4 downto 0);
    begin
        
        sum :=('0' & A) + ('0' & B);

       if sum(4)='1' then 
		OVERFLOW<='1';
	else 
		OVERFLOW<='0';
	end if;
	end process;
end behavioral ;

