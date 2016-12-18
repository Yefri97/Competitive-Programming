/*
ID: yefri.g1
PROG: beads
LANG: C++
*/
#include <bits/stdc++.h>
#define mod(n, m) ((n % m) + m) % m

using namespace std;

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int len; fin >> len;
    string line; fin >> line;
    int ans = -1;
    for (int i = 0; i < line.size(); i++) {
        int left = i, right = (i + 1) % len, cont = 0;
        vector<int> bs(len);
        char curr = 'w';
        while (!bs[right]) {
            if (curr == 'w') curr = line[right];
            else if (curr != line[right] && line[right] != 'w') break;
            bs[right] = 1;
            right = mod(right + 1, len);
            cont++;
        }
        curr = 'w';
        while (!bs[left]) {
            if (curr == 'w') curr = line[left];
            else if (curr != line[left] && line[left] != 'w') break;
            bs[left] = 1;
            left = mod(left - 1, len);
            cont++;
        }
        ans = max(ans, cont);
    }
    fout << ans << endl;
    return 0;
}