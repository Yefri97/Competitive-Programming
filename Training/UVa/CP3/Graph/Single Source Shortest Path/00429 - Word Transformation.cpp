#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int n;
vector<string> dic;
map<string, int> mapper;

bool check(string a, string b) {
	if (a.size() != b.size()) return false;
	int cnt = 0;
	fori(i, 0, a.size())
		cnt += (a[i] != b[i]);
	return (cnt == 1);
}

int solver(string a, string b) {
	int s = mapper[a], t = mapper[b];
	vi dist(n, oo); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) return dist[t];
		fori(v, 0, dic.size()) if (check(dic[u], dic[v])) {
			if (dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}

int nextInt() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool first = true;
	int t = nextInt();
	while (t--) {
		if (!first) cout << endl; first = false;
		dic.clear();
		mapper.clear();
		string word;
		for (int i = 0; getline(cin, word) && word != "*"; i++) {
			dic.push_back(word);
			mapper[word] = i;
		}
		n = mapper.size();
		string query;
		while (getline(cin, query) && query.size()) {
			vector<string> vs = splitLine(query);
			string a = vs[0], b = vs[1];
			int ans = solver(a, b);
			cout << a << " " << b << " " << ans << endl;
		}
	}
	return 0;
}