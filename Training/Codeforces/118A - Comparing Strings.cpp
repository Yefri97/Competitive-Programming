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

const int INF = 1e9;

bool solver(string a, string b) {
	if (a.size() != b.size()) return false;
	int n = a.size();
	vi freqA(26), freqB(26);
	fori(i, 0, n) {
		freqA[a[i] - 'a']++;
		freqB[b[i] - 'a']++;
	}
	if (freqA != freqB) return false;
	int cnt = 0;
	fori(i, 0, n)
		cnt += (a[i] != b[i]);
	return cnt == 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b; cin >> a >> b;
	bool ans = solver(a, b);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}