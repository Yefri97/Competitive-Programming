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
	int cs = 0;
	string s;
	while (cin >> s) {
		vector<string> vs;
		vs.push_back(s);
		while (cin >> s && s != "9")
			vs.push_back(s);
		int n = vs.size(), ans = 0;
		fori(i, 0, n)
			fori(j, 0, n) 
				if (i != j)
					ans |= (vs[i].size() <= vs[j].size() && vs[i] == vs[j].substr(0, vs[i].size()));
		cout << "Set " << ++cs << " is" << (ans ? " not " : " ") << "immediately decodable" << endl;
	}
	return 0;
}