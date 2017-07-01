// 1D Array Manipulation
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 20;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string sn;
	while (getline(cin, sn) && sn != "0") {
		int n = atoi(sn.c_str());
		int max_val = 0;
		fori(i, 0, n) {
			string line; getline(cin, line);
			int cont = 0;
			fori(j, 0, line.size())
				cont += (line[j] == 'X');
			A[i] = cont;
			max_val = max(max_val, cont);
		}
		int ans = 0;
		fori(i, 0, n)
			ans += max_val - A[i];
		cout << ans << endl;
	}
	return 0;
}