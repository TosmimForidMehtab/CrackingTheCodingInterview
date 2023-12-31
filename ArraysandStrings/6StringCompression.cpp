#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
// ================= BRUTE ====================
string compress(string s) {
    string compressed = "";
    int consecCnt = 1;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (i + 1 < n and s[i] == s[i + 1])
            consecCnt++;
        else {
            compressed += s[i] + to_string(consecCnt);
            consecCnt = 1;
        }
    }
    return compressed.length() < s.length() ? compressed : s;
}
// ================= BETTER ====================
string compressTheString(string &s) {
    int count = 1;
    string ans = "";
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
            if (count > 1)
                ans += s[i] + to_string(count);
            else
                ans += s[i];

            count = 1;
        } else
            count++;
    }

    if (count > 1)
        ans += s[s.size() - 1] + to_string(count);
    else
        ans += s[s.size() - 1];

    return ans;
}
// Leetcode version
int compressLeet(vector<char> &s) {
    int n = s.size();

    int index = 0, i = 0;

    while (i < n) {
        char currChar = s[i];
        int countt = 0;

        // Duplicate count
        while (i < n and currChar == s[i]) {
            i++;
            countt++;
        }

        s[index++] = currChar;

        if (countt > 1) {
            string countStr = to_string(countt);
            for (char &ch : countStr)
                s[index++] = ch;
        }
    }
    return index;
}
// ================= BEST ====================

int32_t main() {
    fast;

    string s;
    cin >> s;
    cout << compress(s);
    cin.get();
}