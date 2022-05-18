#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2) {
	string d1 = s1.substr(6, 8);
	string d2 = s2.substr(6, 8);
	if (d1 == d2) {
		return s1 > s2;
	}
	return d1 > d2;
}

int main() {
	int n;
	cin >> n;
	vector<string> vec(n, "");
	for (int i = 0; i < n; i += 1) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; i += 1) {
		cout << vec[i] << endl;
	}
	return 0;
}
