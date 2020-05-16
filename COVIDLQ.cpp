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
        int cur=-1, temp;
        bool flag=false, one=false;
        for(int i=0; i<n; i++){
        	cin>>temp;
        	if(temp){
        		if(!one){
        			one=true;
        		}
        		else if(i-cur<6){
        			flag=true;
        		}
        		cur=i;
        	}
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
     } 
    
    return 0;
} 