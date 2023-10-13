#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getCellNumber(int row, int col) {
    return (row - 1) * 12 + col;
}

bool isDevilActive(char devilType, int second, int angelRow, int angelCol) {
    if (devilType == 'X') {
        return second == angelCol;
    } else if (devilType == 'O') {
        return (second % 4) == 1 || (second % 4) == 3;
    } else if (devilType == 'Z') {
        int cycle = second % 12;
        if (cycle <= 3) {
            return (angelRow + cycle == 12 && angelCol == 12) || (angelRow + cycle == 2 && angelCol == 1);
        } else if (cycle <= 6) {
            return (angelRow == 12 && angelCol - (cycle - 3) == 12) || (angelRow == 1 && angelCol - (cycle - 3) == 1);
        } else if (cycle <= 9) {
            return (angelRow - (cycle - 6) == 12 && angelCol == 1) || (angelRow - (cycle - 6) == 1 && angelCol == 12);
        } else {
            return (angelRow == 12 && angelCol + (cycle - 9) == 1) || (angelRow == 1 && angelCol + (cycle - 9) == 12);
        }
    }
    return false;
}

string solveGame(const string &angelStart, const string &devilTypes, const vector<string> &devilStarts) {
    int angelRow = angelStart[0] - 'A' + 1;
    int angelCol = angelStart[1] - '0';
    int second = 1;

    while (true) {
        if (angelRow == 1 || angelRow == 12 || angelCol == 1 || angelCol == 12) {
            return "SS"; // Angel successfully crossed the board
        }

        for (int i = 0; i < devilTypes.size(); i++) {
            char devilType = devilTypes[i];
            int devilRow = devilStarts[i][0] - 'A' + 1;
            int devilCol = devilStarts[i][1] - '0';

            if (isDevilActive(devilType, second, angelRow, angelCol)) {
                if (devilType == 'X' && devilCol == angelCol) {
                    return to_string(getCellNumber(angelRow, angelCol));
                } else if (devilType == 'O') {
                    if ((second % 4) == 1 || (second % 4) == 3) {
                        if (devilRow == angelRow && devilCol == angelCol) {
                            return to_string(getCellNumber(angelRow, angelCol));
                        }
                    }
                } else if (devilType == 'Z') {
                    if (angelRow == devilRow && angelCol == devilCol) {
                        return to_string(getCellNumber(angelRow, angelCol));
                    }
                }
            }
        }

        if (angelStart[0] == 'A') {
            angelCol++;
        } else if (angelStart[0] == 'L') {
            angelCol--;
        } else if (angelStart.compare("12") == 0) {
            angelRow--;
        } else if (angelStart[1] == '1') {
            angelRow++;
        }

        second++;
    }
}

int main() {
    string angelStart, devilTypes;
    vector<string> devilStarts;
    cin >> angelStart;
    cin.ignore(); // Read the newline character
    cin >> devilTypes;
    cin.ignore(); // Read the newline character

    string temp;
    while (getline(cin, temp, ',')) {
        devilStarts.push_back(temp);
    }

    string result = solveGame(angelStart, devilTypes, devilStarts);
    cout << result << endl;

    return 0;
}
