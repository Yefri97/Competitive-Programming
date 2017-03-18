// C++ STL queue
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

struct boat {
	int ct, ld, side;
	boat(int _ct, int _ld, int _side) : ct(_ct), ld(_ld), side(_side) {}
};

struct car {
	int id, t;
	car(int _id, int _t) : id(_id), t(_t) {}
};

int main() {
	int cs; cin >> cs;
	while (cs--) {
		int cp, tm, n; cin >> cp >> tm >> n;
		vector<int> ans(n);
		boat bt(0, 0, 0);
		vector< queue<car> > vqc(2);
		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			string side; cin >> side;
			if (side == "left") vqc[0].push(car(i, t));
			else vqc[1].push(car(i, t));
		}
		while (!vqc[0].empty() || !vqc[1].empty()) {
			int sl = INF;
			if (!vqc[0].empty()) sl = min(sl, vqc[0].front().t);
			if (!vqc[1].empty()) sl = min(sl, vqc[1].front().t);
			bt.ct = max(bt.ct, sl);
			while (!vqc[bt.side].empty() && vqc[bt.side].front().t <= bt.ct && bt.ld < cp) {
				ans[vqc[bt.side].front().id] = bt.ct + tm;
				vqc[bt.side].pop();
				bt.ld++;
			}
			bt.ct += tm;
			bt.side = 1 - bt.side;
			bt.ld = 0;
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
		if (cs) cout << endl;
	}
	return 0;
}