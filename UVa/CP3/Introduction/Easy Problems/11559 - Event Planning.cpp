// Easy Problems
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20, INF = 10001;
int p[MAXN + 10], mat[MAXN + 10][MAXN + 10];

int main() {
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		for (int i = 0; i < h; i++) {
			cin >> p[i];
			for (int j = 0; j < w; j++)
				cin >> mat[i][j];
		}
		int ans = INF;
		for (int i = 0; i < h; i++) {
			int mmax = -1;
			for (int j = 0; j < w; j++)
				mmax = max(mmax, mat[i][j]);
			if (n < mmax)
				ans = min(ans, p[i]);
		}
		if (n * ans > b) cout << "stay home" << endl;
		else cout << n * ans << endl;
	}
	return 0;
}