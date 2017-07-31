#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int A[] = {-1, -1, 1, 7, 4, 2, 0, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin >> k;
	int cnt = 0;
	while (k > 21) k -= 7, cnt++;
	cout << A[k];
	fori(i, 0, cnt) cout << 8;
	cout << endl;
	return 0;
}