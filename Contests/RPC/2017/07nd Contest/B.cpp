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

const int INF = 1e9, MAXN = 15;
string names[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> names[i];
	string cmd; cin >> cmd;
	int max_val = 0, len = 0;
	fori(i, 0, cmd.size()) {
		if (cmd[i] != cmd[i - 1]) len = 0;
		len++;
		max_val = max(max_val, len);
	}
	int b = 0, w = 0;
	queue<int> q;
	vii ans;
	ii curr_white = ii(0, 2), curr_black = ii(1, 3);
	ii cw = curr_white, cb = curr_black;
	fori(i, 4, n) q.push(i);
	fori(i, 0, cmd.size()) {
		if (cmd[i] == 'W') {
			swap(curr_white.first, curr_white.second);
			q.push(curr_black.second);
			curr_black.second = curr_black.first;
			curr_black.first = q.front(); q.pop();
			cb = curr_black;
			w++;
			b = 0;
		} else {
			swap(curr_black.first, curr_black.second);
			q.push(curr_white.second);
			curr_white.second = curr_white.first;
			curr_white.first = q.front(); q.pop();
			cw = curr_white;
			b++;
			w = 0;
		}
		if (w == max_val) ans.push_back(cw);
		if (b == max_val) ans.push_back(cb);
	}
	fori(i, 0, ans.size())
		cout << names[ans[i].first] << " " << names[ans[i].second] << endl;
	return 0;
}