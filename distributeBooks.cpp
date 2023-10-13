/* For enhancing the book reading, school distributed story books to students as part of the Children’s day celebrations.
To increase the reading habit, the class teacher decided to exchange the books every weeks so that everyone will have a different book to read. She wants to know how many possible exchanges are possible.

If they have 4 books and students, the possible exchanges are 9. Bi is the book of i-th student and after the exchange he should get a different book, other than Bi.

B1 B2 B3 B4 – first state, before exchange of the books
B2 B1 B4 B3
B2 B3 B4 B1
B2 B4 B1 B3
B3 B1 B4 B2
B3 B4 B1 B2
B3 B4 B2 B1
B4 B1 B2 B3
B4 B3 B1 B2
B4 B3 B2 B1



Find the number of possible exchanges, if the books are exchanged so that every student will receive a different book.

Constraints

1<= N <= 1000000

Input Format

Input contains one line with N, indicates the number of books and number of students.

Output

Output the answer modulo 1000000007.

Test Case

Example 1

Input

4

Output

9

*/

/*The formula for !n is given by the following recursive formula:

!n = (n - 1)(!(n - 1) + !(n - 2))

To find the number of possible exchanges, we can use this formula,
and then apply modulo 1000000007 to the result*/

// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1000000007;

// int distributeBooks(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n == 1)
//     {
//         return 0;
//     }
//     return (int)(((long long)(n - 1) * (distributeBooks(n - 1) + distributeBooks(n - 2))) % MOD);
// }

// #include <iostream>
// using namespace std;

// const int MOD = 1000000007;

// int distributeBooks(int n)
// {
//     if (n == 0) {
//         return 1;
//     }
//     if (n == 1) {
//         return 0;
//     }
//     return (int)(((long long)(n - 1) * (distributeBooks(n - 1) + distributeBooks(n - 2))) % MOD);
// }

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int distributeBooks(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = (int)(((long long)(i - 1) * (dp[i - 1] + dp[i - 2])) % MOD);
    }

    return dp[n]; //more optimized approach
}


int main() {
    int T;
    cin >> T;

    vector<int> results;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // Calculation
        int result = distributeBooks(N);
        results.push_back(result);
    }

    // Output
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}