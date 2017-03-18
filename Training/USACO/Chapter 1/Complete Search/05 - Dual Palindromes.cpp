/*
ID: yefri.g1
PROG: dualpal
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

string dec_to_base(string s, int b) {
    string target = "";
    for (int i = atoi(s.c_str()); i; i /= b) {
        char c = (i % b > 9)? ((i % b) - 10) + 'A' : (i % b) + '0'; 
        target = c + target;
    }
    return target;
}

int main() {
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");
    int n, s; fin >> n >> s;
    int cont = 0, k = s + 1;
    while (cont < n) {
        int acc = 0;
        for (int i = 2; i <= 10; i++) {
            acc += is_palindrome(dec_to_base(to_string(k), i));
        }
        if (acc >= 2) {
            fout << k << endl;
            cont++;
        }
        k++;
    }
    return 0;
}