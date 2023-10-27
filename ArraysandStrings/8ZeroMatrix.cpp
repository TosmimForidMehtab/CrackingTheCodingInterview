#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> pos;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0)
                pos.push_back({i, j});
        }
    }
    while (!pos.empty()) {
        pair<int, int> p = pos.back();
        pos.pop_back();

        for (int i = 0; i < m; ++i) {
            matrix[i][p.second] = 0;
        }

        for (int i = 0; i < n; ++i) {
            matrix[p.first][i] = 0;
        }
    }
}
int32_t main() {
    fast;

    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
}