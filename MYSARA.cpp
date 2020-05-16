// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

unsigned long long int power(unsigned int y) 
{ 
    if (y==0) 
        return 1; 
    else if (y%2==0) 
        return power(y/2)*power(y/2); 
    else
        return 2*power(y/2)*power(y/2); 
} 

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
        unsigned long long int b[n];
        for(int i=0; i<n; i++) cin>>b[i];
      	unsigned long long int diff, num, ans=1, check;
      	unsigned int bits;
      	bool flag=true;
        for(int i=1; i<n; i++){
        	check=b[i]&b[i-1];
        	if(check!=b[i-1]){
        		flag=false;
        		break;
        	}
        	diff=b[i]-b[i-1];
        	num= diff^b[i];
        	bits=__builtin_popcountll(num);
        	ans*=power(bits);
        	ans%=1000000007;

        }
        if(flag)
       		cout<<ans%1000000007<<endl;
       	else cout<<0<<endl;
     } 
    
    return 0;
} 