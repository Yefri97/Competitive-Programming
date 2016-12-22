/*
ID: yefri.g1
PROG: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

vvc reflection(vvc board) {
    vvc target = board;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            target[i][board.size() - j - 1] = board[i][j];
        }
    }
    return target;
}


vvc rotate_90(vvc board) {
    vvc target = board;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            target[j][board.size() - i - 1] = board[i][j];
        }
    }
    return target;
}

vvc rotate_180(vvc board) {
    return rotate_90(rotate_90(board));
}

vvc rotate_270(vvc board) {
    return rotate_90(rotate_180(board));
}

int main() {
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    int n; fin >> n;
    vvc init(n, vector<char>(n)), target(n, vector<char>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            fin >> init[i][j];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            fin >> target[i][j];
    if (rotate_90(init) == target)
        fout << 1 << endl;
    else if (rotate_180(init) == target)
        fout << 2 << endl;
    else if (rotate_270(init) == target)
        fout << 3 << endl;
    else if (reflection(init) == target)
        fout << 4 << endl;
    else if (rotate_90(reflection(init)) == target || 
            rotate_180(reflection(init)) == target ||
            rotate_270(reflection(init)) == target)
        fout << 5 << endl;
    else if (init == target)
        fout << 6 << endl;
    else
        fout << 7 << endl;
    return 0;
}