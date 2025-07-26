#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int my_ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
    int h1, d1, t1;
    cin >> h1 >> d1 >> t1;
    int h2, d2, t2;
    cin >> h2 >> d2 >> t2;
    int cost1 = (my_ceil(h2, d1) - 1) * t1;
    int cost2 = (my_ceil(h1, d2) - 1) * t2;
    if (cost1 < cost2) cout << "player one" << endl;
    else if (cost2 < cost1) cout << "player two" << endl;
    else cout << "draw" << endl;
    return 0;
}