#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
// ================= BRUTE (1 TC Failing)====================
bool isOneAway(string a, string b) {
    unordered_map<char, int> mp;
    if (a.size() < b.size())
        swap(a, b);
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    for (int i = 0; i < m; i++) {
        if (mp.find(b[i]) != mp.end()) {
            // cout << b[i] << "->" << mp[b[i]] << endl;
            mp[b[i]]--;
            if (mp[b[i]] == 0)
                mp.erase(b[i]);
        }
    }
    return mp.size() <= 1;
}
// ================= BETTER O(N+M)====================
bool isOneAwayBett(string a, string b) {
    int lenA = a.size(), lenB = b.size();

    // If the difference between the string lengths is more than one, we can
    // never con convert string a into string b by doing only one operation.
    if (abs(lenA - lenB) > 1) {
        return false;
    }

    // We will only iterate uptill the length of the shorter string.
    int minLen = min(lenA, lenB);

    for (int i = 0; i < minLen; i++) {
        if (a[i] != b[i]) {
            bool validReplace = a.substr(i + 1) == b.substr(i + 1);
            // If we replace the character.

            bool validInsert = a.substr(i) == b.substr(i + 1);
            // If we insert a character at this index.

            bool validDelete = a.substr(i + 1) == b.substr(i);
            // if we delete the character at this index.

            // If after performing any of these operations, the remaining
            // strings are equal, it means that it is possible for us to convert
            // string a into string b.
            return (validReplace || validInsert || validDelete);
        }
    }

    // Since there is no mismatch and the difference between the
    // string lengths is not more than 1, so we can return true.
    return true;
}
// ================= BEST O(N+M)====================
bool isOneAwayBest(string a, string b) {
    int lenA = a.size(), lenB = b.size();

    // Initialize a variable to store the number of mismatched characters.
    int mismatch = 0;

    // Initialize one pointer for each string.
    int ptrA = 0, ptrB = 0;

    while (ptrA < lenA and ptrB < lenB) {
        if (a[ptrA] == b[ptrB]) {
            ptrA++;
            ptrB++;
        }

        else {
            // If the characters do not match, increment the count.
            mismatch++;

            // If the mismatched characters become more than one, return False.
            if (mismatch > 1) {
                return false;
            }

            // If the lengths of both the strings are equal, increment both
            // pointers by 1.
            if (lenA == lenB) {
                ptrA++;
                ptrB++;
            }

            // If the length of string a is more than string b, increment
            // pointer of string a.
            else if (lenA > lenB) {
                ptrA++;
            }

            // If the length of string a is less than string b, increment
            // pointer of string b.
            else if (lenA < lenB) {
                ptrB++;
            }
        }
    }

    // If there is any extra character at the end of any of the two strings,
    // increment the count.
    if (ptrA < lenA or ptrB < lenB) {
        mismatch++;
    }

    // If the number of mismatched characters in less than or equal to one,
    // return True.
    if (mismatch <= 1) {
        return 1;
    }

    else {
        return 0;
    }
}
int32_t main() {
    cout.setf(ios::boolalpha);

    string s1, s2;
    cin >> s1 >> s2;
    cout << isOneAwayBest(s1, s2);
    cin.get();
}