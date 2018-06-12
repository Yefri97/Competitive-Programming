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

int freq[10];

string getMin() {
	string ans;
	fori(i, 0, 10)
		fori(j, 0, freq[i])
			ans.push_back(i + '0');
	return ans;
}

string calc() {
	set<string> st;
	fori(k, 0, 10) {
		if (freq[k] == 0) continue;
		freq[k]--;
		fori(i, 0, 10) {
			if (freq[i] == 0) continue;
			freq[i]--;
			fori(j, 0, 10) {
				if (freq[j] == 0) continue;
				if ((i * 10 + j + 4 * (k & 1)) % 8 == 0) {
					freq[j]--;
					string s = getMin();
					s.push_back(k + '0');
					s.push_back(i + '0');
					s.push_back(j + '0');
					st.insert(s);
					freq[j]++;
				}
			}
			freq[i]++;
		}
		freq[k]++;
	}
	if (st.size()) return *(st.begin());
	return "-1";
}

string solver(string n) {
	int l = n.size();
	fori(i, 0, l)
		freq[n[i] - '0']++;
	fori(i, 1, 10) {
		if (freq[i] == 0) continue;
		freq[i]--;
		string val = calc();
		if (val != "-1") {
			string c(1, i + '0');
			return c + val;
		}
		freq[i]++;
	}
	return "-1";
}

string bf(string n) {
	sort(n.begin(), n.end());
	do {
		if (n[0] == '0') continue;
		int x = atoi(n.c_str());
		if (x % 8 == 0) return n;
	} while (next_permutation(n.begin(), n.end()));
	return "-1";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string n; cin >> n;
	string ans = (n.size() > 3 ? solver(n) : bf(n));
	cout << ans << endl;
	return 0;
}