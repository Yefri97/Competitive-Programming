#include <bits/stdc++.h>
using namespace std;

const int MN = 100010;

long long c[MN];

void gen() {
    for (int i = 1; i < MN; i++)
        c[i] = i + c[i - 1];
}

int main() {
    gen();
    long long n, k; cin >> n >> k;
    int x = upper_bound(c, c + MN, k) - c - 1;
    vector<int> ans;
    for (int i = 1; i < n - x; i++)
        ans.push_back(i);
    for (int i = n; i >= n - x; i--)
        ans.push_back(i);
    for (int i = 0, idx = n - x - 2; i < k - c[x]; i++)
        swap(ans[idx], ans[n - i - 1]);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}