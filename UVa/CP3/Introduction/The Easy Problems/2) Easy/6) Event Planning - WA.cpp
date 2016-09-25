#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, b, h, w, p, wk;
    bool flag;
    vector<int> v;
    while(cin>>n>>b>>h>>w){
        while(h--){
            flag=true;
            cin>>p;
            for(int i=0; i<w; i++){
                cin>>wk;
                if(wk<n){
                    flag=false;
                }
            }
            if(flag){
                v.push_back(n*p);
            }
        }
        sort(v.begin(), v.end());
        if(b<v[0] || v.size()==0){
            cout<<"stay home"<<endl;
        }else{
            cout<<v[0]<<endl;
        }
        v.clear();
    }
    return 0;
}
