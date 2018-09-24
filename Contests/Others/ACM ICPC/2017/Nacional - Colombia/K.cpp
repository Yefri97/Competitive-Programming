#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;

const int oo = 1e9, MN = 200;

string names[MN];
int points[MN], scored[MN], against[MN], visitor[MN];

bool cmp(int i, int j) {
	if (points[i] != points[j])
		return points[i] > points[j];
	if (scored[i] - against[i] != scored[j] - against[j])
		return scored[i] - against[i] > scored[j] - against[j];
	if (scored[i] != scored[j])
		return scored[i] > scored[j];
	if (visitor[i] != visitor[j])
		return visitor[i] > visitor[j];
	return names[i] < names[j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) { cin.ignore();
		fori(i, 0, MN) points[i] = scored[i] = against[i] = visitor[i] = 0;
		string line;
		vector<iiii> input(n);
		map<string, int> mapper;
		int m = 0;
		fori(i, 0, n) {
			getline(cin, line);
			int vs = line.find(" vs. ");
			int it = vs - 1;
			while (line[it] != ' ') it--;
			string team1 = line.substr(0, it);
			int goals1 = stoi(line.substr(it + 1, vs - it - 1));
			it = vs + 5;
			while (line[it] != ' ') it++;
			string team2 = line.substr(it + 1, SZ(line) - it - 1);
			int goals2 = stoi(line.substr(vs + 5, it - vs - 5));
			if (mapper.count(team1) == 0)
				mapper[team1] = m++;
			if (mapper.count(team2) == 0)
				mapper[team2] = m++;
			int id1 = mapper[team1];
			int id2 = mapper[team2];
			input[i] = iiii(id1, goals1, goals2, id2);
			names[id1] = team1; names[id2] = team2;
			scored[id1] += goals1; against[id1] += goals2;
			scored[id2] += goals2; against[id2] += goals1;
			visitor[id2] += goals2;
			if (goals1 > goals2)
				points[id1] += 3;
			else if (goals2 > goals1)
				points[id2] += 3;
			else
				points[id1]++, points[id2]++;
		}
		vi order(m), place(m);
		fori(i, 0, m) order[i] = i;
		sort(order.begin(), order.end(), cmp);
		fori(i, 0, m)
			place[order[i]] = i;
		int paradox = 0;
		fori(i, 0, n) {
			int id1, g1, g2, id2;
			tie(id1, g1, g2, id2) = input[i];
			if (g1 > g2 && place[id2] < place[id1] || g2 > g1 && place[id1] < place[id2])
				paradox++;
		}
		cout << "The paradox occurs " << paradox << " time(s)." << endl;
		fori(i, 0, m)
			cout << i + 1 << ". " << names[order[i]] << endl;
	}
	return 0;
}
