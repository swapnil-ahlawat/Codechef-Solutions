#include <bits/stdc++.h> 
using namespace std;


long long int mPow(int x,int n)
{
    if ( n == 0)
    return 1;
    long long int ans;
    ans = mPow(x,n/2);
    if (n%2)
    {
    return ans*ans*x;
    }
    else
    return ans*ans;
    
}
int loga(long long int x){
    int count=0;
    while(x!=1){
        x/=2;
        count++;
    }
    return count;
}
int main()
{
		int fib[60];
        fib[0]=0;
        fib[1]=1;
		for(int i=2; i<=60; i++){
			fib[i]=fib[i-1]+fib[i-2];
			fib[i]%=10;
		}
    
	int t;
	cin>>t;
	while(t){
		long long int n;
		cin>>n;
	    int ans= loga(n);
	    
// 		bool odd=false;
// 		if(ans%2){
// 		   odd =true;
// 		}
		//long long int powe=1;
		//for(int i=0; i<(ans/2); i++){
// 		    powe*=4;
// 		}

// 		if(odd){
// 		    powe*=2;
// 		}
        long long int final = (mPow(2, ans)%60);
		cout<<fib[(final-1)]<<endl;
		
		--t;
	}

}