/*
ID: yefri97
PROG: blocks
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> foo(string a, string b) {
	vector<int> va(26), vb(26), target(26);
	for (int i = 0; i < a.size(); i++)
		va[a[i] - 'a']++;
	for (int i = 0; i < b.size(); i++)
		vb[b[i] - 'a']++;
	for (int i = 0; i < va.size(); i++)
		target[i] = max(va[i], vb[i]);
	return target;
}

int main() {
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    vector<int> ans(26);
    int n; fin >> n;
    while (n--) {
    	string a, b; fin >> a >> b;
    	vector<int> v = foo(a, b);
    	for (int i = 0; i < v.size(); i++)
    		ans[i] += v[i];
    }
    for (int i = 0; i < ans.size(); i++)
    	fout << ans[i] << endl;
    return 0;
}