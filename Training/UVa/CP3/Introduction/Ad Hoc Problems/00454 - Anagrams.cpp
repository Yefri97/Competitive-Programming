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
typedef pair<string, string> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int nextInt() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt();
	string b; getline(cin, b);
	while (t--) {
		string line;
		int n = 0;
		vector<string> vs;
		vector< map<char, int> > freq;
		while (getline(cin, line) && (int)line.size()) {
			vs.push_back(line);
			freq.push_back(map<char, int>());
			fori(i, 0, (int)line.size())
				if (line[i] != ' ')
					freq[n][line[i]]++;
			n++;
		}
		vector<ii> ans;
		fori(i, 0, n) {
			fori(j, 0, i) {
				if (freq[i] == freq[j]) {
					string a = vs[i], b = vs[j];
					if (a > b)
						swap(a, b);
					ans.push_back(ii(a, b));
				}
			}
		}
		sort(ans.begin(), ans.end());
		fori(i, 0, (int)ans.size())
			cout << ans[i].first << " = " << ans[i].second << endl;
		if (t) cout << endl;
	}
	return 0;
}