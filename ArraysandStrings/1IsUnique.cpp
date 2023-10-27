#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// clang-format on
using namespace std;
// ================= BRUTE ====================
// O(n^2), O(1)
bool isUnik(string s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j++) {
            if (s[j] == s[i]) return false;
        }
    }
    return true;
}
// ================= BETTER ====================
// O(nlogn), O(1)
bool isUnikBett(string s) {
    int n = s.length();
    sort(s.begin(), s.end());
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) return false;
    }
    return true;
}
// ================= BEST ====================
// O(n), O(1)
bool isUnikBest(string s) {
    int n = s.length();
    unordered_map<char, int> mp;
    for (char ch : s) mp[ch]++;
    for (auto &it : mp) {
        if (it.second > 1) return false;
    }
    return true;
}
bool isUnikBestest(string s) {
    int check = 0;
    for (int i = 0; i < s.length(); i++) {
        int value = s[i] - 'a';
        if ((check & (1 << value)) > 0) return false;
        check |= (1 << value);
    }
    return true;
}
int32_t main() {
    fast cout.setf(ios::boolalpha);

    string s;
    cin >> s;
    cout << isUnikBest(s);
    cin.get();
}