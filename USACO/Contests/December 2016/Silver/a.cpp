/*
ID: yefri97
PROG: haybales
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000, INF = 1000000001;
int *pos_a, *pos_b, arr[MAXN + 10];

int main() {
    ifstream fin ("haybales.in");
    ofstream fout ("haybales.out");
    int n, q; fin >> n >> q;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    arr[n] = INF; n++;
    sort(arr, arr + n);
    while (q--) {
        int a, b; fin >> a >> b;
        pos_a = lower_bound(arr, arr + n, a);
        pos_b = lower_bound(arr, arr + n, b);
        int pa = pos_a - arr, pb = pos_b - arr;
        if (arr[pb] != b) pb--;
        fout << pb - pa + 1 << endl;
    }
    return 0;
}