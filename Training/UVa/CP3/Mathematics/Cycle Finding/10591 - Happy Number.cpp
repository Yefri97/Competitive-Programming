#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 100;

int process(int x) {
    int target = 0;
    while (x) {
        target += sq(x%10);
        x /= 10;
    }
    return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t, cs = 0; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> st;
        int x = n, ans = 1;
        while (x != 1) {
            x = process(x);
            if (st.find(x) != st.end()) { ans = 0; break; }
            st.insert(x);
        }
        cout << "Case #" << ++cs << ": " << n << " is " << (ans ? "a Happy" : "an Unhappy") << " number." << endl;
    }
	return 0;
}