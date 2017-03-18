#include <bits/stdc++.h>

using namespace std;

const int maxn = 16;

int n, ans[maxn + 10], used[maxn + 10], sieve[2 * maxn + 10];

void init_sieve() {
	int size = 2 * maxn + 10;
	for (int i = 2; i * i <= size; i++) if (sieve[i])
		for (int j = i * i; j <= size; j += i) sieve[j] = 0;
}

void print_ans() {
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

void solver(int id) {
	if (id == n && sieve[ans[n - 1] + ans[0]]) print_ans();
	for (int i = 0; i < n; i++) {
		if (!used[i] && sieve[ans[id - 1] + i + 1]) {
			ans[id] = i + 1;
			used[i] = 1;
			solver(id + 1);
			used[i] = 0;
		}
	}
}

int main() {
	memset(sieve, 1, sizeof sieve);
	memset(used, 0, sizeof used);
	used[0] = 1; ans[0] = 1;
	init_sieve();
	for (int t = 0; cin >> n; t++) {
		if (t) cout << endl;
		cout << "Case " << t + 1 << ":" << endl;
		solver(1);
	}
	return 0;
}