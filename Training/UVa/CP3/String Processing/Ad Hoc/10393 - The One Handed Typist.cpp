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

string kf[] = {
	"qaz",
	"wsx",
	"edc",
	"rtvfgb",
	" ",
	" ",
	"yhnujm",
	"ik,",
	"ol.",
	"p;/"
};

int find_finger(char c) {
	fori(i, 0, 10)
		if (find(kf[i].begin(), kf[i].end(), c) != kf[i].end())
			return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		bitset<10> bs; bs.set();
		fori(i, 0, n) {
			int x; cin >> x; x--;
			bs.reset(x);
		}
		if (bs.test(5)) bs.set(4);
		set<string> st;
		fori(i, 0, m) {
			bool b = true;
			string word; cin >> word;
			for (char c : word)
				b &= bs.test(find_finger(c));
			if (b) st.insert(word);
		}
		int mmax = 0;
		for (string s : st)
			mmax = max(mmax, (int)s.size());
		int ans = 0;
		for (string s : st)
			ans += (s.size() == mmax);
		cout << ans << endl;
		for (string s : st)
			if (s.size() == mmax)
				cout << s << endl;
	}
	return 0;
}