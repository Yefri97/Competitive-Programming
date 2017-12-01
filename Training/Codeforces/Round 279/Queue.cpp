#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi A(n), B(n);
	fori(i, 0, n)
		cin >> A[i] >> B[i];
	map<int, int> mapper;
	fori(i, 0, n)
		mapper[A[i]] = B[i];
	int first, second;
	set<int> dict;
	fori(i, 0, n)
		dict.insert(B[i]);
	fori(i, 0, n) {
		if (dict.find(A[i]) == dict.end()) first = A[i];
		if (A[i] == 0) second = B[i];
	}
	vi ans;
	fori(i, 0, (n + 1) / 2) {
		ans.push_back(first);
		first = mapper[first];
		ans.push_back(second);
		second = mapper[second];
	}
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}