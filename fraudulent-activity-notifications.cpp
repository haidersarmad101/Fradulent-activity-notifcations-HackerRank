#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, M = 201;
int n, d, k, expenditure[N], cnt[M];

// this function calculates the double of the median
int median2x(int i) {
	int sum, median, res;
		if (d & 1) {
			for (median = -1, sum = 0; sum <= d / 2; sum += cnt[++median]);
			res = 2 * median;
		} else {
			for (median = -1, sum = 0; sum < d / 2; sum += cnt[++median]);
			if (sum > d / 2) {
				median *= 2;
			} else for (int j = median + 1;; j++) {
				if (cnt[j]) {
					median += j;
					break;
				}
			}
			res = median;
		}
		cnt[expenditure[i - d]]--;
		return res;
}

int main() {
	cin >> n >> d;
	memset(cnt, 0, sizeof(cnt));
	int notifications = 0;
	for (int i = 0; i < n; i++) {
		cin >> expenditure[i];
		if (i >= d) 
			notifications += expenditure[i] >= median2x(i);
		cnt[expenditure[i]]++;
	}
	cout << notifications;
	return 0;
}