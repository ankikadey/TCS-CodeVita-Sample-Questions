/*Consider a Jug of capacity L liters. Given N cups of different capacities Ci (in liters), fill the Jug with the help of cups, according the specification.

The specification according to which the cups may be used to fill the Jug is as below

Cups can be used integral number of times i.e., zero or more times, but never partially i.e., a cup of 1L can be used 0, 1, 2 etc. times, but never 0.5, 1.5, 2.5 .. times
The Jug must not overflow because of cup filling the Jug
The number of distinct cups (i.e., different cup sizes) used to fill the Jug must be maximized
The summation of number of times all cups are used must be minimized.
Consider point 3 to be more important than point 4 when meeting the optimisation goals.
For better understanding of how cups can be used to fill the Jug, go through the Examples section. Both examples clearly explain, when there are multiple ways to achieve the objective, what is the correct answer and why.

Constraints
0 < N < 10

0 < L <= 100

0 < Ci < L

Input
First line contains an integer N denoting the number of cups available.

Second line contains N space separated integers denoting the capacity of the cups.

Third line contains an integer L which denotes the capacity of Jug in liters.

Output
Output consists of two lines.

First line must comprise of N or less space delimited integers, in ascending order of cup size, for the cups used to fill the Jug

Second line must comprise of equal number of space delimited integers which denote the frequency i.e. the number of times the corresponding cup in first line is used to fill the Jug

Time Limit (secs)
1

Examples
Input

4

3 7 10 11

88

Output

3 7 10 11

1 2 6 1

Explanation:

The first and second lines indicate that you are provided with 4 cups of capacities - 3 liters, 7 liters, 10 liters and 11 liters. The third line indicates that the capacity of the Jug is 88 liters.

One possible solution for filling the Jug is

7 10 11

5 2 3

i.e., one can use 7L cup for 5 times to get 35L. Next one can use the 10L cup twice. After that the Jug will contain 55L. Finally, one can use 11L cup thrice. Thus, the Jug will be filled. However, this solution uses cups of only 3 different capacities when 4 different capacities are available. Hence the Jug is perhaps not filled according to the specification. Let's see if we can achieve our objective by using all 4 cup sizes.

We can use all the available cups if we use them as follows

3 7 10 11

1 2 6 1

Hence, this is our final solution which adheres to the specification.

Example 2

Input

3

2 5 10

50

Output

2 5 10

5 2 3

Explanation:

The first and second lines indicate that you are provided with 3 cups of capacities - 2 liters, 5 liters, 10 liters. The third line indicates that the capacity of the Jug is 50 liters.

Here one can easily fill the Jug by using the 10L cup 5 times. However, this does not obey the specifications. According to the specifications, one must use all available cups of capacity 2L, 5L and 10L. If there are multiple ways in which the Jug can be filled by using maximum number of distinct sized cups, then as per specifications one needs to minimize the summation of number of times cups are used.

Consider the following solutions

Solution 1

2 5 10

15 2 1

Solution 2

2 5 10

5 2 3

Both solutions use all available cups. However, sum of frequencies in Solution 1 is 18 (15 + 2 + 1), 
whereas sum of frequencies in Solution 2 is 10 (5 + 2 + 3). 
Solution 2 minimizes the summation of number of times any cup in used. 
This is also a requirement as per the specification. Hence Solution 2 is the correct answer.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fillJug(int N, vector<int> cups, int L) {
    sort(cups.begin(), cups.end());
    vector<int> usedCups(N, 0);
    int remaining = L;
    int distinctCups = 0;

    for (int i = 0; i < N; i++) {
        if (cups[i] <= remaining) {
            usedCups[i] = remaining / cups[i];
            remaining %= cups[i];
            if (usedCups[i] > 0) {
                distinctCups++;
            }
        }
    }

    vector<int> finalUsedCups(distinctCups);
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (usedCups[i] > 0) {
            finalUsedCups[j] = usedCups[i];
            j++;
        }
    }

    return finalUsedCups;
}

int main() {
    int N;
    cin >> N;
    vector<int> cups(N);
    for (int i = 0; i < N; i++) {
        cin >> cups[i];
    }
    int L;
    cin >> L;

    vector<int> usedCups = fillJug(N, cups, L);

    for (int i = 0; i < N; i++) {
        cout << cups[i];
        if (i != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < usedCups.size(); i++) {
        cout << usedCups[i];
        if (i != usedCups.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
