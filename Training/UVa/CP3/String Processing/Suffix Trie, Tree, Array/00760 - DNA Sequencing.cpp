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

const int oo = 1e9;

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int first = 1;
	string a, b;
	while (cin >> a >> b) {
		if (!first) cout << endl; first = 0;
		a.push_back('$'); b.push_back('#');
		string c = a + b;
		int n = a.size(), m = b.size(), nm = c.size();
		SuffixArray sa(c);
		int maxLCP = -1;
		for (int i = 1; i < nm; i++) {
			int owner1 = (sa.SA[i] < nm - m - 1) ? 1 : 2;
			int owner2 = (sa.SA[i - 1] < nm - m - 1) ? 1 : 2;
			if (owner1 != owner2)
				maxLCP = max(maxLCP, sa.LCP[i]);
		}
		if (maxLCP > 0) {
			set<string> dict;
			for (int i = 1; i < nm; i++) {
				int owner1 = (sa.SA[i] < nm - m - 1) ? 1 : 2;
				int owner2 = (sa.SA[i - 1] < nm - m - 1) ? 1 : 2;
				if (owner1 != owner2 && sa.LCP[i] == maxLCP)
					dict.insert(c.substr(sa.SA[i], maxLCP));
			}
			for (string s : dict)
				cout << s << endl;
		} else {
			cout << "No common sequence." << endl;
		}
	}
	return 0;
}