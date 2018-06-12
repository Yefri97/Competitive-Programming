#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 2000000;

bitset<MX> bs;
vi pf[MX];
set<int> used;

void sieve() {
  bs.set();
  for (ll i = 2; i < MX; i++) if (bs[i]) {
    pf[i].push_back(i);
    for (ll j = i + i; j < MX; j += i) {
      bs[j] = 0;
      pf[j].push_back(i);
    }
  }
}

bool can(int x) {
  for (int p : pf[x])
    if (used.count(p))
      return false;
  return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
	int n; cin >> n;
  vi v(n);
  fori(i, 0, n) cin >> v[i];
  int pos = 0;
  for (int x : v) {
    if (!can(x)) break;
    for (int p : pf[x]) used.insert(p);
    pos++;
  }
  if (pos < n) {
    while (!can(v[pos])) v[pos]++;
    for (int p : pf[v[pos]]) used.insert(p);
    int curr = 2;
    fori(i, pos + 1, n) {
      while (!bs[curr] || used.count(curr)) curr++;
      used.insert(curr);
      v[i] = curr;
    }
  }
  fori(i, 0, n)
    cout << v[i] << " ";
  cout << endl;
	return 0;
}
