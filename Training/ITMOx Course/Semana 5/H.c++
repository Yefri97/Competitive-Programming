/*
 *  ITMOx Course - 4st Week Problems
 *  Problem: Hamiltonian Paths
 *  Level: Hard
 */
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
using namespace std;

ifstream fin("input.txt");    // File Input
ofstream fout("output.txt");  // File Output

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 25;

int n, lim;
int g[MAXN], g2[MAXN];
int dp[1 << (MAXN-1)], dp2[1 << (MAXN-1)];
int was[MAXN];

void hamiltonianDP(int *dp, int *g) {
	dp[0] = 1;
	fori(bitmask,0,lim) {
		fori(u,1,n) {
			int bit = 1 << (u - 1);
			if ((bitmask & bit) == 0)
				continue;
			int prev = bitmask ^ bit;
			if ((g[u] & dp[prev]) != 0)
				dp[bitmask] |= 1 << u;
		}
	}
}

bool arePaths = false;

vector<int> path(int v, int m, int* dp, int* g) {
	vector<int> ans;
	while (m > 0) {
		assert(m & (1 << (v-1)));
		ans.push_back(v);
		m = m ^ (1 << (v-1));
		fori(u,1,n) {
			if (g[v] & dp[m] & (1 << u)) {
				v = u;
				break;
			}
		}
	}
	return ans;
}

void printAns(const vector<int>& start, const vector<int>& end) {
	arePaths = true;
	vector<int> res;
	res.insert(res.end(), start.begin(), start.end());
	res.push_back(0);
	res.insert(res.end(), end.rbegin(), end.rend());
	fout << res[0] + 1;
	fori(i,1,res.size())
		fout << " -> " << res[i] + 1;
	fout << endl;
}

int main() {
	ios::sync_with_stdio(false);  // Fast input - output
	/*** Code ***/
	fin >> n;
	fori(i,0,n) {
		string line; fin >> line;
		fori(j,0,n)
			if (line[j] == '1') {
				g[j] |= (1 << i);
				g2[i] |= (1 << j);
			}
	}

	lim = 1 << (n - 1);
	hamiltonianDP(dp, g);
	hamiltonianDP(dp2, g2);

	int full = lim-1;
	fori(m,0,lim) {
		int other = full ^ m;
		int starts = dp2[m], ends = dp[other];
		fori(u,0,n) {
			if ((starts & (1 << u)) && (~was[u] & ends)) {
				vector<int> start = path(u, m, dp2, g2);
				fori(v,0,n) {
					if (~was[u] & (1 << v) & ends) {
						vector<int> end = path(v, other, dp, g);
						was[u] |= 1 << v;
						printAns(start, end);
					}
				}
			}
		}
	}
	if (!arePaths)
		fout << "No paths" << endl;
	return 0;
}