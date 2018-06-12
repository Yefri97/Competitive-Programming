#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    set<int> dict;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            dict.insert(v[i] + v[j]);
    cout << (int)dict.size() << endl;
    return 0;
}