#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void solve(vector<int>& arr, int id, int sum, int target, int& ans) {
	if (id == arr.size()) {
		if (sum == target) {
			ans++;
		}
		return;
	}
	if (sum == target) {
		ans++;
		return;
	}
	if (sum > target) {
		return;
	}
	solve(arr, id + 1, sum + arr[id], target, ans);
	solve(arr, id + 1, sum, target, ans);
}

int main(int argc, char** argv) {
	int n, target;
	cin >> n >> target;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i += 1) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	solve(arr, 0, 0, target, ans);
	cout << ans << endl;
	return 0;
}

