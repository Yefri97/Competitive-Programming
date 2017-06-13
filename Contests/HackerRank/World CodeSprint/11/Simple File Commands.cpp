// time: 43 min
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define substr(str, a, b) (str).substr((a), (b) - (a))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

map <string, priority_queue <int> > slopes;
map <string, int> cnt;

void create_file(string name) {
	cout << name;
	if (slopes[name].empty()) {
		if (cnt[name])
			cout << "(" << cnt[name] << ")";
		cnt[name]++;
	} else {
		int num = slopes[name].top(); slopes[name].pop();
		if (num)
			cout << "(" << -num << ")";
	}
}

void delete_file(string name) {
	cout << name;
	int num = 0;
	if (name[name.size() - 1] == ')') {
		int i = name.size() - 1;
		while (name[i] != '(') i--;
		num = atoi(substr(name, i + 1, name.size() - 1).c_str());
		name = substr(name, 0, i);
	}
	slopes[name].push(-num);
}

void rename_file(string name1, string name2) {
	delete_file(name1);
	cout << " -> ";
	create_file(name2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		string cmd; cin >> cmd;
		if (cmd == "crt") {
			string name; cin >> name;
			cout << "+ ";
			create_file(name);
			cout << endl;
		} else if (cmd == "del") {
			string name; cin >> name;
			cout << "- ";
			delete_file(name);
			cout << endl;
		} else {
			string name1, name2; cin >> name1 >> name2;
			cout << "r ";
			rename_file(name1, name2);
			cout << endl;
		}
	}
	return 0;
}