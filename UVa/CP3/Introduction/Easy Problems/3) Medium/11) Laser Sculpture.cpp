#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int A, C;
	while (cin>>A>>C && A) {
		int target = 0;
		vector<int> v;
		for (int i = 0; i < C; i++) {
			int n; cin>>n;
			v.push_back(n);
		}
		v.push_back(A);
		for (int i = 0; i < C; i++) {
			if (v[i+1] > v[i]) {
				target += (v[i+1] - v[i]);
			}
		}
		cout<<target<<endl;
	}
	return 0;
}