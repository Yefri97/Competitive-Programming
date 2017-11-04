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

char m[10][10];

string process(string s) {
	string ans;
	fori(i, 0, (int)s.size()) if (s[i] != ' ')
		ans.push_back(toupper(s[i]));
	return ans;
}

int next_int() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = next_int();
	while (t--) {
		string key; getline(cin, key);
		key = process(key);
		fori(i, 0, 26) if (i + 'A' != 'Q')
			key.push_back(i + 'A');
		vii seen(26);
		fori(i, 0, 26) seen[i] = ii(-1, -1);
		int it = 0;
		fori(i, 0, 5) {
			fori(j, 0, 5) {
				while (seen[key[it] - 'A'].first != -1) it++;
				m[i][j] = key[it];
				seen[key[it] - 'A'] = ii(i, j);
			}
		}
		string word; getline(cin, word);
		word = process(word);
		vii v;
		int n = word.size();
		fori(i, 0, n) {
			if (i + 1 == n || word[i] == word[i + 1]) {
				v.push_back(ii(word[i] - 'A', 'X' - 'A'));
			} else {
				v.push_back(ii(word[i] - 'A', word[i + 1] - 'A'));
				i++;
			}
		}
		string ans;
		fori(i, 0, (int)v.size()) {
			ii curr = v[i];
			int i0 = seen[curr.first].first, j0 = seen[curr.first].second;
			int i1 = seen[curr.second].first, j1 = seen[curr.second].second;
			if (i0 == i1) {
				ans.push_back(m[i0][mod(j0 + 1, 5)]);
				ans.push_back(m[i0][mod(j1 + 1, 5)]);
			} else if (j0 == j1) {
				ans.push_back(m[mod(i0 + 1, 5)][j0]);
				ans.push_back(m[mod(i1 + 1, 5)][j0]);
			} else {
				ans.push_back(m[i0][j1]);
				ans.push_back(m[i1][j0]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}