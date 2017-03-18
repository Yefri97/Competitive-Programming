/*
ID: yefri97
PROG: square
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin ("square.in");
    ofstream fout ("square.out");
    int xa1, ya1, xa2, ya2; fin >> xa1 >> ya1 >> xa2 >> ya2;
    int xb1, yb1, xb2, yb2; fin >> xb1 >> yb1 >> xb2 >> yb2;
    int dx = max(xa2, xb2) - min(xa1, xb1);
    int dy = max(ya2, yb2) - min(ya1, yb1);
    int len = max(dx, dy);
    fout << len * len << endl;
    return 0;
}