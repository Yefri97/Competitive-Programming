#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ranking1(n), points(n);
    for (int i = 0; i < n; i++) {
        cin >> ranking1[i];
        ranking1[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    vector<int> ranking2(n);
    for (int i = 0; i < n; i++) ranking2[i] = i;
    sort(ranking2.begin(), ranking2.end(), [&points](int a, int b) {
        return points[a] > points[b];
    });
    // for (int i = 0; i < n; i++) cout << ranking1[i] << " "; cout << endl;
    // for (int i = 0; i < n; i++) cout << ranking2[i] << " "; cout << endl;
    vector<int> total(n);
    for (int i = 0; i < n; i++) total[ranking1[i]] += (n - i);
    for (int i = 0; i < n; i++) total[ranking2[i]] += (n - i);
    vector<int> final_ranking(n);
    for (int i = 0; i < n; i++) final_ranking[i] = i;
    sort(final_ranking.begin(), final_ranking.end(), [&total, &points](int a, int b) {
        if (total[a] == total[b]) return points[a] > points[b];
        return total[a] > total[b];
    });
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Kod";
        int id = final_ranking[i];
        if (id + 1 < 10) cout << "0" << id + 1;
        else cout << id + 1;
        cout << " (" << total[id] << ")" << endl;
    }
    return 0;
}