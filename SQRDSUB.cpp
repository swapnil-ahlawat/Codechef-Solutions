// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1], num[n+1], last=0;
        num[0]=0;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n; i++){
          if(a[i]%4==0){
            num[i]=i;
            last=i;
          }
          else if(a[i]%2==0){
            num[i]=last;
            last=i;
          }
          else{
            num[i]=1+num[i-1];
          }
        }
        long long int total=0;
        for(int i=1; i<=n; i++) total+=(long long int) num[i];
        cout<<total<<endl;
    }
    
    return 0;
} 