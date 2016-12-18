/*
ID: yefri.g1
PROG: friday
LANG: C++
*/
#include <bits/stdc++.h>
#define isLeap(x) (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))

using namespace std;

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");
    vector<int> ans(7);
    int n; fin >> n;
    for (int day = 0, year = 1900; year < 1900 + n; year++) {
        for (int i = 0; i < 12; i++) {
            ans[day]++;
            int val = (isLeap(year) && i == 1)? 29 : month[i];
            day = (day + val) % 7;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i) fout << " ";
        fout << ans[i];
    }
    fout << endl;
    return 0;
}