#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
// ================= BRUTE ====================
bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void generatePermutations(int idx, string &s, vector<string> &ans) {
    if (idx == s.length()) {
        ans.push_back(s);
        return;
    }

    for (int i = idx; i < s.length(); i++) {
        swap(s[i], s[idx]);
        generatePermutations(idx + 1, s, ans);
        swap(s[i], s[idx]);
    }
}
bool isPalindromePartition(string s) {
    vector<string> ans;
    generatePermutations(0, s, ans);
    for (string x : ans) {
        if (isPalindrome(x))
            return true;
    }
    return false;
}
// ================= Best ====================
bool isPalindromePartitionBest1(string s) {
    unordered_map<char, int> mp;
    for (char &x : s) {
        mp[x]++;
    }

    bool foundOdd = false;
    for (auto ele : mp) {
        int cnt = ele.second;
        if (cnt & 1) {
            if (foundOdd)
                return false;
            foundOdd = true;
        }
    }
    return true;
}

bool isPalindromePartitionBest2(string s) {
    unordered_map<char, int> mp;
    int oddCount = 0;
    for (char x : s) {
        mp[x]++;
        if (mp[x] & 1)
            oddCount++;
        else
            oddCount--;
    }

    return (oddCount <= 1);
}
// Using Bitvector
int toggle(int bitVec, int idx) {
    if (idx < 0)
        return bitVec;

    int mask = 1 << idx;
    if ((bitVec & mask))
        bitVec |= mask;
    else
        bitVec &= ~mask;

    return bitVec;
}
bool isPalindromePartitionBestest(string s) {
    int bitVec = 0;

    for (char &ch : s) {
        int x = ch - '0';

        bitVec = toggle(bitVec, x);
    }
    return bitVec == 0 or (bitVec & (bitVec - 1)) == 0;
}
int32_t main() {
    fast;
    cout.setf(ios::boolalpha);

    string s;
    cin >> s;
    cout << isPalindromePartitionBest2(s);
    cout << endl;
    cin.get();
}
