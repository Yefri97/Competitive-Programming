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

vector<string> split_line(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

string process(string s, int k) {
	string ans;
	fori(i, 0, s.size()) {
		int x = s[i] == ' ' ? 0 : s[i] - 'A' + 1;
		x = mod(x - k, 27);
		ans.push_back(x == 0 ? ' ' : x + 'A' - 1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	set<string> dict;
	string line;
	while (getline(cin, line) && line != "#")
		dict.insert(line);
	getline(cin, line);
	int n = line.size(), max_cnt = 0, k = 0;
	fori(i, 0, 27) {
		string s = process(line, i);
		vector<string> vs = split_line(s);
		int cnt = 0;
		fori(j, 0, vs.size())
			cnt += (dict.find(vs[j]) != dict.end());
		if (cnt > max_cnt) {
			max_cnt = cnt;
			k = i;
		}
	}
	string ans = process(line, k);
	vector<string> vs = split_line(ans);
	int cnt = vs[0].size();
	cout << vs[0];
	fori(i, 1, vs.size()) {
		if (cnt + vs[i].size() + 1 > 60) {
			cout << endl;
			cout << vs[i];
			cnt = vs[i].size();
		} else {
			cout << " " << vs[i];
			cnt += vs[i].size() + 1;
		}
	}
	cout << endl;
	return 0;
}