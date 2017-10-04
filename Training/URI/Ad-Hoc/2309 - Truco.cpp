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

const int INF = 1e9, MAXN = 1000000;
int A[MAXN], B[MAXN];
int values[] = {4, 5, 6, 7, 12, 11, 13, 1, 2, 3};

int val(int x) {
	int val = 0;
	while (x != values[val]) val++;
	return val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int a = 0, b = 0;
	while (n--) {
		fori(i, 0, 3)
			cin >> A[i];
		fori(i, 0, 3)
			cin >> B[i];
		int x = 0, y = 0;
		fori(i, 0, 3) {
			if (val(B[i]) > val(A[i])) y++;
			else x++;
		}
		if (x > y) a++;
		else b++;
	}
	cout << a << " " << b << endl;
	return 0;
}