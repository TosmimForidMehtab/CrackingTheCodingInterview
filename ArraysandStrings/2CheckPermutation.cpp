#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
// O(n!), O(n)
void generatePermut(string &a, int idx, vector<string> &ans) {
	if (idx == a.length()) {
		ans.push_back(a);
		return;
	}

	for (int i = idx; i < a.length(); i++) {
		swap(a[idx], a[i]);
		generatePermut(a, idx + 1, ans);
		swap(a[idx], a[i]);
	}
}
bool checkPermut(string a, string b) {
	vector<string> ans;
	generatePermut(a, 0, ans);
	unordered_set<string> st;
	for (string s : ans) {
		st.insert(s);
		if (st.find(b) != st.end()) return true;
	}
	return false;
}
// ================= BETTER ====================
// O(nlogn + mlogm), O(1)
bool checkPermutBett(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}
// ================= BEST ====================
// O(n), O(n)
bool checkPermutBest(string a, string b) {
	int n = a.length(), m = b.length();
	unordered_map < char, int> mp;
	for (int i = 0; i < n; ++i) mp[a[i]]++;

	for (int i = 0; i < m; i++) {
		if (mp.find(b[i]) != mp.end()) {
			mp[b[i]]--;
			if (mp[b[i]] == 0) mp.erase(b[i]);
		}
		else return false;
	}
	return mp.empty();
}
// Same problem on Codestudio
bool areAnagram(string &a, string &b) {
	// Write your code here.
	if (a.size() != b.size()) return false;

	unordered_map<char, int> mp;

	for (int i = 0; i < a.size(); i++) mp[a[i]]++;
	for (int i = 0; i < a.size(); i++) mp[b[i]]--;
	for (auto it : mp) {
		if (it.second != 0) return false;
	}
	return true;
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	string a, b;
	cin >> a >> b;
	cout << checkPermut(a, b);
	cin.get();
}