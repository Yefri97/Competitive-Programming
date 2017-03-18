/*
ID: yefri.g1
PROG: namenum
LANG: C++
*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string> dict, ans;
string bn, pn;

char cell[12][5] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'},
                    {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'},
                    {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

void solver(int id) {
    if (id == bn.size()) {
        if (binary_search(dict.begin(), dict.end(), pn))
            ans.push_back(pn);
        return;
    }
    int k = bn[id] - '0';
    for (int i = 0; i < 3; i++) {
        pn[id] = cell[k - 2][i];
        solver(id + 1);
    }
}

int main() {
    ifstream gin ("dict.txt");
    string name;
    while (gin >> name) {
        dict.push_back(name);
    }

    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    fin >> bn;
    pn.assign(bn.size(), '*');
    solver(0);

    if (ans.size()) {
        for (int i = 0; i < ans.size(); i++)
            fout << ans[i] << endl;
    } else {
        fout << "NONE" << endl;
    }

    return 0;
}