/*
ID: yefri97
PROG: citystate
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> ii;

int main() {
    ifstream fin ("citystate.in");
    ofstream fout ("citystate.out");
    multiset<ii> s;
    int n; fin >> n;
    while (n--) {
        string a, b; fin >> a >> b;
        ii curr = ii(a.substr(0, 2), b);
        if (curr.first != curr.second) s.insert(curr);
    }
    int ans = 0;
    for (multiset<ii>::iterator it = s.begin(); it != s.end(); it++) {
        ii curr = *it;
        ans += s.count(ii(curr.second, curr.first));
    }
    fout << ans / 2 << endl;
    return 0;
}