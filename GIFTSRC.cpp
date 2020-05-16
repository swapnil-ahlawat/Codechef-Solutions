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
        int n, x=0, y=0;
        cin>>n;
        char temp='x', inp;
        for(int i=0; i<n; i++){
        	cin>>inp;
        	if(inp=='L'||inp=='R'){
        		if(temp=='L'||temp=='R') continue;
        		else if(inp=='L') x--;
        		else x++;
        		temp=inp;
        	}
        	else{
        		if(temp=='U'||temp=='D') continue;
        		else if(inp=='D') y--;
        		else y++;
        		temp=inp;
        	} 
        }
        cout<<x<<' '<<y<<endl;
        
        
     } 
    
    return 0;
} 