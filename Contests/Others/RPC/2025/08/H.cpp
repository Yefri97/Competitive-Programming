#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    set<ii> dict;
    vector<int> degree(n), freq(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dict.insert(ii(a, b));
        degree[b]++;
    }
    for (int i = 0; i < n; i++) freq[degree[i]]++;
    // for (int i = 0; i < n; i++) cout << freq[i] << " "; cout << endl;
    cout << (freq[0] == 1 && freq[1] == n - 1 ? "DA" : "NE") << endl;
    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (!dict.count(ii(a, b))) swap(a, b);
        // assert(dict.count(ii(a, b)) == 1);
        // Decrease degree[a]
        freq[degree[b]]--;
        degree[b]--;
        freq[degree[b]]++;
        // Increase degree[a]
        freq[degree[a]]--;
        degree[a]++;
        freq[degree[a]]++;
        // Remove and insert swapped change
        dict.erase(ii(a, b));
        dict.insert(ii(b, a));
        cout << (freq[0] == 1 && freq[1] == n - 1 ? "DA" : "NE") << endl;
    }
    return 0;
}