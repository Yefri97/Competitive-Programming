#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin>>N;
	for (int n = 0; n < N; ++n) {
		vector<int> v(52);
		vector<string> vs(52);
		for (int i = 0; i < v.size(); ++i) {
			string s; cin>>s;
			vs[i] = s;
			int value = atoi(s.substr(0, 1).c_str());
			v[i] = (value)? value : 10;
		}
		int cont_card = 0, cont_y = 0;
		for (int i = 0; i < 3; ++i) {
			cont_y += v[24 - cont_card];
			cont_card += 1 + (10 - v[24 - cont_card]);
		}
		cout << "Case " <<n + 1<< ": " << vs[cont_y + cont_card - 1] << endl;
	}
	return 0;
}