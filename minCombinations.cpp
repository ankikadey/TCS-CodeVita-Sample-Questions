/*Alexander The great, while roaming the stretch of Turkey, came across a wise man. He asked the wise man, “Who is the greatest conqueror of all?”. The wise man replied, “A person with great strength and intelligence. Whosoever can solve my puzzle will go on to become the greatest!”.

The puzzle is as follows : (Minimum Combinations)

Given two integers ‘n1’ and ‘n2’, select two integers ‘a’ and ‘b’, such as to solve the equation (n1 * a + n2 * b = x). But there is a catch, ‘x’ is the smallest positive integer which satisfies the equation. Can you help Alexander become the greatest?

Constraints

1 <= T <= 1000
-10^7 <= a, b <= 10^7
0 <= n1, n2 <= 10^7

Input Format

The first line contains the number of Test cases T.
Next T lines contains two space-separated integers, n1 and n2.

Output

Print the value of x.

Test Case

Example 1

Input

1
34818 45632

Output

2

Explanation

Given n1 = 34818 and n2 = 45632, if we choose a = 3553 and b = -2711, we get

=> n1 * a + n2 * b = x
=> 34818 * 3553 + 45632 * (-2711)
=> 2

Note: No other value of a and b, within the range, will give smaller value than 2.
*/
#include <iostream>
#include <cmath>
using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int minCombinations(int n1, int n2) {
    long long a, b;
    long long gcd = extendedGCD(n1, n2, a, b);

    // Making sure x is positive and minimal
    if (a < 0) {
        long long factor = ceil((-1.0 * a) / n2);
        a += factor * n2;
        b -= factor * n1;
    }

    if (b < 0) {
        long long factor = ceil((-1.0 * b) / n1);
        a -= factor * n2;
        b += factor * n1;
    }

    // Calculating x
    long long x = n1 * a + n2 * b;
    return x;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n1, n2;
        cin >> n1 >> n2;

        // Calling minCombinations function
        int result = minCombinations(n1, n2);
        cout << result << endl;
    }

    return 0;
}