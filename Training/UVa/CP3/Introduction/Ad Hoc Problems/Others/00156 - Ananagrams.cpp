// Anagram
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

const int INF = 1e9, MAXN = 1010;

vector<vi> freq;

bool check(int i) {
	fori(j, 0, freq.size())
		if (i != j && freq[i] == freq[j])
			return false;
	return true;
}

int toint(char c) {
	if (isupper(c)) return c - 'A';
	return c - 'a';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<string> vs, ans;
	int it = 0;
	string s;
	while (cin >> s && s != "#") {
		vs.push_back(s);
		freq.push_back(vi(26));
		fori(i, 0, s.size())
			freq[it][toint(s[i])]++;
		it++;
	}
	fori(i, 0, freq.size())
		if (check(i))
			ans.push_back(vs[i]);
	sort(ans.begin(), ans.end());
	fori(i, 0, ans.size())
		cout << ans[i] << endl;
	return 0;
}