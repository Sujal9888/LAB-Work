LIBRARY ieee;
USE ieee.STD_LOGIC_1164.ALL;

ENTITY BA_BS_SUJAL IS
    PORT(
        A    : IN  STD_LOGIC;
        B    : IN  STD_LOGIC;
        M    : IN  STD_LOGIC;   -- Mode: 0 = Add, 1 = Subtract
        Sum  : OUT STD_LOGIC;
        Cout : OUT STD_LOGIC
    );
END BA_BS_SUJAL;

ARCHITECTURE Behavioral OF BA_BS_SUJAL IS
BEGIN
    PROCESS(A, B, M)
    VARIABLE Bx : STD_LOGIC;
    BEGIN
        -- XOR B with M to select Add or Subtract
        Bx := B xor M;

        -- Sum
        Sum <= A xor Bx xor M;

        -- Carry/Borrow
        Cout <= (A and Bx) or (A and M) or (Bx and M);
    END PROCESS;
END Behavioral;

