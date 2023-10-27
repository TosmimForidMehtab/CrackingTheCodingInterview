#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
// ================= BETTER ====================
// O(n^3)
void URLify(string &s, int n) {
    string rep = "%20";
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            s.replace(i, 1, rep);
        }
    }
}

// ================= BEST ====================
// O(n), O(1)
void URLifyBest(char *s, int n) {
    // Count whitespaces
    int spaceCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ')
            spaceCount++;
    }
    // Calculate new length
    int newLength = n + 2 * spaceCount;
    // Defining the end of the string
    s[newLength] = '\0';

    // Iterating from the front of the string will result in overwriting some
    // characters, so iterate from the end
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[newLength - 1] = '0';
            s[newLength - 2] = '2';
            s[newLength - 3] = '%';
            newLength -= 3;
        } else {
            s[newLength - 1] = s[i];
            newLength--;
        }
    }
}
// Codestudio
string replaceSpaces(string &str) {
    // Write your code here.
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            temp.push_back(str[i]);
        }
    }
    return temp;
}
int32_t main() {
    fast;

    char s[100];
    int n;
    cin >> n;
    cin.ignore();
    cin.getline(s, 100);
    URLifyBest(s, n);
    cout << s;
    cout << endl;
    cin.get();
}