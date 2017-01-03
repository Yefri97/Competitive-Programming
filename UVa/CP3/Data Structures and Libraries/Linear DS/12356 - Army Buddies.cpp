// 1D Array Manipulation
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 100000;
int pleft[MAXN + 10], pright[MAXN + 10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int s, b;
	while (cin >> s >> b && s) {
		for (int i = 0; i < s; i++) pleft[i] = i - 1;
		for (int i = 0; i < s - 1; i++) pright[i] = i + 1; pright[s - 1] = -1;
		while (b--) {
			int a, b; cin >> a >> b; a--; b--;
			int l = pleft[a], r = pright[b];
			if (l != -1) pright[l] = r;
			if (r != -1) pleft[r] = l;
			if (l != -1) cout << l + 1;
			else cout << "*";
			cout << " ";
			if (r != -1) cout << r + 1;
			else cout << "*";
			cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}