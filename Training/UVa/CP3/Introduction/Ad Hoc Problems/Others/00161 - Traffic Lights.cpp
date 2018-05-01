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

const int oo = 1e9, mxn = 100;

int input[mxn];

struct Event {
	int curr, cycle, status;
	Event() {}
	Event(int _curr, int _cycle, int _status) : curr(_curr), cycle(_cycle), status(_status) {}
	bool operator < (const Event &o) const {
		if (curr != o.curr)
			return curr > o.curr;
		return status;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x;
	while (cin >> x && x) {
		int n = 0;
		input[n++] = x;
		while (cin >> x && x)
			input[n++] = x;
		priority_queue<Event> pq;
		fori(i, 0, n)
			pq.push(Event(input[i] - 5, input[i], 0));
		int ans = -1, cnt = n;
		while (pq.top().curr <= 18000) {
			Event e = pq.top(); pq.pop();
			if (e.status) {
				cnt++;
				if (cnt == n) { ans = e.curr; break; }
				pq.push(Event(e.curr + e.cycle - 5, e.cycle, 0));
			} else {
				cnt--;
				pq.push(Event(e.curr + e.cycle + 5, e.cycle, 1));
			}
		}
		if (ans == -1) {
			cout << "Signals fail to synchronise in 5 hours" << endl;
		} else {
			int ss = ans % 60; ans /= 60;
			int mm = ans % 60; ans /= 60;
			int hh = ans;
			cout << setfill('0');
			cout << setw(2) << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << endl;
		}
	}
	return 0;
}