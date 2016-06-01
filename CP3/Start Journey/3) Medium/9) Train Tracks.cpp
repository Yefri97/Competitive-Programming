#include<bits/stdc++.h>
using namespace std;

int get_int() {
    string s;
    getline(cin, s);
    return atoi(s.c_str());
}


int main () {
    int N = get_int();
    while (N--) {
        int female = 0, male = 0;
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if ((i+1)%3) {
                if(s[i] == 'F') {
                    female++;
                } else {
                    male++;
                }
            }
        }
        if (female == male) {
            cout<<"LOOP"<<endl;
        } else {
            cout<<"NO LOOP"<<endl;
        }
    }
    return 0;
}
