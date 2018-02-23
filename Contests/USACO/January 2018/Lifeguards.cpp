/*
ID: yefri97
PROG: lifeguards
LANG: C++11
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int oo = 1e9;

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	int n; fin >> n;
	vector<iii> v(2 * n);
	fori(i, 0, n) {
		int a, b; fin >> a >> b; b--;
		v[2 * i] = iii(a, 0, i);
		v[2 * i + 1] = iii(b, 1, i);
	}
	sort(v.begin(), v.end());
	int acc = 0;
	vi sum(n);
	set<int> dict;
	for (int i = 0, prev, l; i < 2 * n; i++) {
		int curr, type, id;
		tie(curr, type, id) = v[i];
		if (type == 0) {
			if (dict.size() == 1) {
				int x = *dict.begin();
				sum[x] += curr - prev;
			}
			if (dict.size() == 0) {
				prev = curr;
				l = curr;
			}
			dict.insert(id);
		} else {
			if (dict.size() == 1) {
				int x = *dict.begin();
				sum[x] += curr - prev + 1;
				acc += curr - l + 1;
			}
			if (dict.size() == 2) {
				prev = curr + 1;
			}
			dict.erase(id);
		}
	}
	int x = *min_element(sum.begin(), sum.end());
	fout << acc - x << endl;
	return 0;
}