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
