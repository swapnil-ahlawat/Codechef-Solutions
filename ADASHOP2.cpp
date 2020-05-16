#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int r, c;
    int m=25;
    while(t--){
        cin>>r>>c;
        if(r!=c){
            cout<<m+2<<'\n';
            cout<<(r+c)/2<<' '<<(r+c)/2<<'\n';
            cout<<'1'<<' '<<'1'<<'\n';
        }
        else if(r==c and r!=1){
            cout<<m+1<<'\n';
            cout<<'1'<<' '<<'1'<<'\n';
        }
        else cout<<m<<'\n';
        r=1;
        int i=1;
        while(i<=3){
            cout<<r+i<<' '<<r+i<<'\n';
            cout<<r<<' '<<r+(2*i)<<'\n';
            cout<<r+(2*i)<<' '<<r<<'\n';
            cout<<r+i<<' '<<r+i<<'\n';
            i++;
        }
        r=4;
        i=1;
        while(i<=3){
            cout<<r+i<<' '<<r+i<<'\n';
            cout<<'8'<<' '<<2*i<<'\n';
            cout<<2*i<<' '<<'8'<<'\n';
            cout<<r+i<<' '<<r+i<<'\n';
            i++;
        }
        cout<<'8'<<' '<<'8'<<'\n';
        
        
    }
}