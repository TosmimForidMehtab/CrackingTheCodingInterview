#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
/*
Check if the value of a binary number(passed as string) equals the hexadecimal representation of string
*/
int convertFromBase(string, int);
bool compareBinToHex(string binaryNum, string hexNum) {
	int num1 = convertFromBase(binaryNum, 2);
	int num2 = convertFromBase(hexNum, 16);

	if (num1 < 0 or num2 < 0) return false;
	return num1 == num2;
}

int convertFromBase(string num, int base) {
	int n = num.length();
	if (base < 2 or (base > 10 and base != 16)) return -1;
	int val = 0;
	for (int i = n - 1; i >= 0; i++) {
		int digit = num[i] - '0';
		if (digit < 0 or digit >= base) return -1;

		int exponent = n - 1 - i;
		val += digit * pow(base, exponent);
	}
	return val;
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	string bi, hex;
	cin >> bi >> hex;
	cout << compareBinToHex(bi, hex);
	cin.get();
}