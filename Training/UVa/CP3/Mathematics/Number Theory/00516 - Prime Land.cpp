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

const int oo = 1e9, k = 1000;

bitset<k + 10> bs;
vi primes;

void sieve(int sz) {
	bs.set();
	for (int i = 2; i <= sz; i++) if (bs[i]) {
		for (int j = i * i; j <= sz; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

vii primeFactors(int n) {
	int idx = 0, pf = primes[idx];
	vii ans;
	while (pf * pf <= n) {
		int power = 0;
		while (n % pf == 0) { n /= pf; power++; }
		if (power)
			ans.push_back(ii(pf, power));
		pf = primes[++idx];
	}
	if (n != 1) ans.push_back(ii(n, 1));
	return ans;
}

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(k);
	string line;
	while (getline(cin, line) && line.size() > 1) {
		vector<string> vs = splitLine(line);
		int n = 1;
		for (int i = 0; i < (int)vs.size(); i += 2)
			n *= (int)pow(atoi(vs[i].c_str()), atoi(vs[i + 1].c_str()));
		vii pfs = primeFactors(n - 1);
		reverse(pfs.begin(), pfs.end());
		cout << pfs[0].first << " " << pfs[0].second;
		fori(i, 1, (int)pfs.size())
			cout << " " << pfs[i].first << " " << pfs[i].second;
		cout << endl;
	}
	return 0;
}