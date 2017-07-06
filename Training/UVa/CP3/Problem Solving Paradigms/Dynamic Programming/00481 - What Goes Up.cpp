// Longest Increasing Subsequence (LIS)
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

const int INF = 1e9, MAXN = 1000010;
int A[MAXN], L[MAXN], L_id[MAXN], P[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, n = 0;
	while (cin >> x)
		A[n] = x, n++;
	int lis = 0, lis_end = 0;
	fori(i, 0, n) {
		int pos = lower_bound(L, L + lis, A[i]) - L;
		L[pos] = A[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos + 1 >= lis) {
			lis = pos + 1;
			lis_end = i;
		}
	}
	cout << lis << endl << "-" << endl;
	x = lis_end;
	stack<int> s;
	for (; x >= 0; x = P[x]) s.push(A[x]);
	for (; !s.empty(); s.pop()) cout << s.top() << endl;
	return 0;
}