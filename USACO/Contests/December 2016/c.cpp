/*
ID: yefri97
PROG: cowsignal
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
char input[MAXN + 10][MAXN + 10], target[MAXN * MAXN + 10][MAXN * MAXN + 10];

int main() {
    ifstream fin ("cowsignal.in");
    ofstream fout ("cowsignal.out");
    int n, m, k; fin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> input[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c = input[i][j];
        for (int a = 0; a < k; a++) for (int b = 0; b < k; b++)
            target[k * i + a][k * j + b] = c;
    }
    for (int i = 0; i < k * n; i++) {
        for (int j = 0; j < k * m; j++) fout << target[i][j];
        fout << endl;
    }
    return 0;
}