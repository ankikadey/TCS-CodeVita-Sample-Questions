#include <iostream>
#include <vector>
using namespace std;

vector<int> marketSurvey(vector<int> &Default, vector<vector<int>> &survey) {
    vector<int> results;

    int T = 1; // Assuming a single test case

    for (int t = 0; t < T; t++) {
        int N = Default.size();
        int M = survey.size();

        vector<int> latestKey = Default;
        vector<int> scores(M, 0);

        for (int i = 0; i < M; i++) {
            int rightAnswers = 0;
            for (int j = 0; j < N; j++) {
                if (survey[i][j] == latestKey[j]) {
                    rightAnswers++;
                } else if (survey[i][j] != 0) {
                    latestKey[j] = survey[i][j];
                }
            }
            results.push_back(rightAnswers);
            scores[i] = rightAnswers;
        }

        int topScore = 0;
        int topper = -1;
        for (int i = 0; i < M; i++) {
            if (scores[i] >= topScore) {
                topScore = scores[i];
                topper = i + 1;
            }
        }

        results.push_back(topper);
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    vector<vector<int>> testCases;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> Default(N);
        vector<vector<int>> survey(M, vector<int>(N));

        for (int j = 0; j < N; j++) {
            cin >> Default[j];
        }

        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> survey[j][k];
            }
        }

        vector<int> res = marketSurvey(Default, survey);
        for (int j = 0; j < M; j++) {
            cout << res[j] << " ";
        }
        cout << endl;

        cout << res[M] << endl;
    }

    return 0;
}
