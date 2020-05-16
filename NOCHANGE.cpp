#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        int den[n][2];
        for(int i=0; i<n; i++){
            cin>>den[i][0];
            den[i][1]=0;
        }
        bool flag=false;
        for(int i=n-1; i>=0; i--){
            if(p%den[i][0]){
               den[i][1]= p/den[i][0]+1;
               flag=true;
               break;
            }
            else{
                int temp=p/den[i][0];
                if(temp==0)continue;
                temp--;
                den[i][1]=temp;
                p-=temp*den[i][0];
            }
            
        }
        if(flag){
            cout<<"YES ";
            for(int i=0; i<n; i++){
                cout<<den[i][1]<<" ";
            }
            cout<<endl;
        }
        else cout<<"NO "<<endl;
        
    }
    
	// your code goes here
	return 0;
}
