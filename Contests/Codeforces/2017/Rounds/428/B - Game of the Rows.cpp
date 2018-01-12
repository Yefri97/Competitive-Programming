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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	priority_queue<int> pq;
	fori(i, 0, k) {
		int x; cin >> x;
		pq.push(x);
	}
	int slot4 = n, slot2 = 2 * n, slot1 = 0;
	bool ans = true;
	while (!pq.empty()) {
		int x = pq.top(); pq.pop();
		if (slot4) {
			int y = min(4, x);
			int a = 4 - y - 1;
			if (a == 1) slot1++;
			if (a == 2) slot2++;
			x -= y;
			slot4--;
		} else if (slot2) {
			int y = min(2, x);
			x -= y;
			slot2--;
		} else if (slot1) {
			x--;
			slot1--;
		} else {
			ans = false;
			break;
		}
		if (x) pq.push(x);
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}