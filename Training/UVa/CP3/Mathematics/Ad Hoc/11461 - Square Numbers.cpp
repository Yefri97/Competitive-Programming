// Number Systems or Sequences
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

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i * i <= MAXN; i++)
		A[i * i] = 1;
	fori(i, 1, MAXN)
		A[i] = A[i] + A[i - 1];
	int a, b;
	while (cin >> a >> b && (a || b))
		cout << A[b] - A[a - 1] << endl;
	return 0;
}