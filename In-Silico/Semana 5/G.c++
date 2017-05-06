/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Football Broadcasting
 *  Level: Medium
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 301;

int mi[] = {0, -1, 0, 1};
int mj[] = {-1, 0, 1, 0};

int w, h, n;
char board[MAXN][MAXN][MAXN];
bool was[MAXN][MAXN][MAXN];
vector<ii> path;

bool dfs(int k, int i, int j) {
	if (k == n - 1) return true;
	was[k][i][j] = true;
	for (int e = 0; e < 4; e++) {
		int dk = k + 1, di = i + mi[e], dj = j + mj[e];
		if ((di >= 0 and di < h and dj >= 0 and dj < w) and board[dk][di][dj] != '#' and !was[dk][di][dj]) {
			path.push_back(ii(dj, di));
			if (dfs(dk, di, dj)) return true;
			path.pop_back();
		}
	}
	return false;
}

bool solver() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[0][i][j] != '#') {
				path.push_back(ii(j, i));
				if (dfs(0, i, j)) return true;
				path.pop_back();
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);  // Fast input - output
	ifstream fin("input.txt");    // File Input
	ofstream fout("output.txt");  // File Output
	/*** Code ***/
	fin >> w >> h;
	fin >> n;
	for (int k = 0; k < n; k++) {
		int x0, y0, x1, y1; fin >> x0 >> y0 >> x1 >> y1; x0--; y0--; x1--; y1--;
		for (int i = 0; i <= h; i++)
			for (int j = 0; j <= w; j++)
				board[k][i][j] = (i >= y0 and i <= y1 and j >= x0 and j <= x1)? '#' : '.';
	}
	
	bool ans = solver();

	if (!ans) {
		fout << "Impossible" << endl;
	} else {
		for (int i = 0; i < path.size(); i++)
			fout << path[i].first + 1 << " " << path[i].second + 1 << endl;
	}
	return 0;
}