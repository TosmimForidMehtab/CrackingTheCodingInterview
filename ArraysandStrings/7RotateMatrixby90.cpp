#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
// ================= BETTER ====================
// O(n*m), O(n*m)
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    int newI = 0, newJ = 0;
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            ans[newI][newJ] = matrix[j][i];
            newJ++;
            if (newJ == m)
                newJ = 0;
        }
        newI++;
    }
    return ans;
}
vector<vector<int>> rotateMatrixAnti(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    int newI = n - 1, newJ = m - 1;
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            ans[newI][newJ] = matrix[j][i];
            newJ--;
            if (newJ < 0)
                newJ = m - 1;
        }
        newI--;
    }
    return ans;
}
// ================= BEST ====================
// O(n*m), O(1)
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void rotate_(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 or matrix.size() != matrix[0].size())
        return false;
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];

            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}
int32_t main() {
    fast;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> ans = rotateMatrix(arr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
}