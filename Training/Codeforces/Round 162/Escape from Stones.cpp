#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	deque<int> dq;
	dq.push_front(n);
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == 'r') dq.push_front(i + 1);
		else dq.push_back(i + 1);
	}
	while (!dq.empty()) {
		int id = dq.front(); dq.pop_front();
		cout << id << endl;
	}
	return 0;
}
