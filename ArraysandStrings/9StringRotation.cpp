#include <bits/stdc++.h>
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
// ================= BRUTE ====================
bool isRotationBrute(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    int n = s1.length();
    string s1s1 = s1 + s1;
    for (int i = 0; i < s1s1.length(); i++) {
        if (s1s1.substr(i, n) == s2)
            return true;
    }
    return false;
}
// ================= BETTER ====================
/*bool isRotationBett1(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    if (s1.length() < 0) {
        string s1s1 = s1 + s1;
        // According to CCI question, isSubstring is already defined
        return isSubstring(s1s1, s2);
    }
    return false;
}*/
bool isRotationBett1(string s2, string s1) {
    int n = s.length();
    int m = goal.length();
    if (n != m)
        return false;
    string concatenatedS = s + s;
    if (concatenatedS.find(goal) != string::npos)
        return true;
    return false;
}

// ================= BEST(Rabin Karp) ====================
// We can also use KMP
bool isRotationBest(string p, string q) {
    string temp = p + p;
    int rolling_hash = 0;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        rolling_hash += temp[i] - 'a';
    }
    int target = 0;
    for (int i = 0; i < q.size(); i++) {
        target += q[i] - 'a';
    }

    for (int i = 0; i < temp.size() - n - 1; i++) {
        if (target == rolling_hash) {
            if (temp.substr(i, n) == q)
                return 1;
        }
        rolling_hash -= temp[i] - 'a';
        rolling_hash += temp[i + n] - 'a';
    }
    if (temp.substr(temp.size() - n - 1, n) == q)
        return 1;
    return 0;
}

int32_t main() {
    fast;

    cout.setf(ios::boolalpha);
    string s1, s2;
    cin >> s1 >> s2;
    cout << isRotation(s1, s2);
    cin.get();
}
