#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int i, flag=1;
    string cad, cadR;
    while(getline(cin, cad)){
        for(i=0; i<cad.size(); i++){
            if(cad[i] == '"'){
                if(flag == 1){
                    cadR.push_back('`');
                    cadR.push_back('`');
                    flag=2;
                }else{
                    cadR.push_back('\'');
                    cadR.push_back('\'');
                    flag=1;
                }
            }else{
                cadR.push_back(cad[i]);
            }
        }
        cout<<cadR<<endl;
        cadR.erase(cadR.begin(), cadR.end());
    }
    return 0;
}
