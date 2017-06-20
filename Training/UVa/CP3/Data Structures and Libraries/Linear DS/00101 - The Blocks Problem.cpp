// 2D Array Manipulation
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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector< stack<int> > vs(n);
	fori(i, 0, n) vs[i].push(i);
	vector<int> pos(n);
	fori(i, 0, n) pos[i] = i;
	string cmd1;
	while (cin >> cmd1 && cmd1 != "quit") {
		string cmd2;
		int a, b;
		cin >> a >> cmd2 >> b;
		int pa = pos[a], pb = pos[b];
		if (pa == pb) continue;
		if (cmd1 == "move") {
			while (vs[pa].top() != a) {
				int x = vs[pa].top();
			 	vs[x].push(x); vs[pa].pop();
			 	pos[x] = x;
			}
			if (cmd2 == "onto") {
				while (vs[pb].top() != b) {
					int x = vs[pb].top();
					vs[x].push(x); vs[pb].pop();
					pos[x] = x;
				}
			}
			vs[pb].push(a); vs[pa].pop();
			pos[a] = pb;
		} else {
			stack <int> tmp;
			while (vs[pa].top() != a) {
				int x = vs[pa].top(); vs[pa].pop();
				tmp.push(x);
			}
			tmp.push(a); vs[pa].pop();
			if (cmd2 == "onto") {
				while (vs[pb].top() != b) {
					int x = vs[pb].top();
					vs[x].push(x); vs[pb].pop();
					pos[x] = x;
				}
			}
			while (!tmp.empty()) {
				int x = tmp.top();
				vs[pb].push(x); tmp.pop();
				pos[x] = pb;
			}
		}
	}
	fori(i, 0, n) {
		cout << i << ":";
		stack<int> tmp;
		while (!vs[i].empty()) tmp.push(vs[i].top()), vs[i].pop();
		while (!tmp.empty()) {
			cout << " " << tmp.top(); tmp.pop();
		}
		cout << endl;
	}
	return 0;
}