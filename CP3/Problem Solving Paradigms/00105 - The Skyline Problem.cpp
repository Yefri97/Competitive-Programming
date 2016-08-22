#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int max_n = 5000;

int main() {
	int a, h, b, heights[max_n + 10];
	vector<ii> events;
	for (int i = 0; cin >> a >> h >> b; i++) {
		events.push_back(ii(a, i));
		events.push_back(ii(b, i));
		heights[i] = h;
	}
	sort(events.begin(), events.end());
	vector<int> ans;
	set<ii> s;
	s.insert(ii(0, -1));
	int mmax = 0;
	for (int i = 0; i < events.size(); ) {
		int curr = events[i].first;
		while (curr == events[i].first) {
			int id = events[i].second;
			ii event = ii(heights[id], id);
			if (s.count(event))
				s.erase(event);
			else
				s.insert(event);
			i++;
		}
		set<ii>::iterator last = s.end(); last--;
		ii temp = *last;
		int x = temp.first;
		if (mmax != x) {
			ans.push_back(curr);
			ans.push_back(x);
			mmax = x;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}