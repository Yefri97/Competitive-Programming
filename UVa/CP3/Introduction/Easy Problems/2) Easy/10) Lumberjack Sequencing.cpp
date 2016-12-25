#include<bits/stdc++.h>
using namespace std;

bool sToL(vector<int> v){
    for(int i=0; i<9; i++){
        if(v[i]>=v[i+1]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool lToS(vector<int> v){
    for(int i=0; i<9; i++){
        if(v[i]<=v[i+1]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    cout<<"Lumberjacks:"<<endl;
    int n;
    cin>>n;
    while(n--){
        vector<int> v(50);
        for(int i=0; i<10; i++){
            cin>>v[i];
        }
        if(sToL(v) || lToS(v)){
            cout<<"Ordered"<<endl;
        }else{
            cout<<"Unordered"<<endl;
        }
    }
    return 0;
}
