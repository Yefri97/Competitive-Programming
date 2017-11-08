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

const int oo = 1e9, MX = 100010;

int owner[MX];

struct SuffixArray {
	string T;
	vi SA, RA, LCP;

	void computeLCP() {
		int n = T.size();
		LCP.assign(n, 0);
		vi Phi(n), PLCP(n);
		Phi[SA[0]] = -1;
		for (int i = 1; i < n; i++)
			Phi[SA[i]] = SA[i - 1];
		for (int i = 0, L = 0; i < n; i++) {
			if (Phi[i] == -1) { PLCP[i] = 0; continue; }
			while (T[i + L] == T[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max(L - 1, 0);
		}
		for (int i = 0; i < n; i++)
			LCP[i] = PLCP[SA[i]];
	}

	void countingSort(int k) {
		int n = T.size(), maxi = max(300, n);
		vi c(maxi);
		for (int i = 0; i < n; i++)
			c[i + k < n ? RA[i + k] : 0]++;
		for (int i = 0, sum = 0; i < maxi; i++) {
			int t = c[i];
			c[i] = sum;
			sum += t;
		}
		vi tempSA(n);
		for (int i = 0; i < n; i++)
			tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
		for (int i = 0; i < n; i++)
			SA[i] = tempSA[i];
	}

	SuffixArray(string _T) { T = _T;
		int n = T.size();
		for (int i = 0; i < n; i++) RA.push_back(T[i]);
		for (int i = 0; i < n; i++) SA.push_back(i);
		for (int k = 1; k < n; k <<= 1) {
			countingSort(k);
			countingSort(0);
			vi tempRA(n);
			int r = 0;
			tempRA[SA[0]] = 0;
			for (int i = 1; i < n; i++)
				tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			for (int i = 0; i < n; i++)
				RA[i] = tempRA[i];
			if (RA[SA[n - 1]] == n - 1) break;
		}
		computeLCP();
	}

};

bool check(SuffixArray& sa, int k, int m) {
	int n = sa.LCP.size();
	fori(i, m, n) {
		while (i < n && sa.LCP[i] < k) i++;
		if (i == n) return false;
		set<int> dict;
		dict.insert(owner[sa.SA[i - 1]]);
		while (i < n && k <= sa.LCP[i]) {
			dict.insert(owner[sa.SA[i]]);
			i++;
		}
		if ((int)dict.size() > (m >> 1)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int first = 1;
	int m;
	while (cin >> m && m) {
		if (!first) cout << endl; first = 0;
		string T;
		int n = 0;
		fori(i, 0, m) {
			string s; cin >> s; s.push_back(i + 1);
			fori(j, 0, (int)s.size())
				owner[n++] = i;
			T += s;
		}
		if (m == 1) { cout << T.substr(0, T.size() - 1) << endl; continue; }
		SuffixArray sa(T);
		if (check(sa, 1, m)) {
			int lo = 1, hi = n;
			while (hi - lo > 1) {
				int mid = (hi + lo) >> 1;
				if (check(sa, mid, m))
					lo = mid;
				else
					hi = mid;
			}
			int maxLCP = lo;
			fori(i, m, n) {
				while (i < n && sa.LCP[i] < maxLCP) i++;
				set<int> dict;
				dict.insert(owner[sa.SA[i - 1]]);
				while (i < n && maxLCP <= sa.LCP[i]) {
					dict.insert(owner[sa.SA[i]]);
					i++;
				}
				if ((int)dict.size() > (m >> 1))
					cout << T.substr(sa.SA[i - 1], maxLCP) << endl;
			}
		} else {
			cout << "?" << endl;
		}
	}
	return 0;
}