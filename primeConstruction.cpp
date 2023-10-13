#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(long long num) {
    if (num <= 1) {
        return false;
    }
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

long long compute_smallest_prime(vector<long long> input_list) {
    long long q = *min_element(input_list.begin(), input_list.end());
    for (long long p = q + 1;; p++) {
        bool flag = true;
        for (auto num : input_list) {
            if (num != q && p % num != q) {
                flag = false;
                break;
            }
        }
        if (flag && is_prime(p)) {
            return p;
        }
    }
    return -1;
}

int main() {
    vector<long long> input_list;
    long long input;
    while (cin >> input) {
        input_list.push_back(input);
    }
    long long output = compute_smallest_prime(input_list);
    if (output == -1) {
        cout << "None" << endl;
    } else {
        cout << output << endl;
    }
    return 0;
}
