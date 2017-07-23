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

int S[110];
vi elevators[110], floors[10];

int dijkstra(int s, int t) {
	vi dist(100, oo); dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (u == t) return dist[t];
		if (d > dist[u]) continue;
		fori(i, 0, elevators[u].size()) {
			int curr_elevator = elevators[u][i];
			fori(j, 0, floors[curr_elevator].size()) {
				int v = floors[curr_elevator][j], w = S[curr_elevator] * abs(u - v) + (u == 0 ? 0 : 60);
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push(ii(dist[v], v));
				}
			}
		}
	}
	return -1;
}

vi splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	vi v;
	fori(i, 0, tokens.size())
		v.push_back(atoi(tokens[i].c_str()));
	return v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	vi input;
	while (getline(cin, line)) {
		input = splitLine(line);
		int n = input[0], t = input[1];
		getline(cin, line);
		input = splitLine(line);
		fori(i, 0, n)
			S[i] = input[i];
		fori(i, 0, 100) elevators[i].clear();
		fori(i, 0, 5) floors[i].clear();
		fori(i, 0, n) {
			getline(cin, line);
			input = splitLine(line);
			fori(j, 0, input.size())
				elevators[input[j]].push_back(i);
			floors[i] = input;
		}
		int ans = dijkstra(0, t);
		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}