#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	int n=0,m=0;
	while (T){
	    cin>>n>>m;
	    char a[n][m];
	   
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>a[i][j];
	        }
	    }
	   
	   int imin=1001, imax=-1, jmin=1001, jmax=-1;
	  
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	     
	    if(a[i][j]=='*'){
	    if(jmin>j){
	        jmin=j;
	    break;}
	        }
	        }
	         for(int j=0; j<m; j++){
	     
	    if(a[i][j]=='*'){
	    if(jmax<j){
	    jmax=j;
	        }
	    }
	        }
	    }
	    
	    for(int j=0; j<m; j++){
	        for(int i=0; i<n; i++){
	     
	    if(a[i][j]=='*'){
	    if(imin>i){
	    imin=i;
	    break;
	        }
	    }
	        }
	        for(int i=0; i<n; i++){
	     
	    if(a[i][j]=='*'){
	    if(imax<i){
	    imax=i;
	    }
	        }
	        }
	    }
	    
	  
	    int imean=0, jmean=0;
	    imean=(imin+imax)/2;
	    jmean=(jmin+jmax)/2;
	    int diff,e,b,c,d;
	    e=imean-imin;
	    b=imax-imean;
	    c=jmean-jmin;
	    d=jmax-jmean;
	   diff=e;
	   if(diff<b)
	   diff=b;
	   if(diff<c)
	   diff<c;
	   if(diff<d)
	   diff=d;
	   
	   if(diff<0)
	   cout<<0<<endl;
	   else
	   cout<<diff+1<<endl;
	    T--;
	}
	return 0;
}
