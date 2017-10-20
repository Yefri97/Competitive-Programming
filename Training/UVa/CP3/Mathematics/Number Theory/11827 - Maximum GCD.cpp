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

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int next_int() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = next_int();
	while (t--) {
		string line; getline(cin, line);
		vector<string> vs = splitLine(line);
		int n = vs.size();
		vi v(n);
		fori(i, 0, n)
			v[i] = atoi(vs[i].c_str());
		int ans = 0;
		fori(i, 0, n)
			fori(j, 0, i)
				ans = max(ans, __gcd(v[i], v[j]));
		cout << ans << endl;
	}
	return 0;
}