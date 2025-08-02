#include <iostream> // Required for input/output operations (like std::cout)

// Function to check if a number is prime using an optimized trial division method.
// This function strictly uses integer arithmetic and avoids floating-point operations,
// thus not requiring the <cmath> library.
bool isPrime(long long n) {
    // 0 and 1 are not prime numbers.
    if (n <= 1) {
        return false;
    }
    // 2 and 3 are prime numbers.
    if (n <= 3) {
        return true;
    }
    // If n is divisible by 2 or 3, it is not prime.
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // All prime numbers greater than 3 can be expressed in the form 6k ± 1.
    // This loop checks for divisibility by numbers of this form.
    // The condition 'i * i <= n' is an efficient way to check up to the square root
    // of 'n' using only integer multiplication, which is faster and avoids
    // floating-point inaccuracies compared to using sqrt() from <cmath>.
    for (long long i = 5; i * i <= n; i = i + 6) {
        // Check if n is divisible by i or (i + 2)
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; // If a divisor is found, n is not prime.
        }
    }
    return true; // If no divisors are found, n is prime.
}

int main() {
    // Inform the user about the program's purpose.
    std::cout << "Finding Prime Fibonacci Numbers:\n";
    std::cout << "--------------------------------\n";

    // Initialize the first two Fibonacci numbers.
    // These variables will be updated iteratively to generate the sequence.
    long long f_n_minus_2 = 0; // Represents F(0)
    long long f_n_minus_1 = 1; // Represents F(1)
    long long f_n;             // Will hold the current Fibonacci number F(n)

    // Output the first few Fibonacci numbers that are special cases or not prime.
    std::cout << "F_0 = 0 (Not Prime)\n";
    std::cout << "F_1 = 1 (Not Prime)\n";
    // F_2 is the sum of F_1 and F_0 (1 + 0 = 1).
    std::cout << "F_2 = 1 (Not Prime)\n";

    // Loop to generate Fibonacci numbers and check their primality.
    // The loop runs for 'i' from 3 up to 90. F(93) is approximately the largest
    // Fibonacci number that can be stored in a 'long long' (64-bit integer)
    // without overflowing. Going much higher will cause incorrect results.
    for (int i = 3; i <= 90; ++i) {
        // Calculate the next Fibonacci number.
        f_n = f_n_minus_1 + f_n_minus_2;

        // Basic overflow detection: if the sum is smaller than one of its addends,
        // it indicates that an overflow has occurred (the number wrapped around).
        if (f_n < f_n_minus_1) { // This check works if f_n_minus_1 is positive.
             std::cout << "--- Potential 'long long' overflow detected at F_" << i << ", stopping ---\n";
             break; // Exit the loop if overflow is suspected.
        }

        // Check if the current Fibonacci number is prime using our isPrime function.
        if (isPrime(f_n)) {
            std::cout << "F_" << i << " = " << f_n << " (Prime)\n";
        } else {
            // This section is commented out to only show prime numbers,
            // but you can uncomment it if you want to see all Fibonacci numbers
            // and their primality status.
            // std::cout << "F_" << i << " = " << f_n << " (Composite)\n";
        }

        // Update the previous two Fibonacci numbers for the next iteration.
        // The current F(n) becomes the next F(n-1).
        // The previous F(n-1) becomes the next F(n-2).
        f_n_minus_2 = f_n_minus_1;
        f_n_minus_1 = f_n;
    }

    // Concluding remarks about limitations.
    std::cout << "\n--------------------------------\n";
    std::cout << "Important Notes:\n";
    std::cout << "1. Fibonacci numbers grow extremely rapidly. The F_93 term is roughly the largest that can be precisely stored in a 'long long' integer type on most systems.\n";
    std::cout << "2. For computing and checking the primality of much larger Fibonacci numbers (e.g., hundreds or thousands of digits long), you would need specialized libraries for arbitrary-precision arithmetic (like GMP - GNU Multiple Precision Arithmetic Library in C++).\n";
    std::cout << "3. For primality testing of numbers with many digits, more advanced and efficient algorithms are used, such as the probabilistic Miller-Rabin test or the deterministic AKS primality test, as trial division becomes computationally too expensive.\n";

    return 0; // Indicate successful program execution.
}
