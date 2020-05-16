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
        int a[n], i=0, years=n-1;
        for(; i<n; i++) cin>>a[i];
        sort(a, a+n);
        long long int total=0, mod=1e9 +7;

        for(i=0; i<n; i++){
            if((a[i]-years)>0){
            total+=(long long int) (a[i]-years)%mod;
            total%=mod;
            }
            years--;
        }

        cout<<total<<endl;
        
     } 
    
    return 0;
} 