#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int a[n], b[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
       // int size= sizeof(a)/sizeof(a[0]);   
        sort(a, a+n);
        sort(b,b+n);
        long long int sum=0;
        for(int i=0; i<n; i++){
            if(a[i]<b[i]) sum+=a[i];
            else sum+=b[i];
        }
        cout<<sum<<endl;
        
    }
	return 0;
}
