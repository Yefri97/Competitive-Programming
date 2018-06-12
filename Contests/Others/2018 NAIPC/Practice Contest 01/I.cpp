#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, string> is;

const int oo = 1e9;

string kb[3] = {
	"qwertyuiop",
	"asdfghjkl",
	"zxcvbnm"
};

ii get_pos(char c) {
	fori(i, 0, 3)
		fori(j, 0, (int)kb[i].size())
			if (kb[i][j] == c)
				return ii(i, j);
}

int dist(char a, char b) {
	ii pos_a = get_pos(a), pos_b = get_pos(b);
	return abs(pos_a.first - pos_b.first) + abs(pos_a.second - pos_b.second);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string a; cin >> a;
		int l; cin >> l;
		vector<is> v(l);
		fori(i, 0, l) {
			string b; cin >> b;	
			int acc = 0;
			fori(j, 0, (int)a.size())
				acc += dist(a[j], b[j]);
			v[i] = is(acc, b);
		}
		sort(v.begin(), v.end());
		fori(i, 0, l)
			cout << v[i].second << " " << v[i].first << endl;
	}
	return 0;
}