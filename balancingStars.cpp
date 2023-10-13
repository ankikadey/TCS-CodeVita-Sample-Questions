#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> balancingStars(string &str) {
    int balancedCount = 0;
    int openCount = 0;
    vector<int> result;

    for (char c : str) {
        if (c == '*' || c == '{' || c == '[' || c == '(') {
            if (c == '{' || c == '[' || c == '(') {
                openCount++;
            }
        } else {
            if (openCount == 0) {
                balancedCount++;
            } else {
                openCount--;
            }
        }
    }

    if (openCount != 0) {
        result.push_back(0);
        result.push_back(balancedCount);
    } else {
        result.push_back(1);
        result.push_back(balancedCount);
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Clearing the buffer

    while (T--) {
        string s;
        getline(cin, s);

        vector<int> result = balancingStars(s);
        if (result[0] == 1) {
            cout << "1 " << result[1] << endl;
        } else {
            cout << "0 " << result[1] << endl;
        }
    }

    return 0;
}
