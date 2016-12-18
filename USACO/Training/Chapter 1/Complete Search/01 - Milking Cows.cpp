/*
ID: yefri.g1
PROG: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> ii;

int main() {
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");
    vector<ii> v;
    int n; fin >> n;
    while (n--) {
    	int a, b; fin >> a >> b;
    	v.push_back(ii(a, 'i'));
    	v.push_back(ii(b, 'o'));
    }
    sort(v.begin(), v.end());
    int ans_a = 0, ans_b = 0;
    int t = v[0].first, cont = 1;
    for (int i = 1; i < v.size(); i++) {
    	if (v[i].second == 'i') {
    		if (cont == 0) {
    			ans_b = max(ans_b, v[i].first - t);
    			t = v[i].first;
    		}
    		cont++;
    	} else {
    		cont--;
    		if (cont == 0) {
    			ans_a = max(ans_a, v[i].first - t);
    			t = v[i].first;
    		}
    	}
    }
    fout << ans_a << " " << ans_b << endl;
    return 0;
}