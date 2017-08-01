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

const int oo = 1e9, mxn = 1000010;

int A[mxn], first[30], last[30];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	fori(i, 0, 26) first[i] = last[i] = -1;
	fori(i, 0, n) {
		first[s[n - i - 1]-'A'] = n - i - 1;
		last[s[i]-'A'] = i;
	}
	fori(i, 0, 26) {
		if (first[i] == -1) continue;
		A[first[i]]++;
		A[last[i]+1]--;
	}
	fori(i, 1, n)
		A[i] += A[i-1];
	int max_val = 0;
	fori(i, 0, n)
		max_val = max(max_val, A[i]);
	cout << (max_val > k ? "YES" : "NO") << endl;
	return 0;
}