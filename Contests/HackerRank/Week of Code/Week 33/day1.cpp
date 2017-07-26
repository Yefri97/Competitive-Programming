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

const int INF = 1e9, MAXN = 100010;

int A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	fori(i, 0, n)
		cin >> B[i];
	ii first_minA = ii(INF, -1), second_minA = ii(INF, -1);
	ii first_minB = ii(INF, -1), second_minB = ii(INF, -1);
	fori(i, 0, n) {
		if (A[i] < first_minA.first)
			first_minA = ii(A[i], i);
		if (B[i] < first_minB.first)
			first_minB = ii(B[i], i);
	}
	if (first_minA.second == first_minB.second) {
		A[first_minA.second] = INF;
		B[first_minB.second] = INF;
		fori(i, 0, n) {
			if (A[i] < second_minA.first)
				second_minA = ii(A[i], i);
			if (B[i] < second_minB.first)
				second_minB = ii(B[i], i);
		}
		cout << min(first_minA.first + second_minB.first, second_minA.first + first_minB.first) << endl;
	} else {
		cout << first_minA.first + first_minB.first << endl;
	}
	return 0;
}