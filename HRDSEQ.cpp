#include<iostream>
using namespace std;


int main(){
	int inf[200]={0};
	int arr[200]={0};
	arr[0]=1;
	for(int i=1; i<128; i++){
		if(arr[inf[i-1]]==1){
			inf[i]=0;
			arr[0]++;
		}
		else{
			for(int j=i-2;j>=0;j--){
				if(inf[j]==inf[i-1]){
					inf[i]=i-j-1;
					arr[inf[i]]++;
					break;
				}
			}
		}
	}

	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		int count=0;
		for(int i=0; i<n; i++){
		    if(inf[i]==inf[n-1])count++;
		}
		cout<<count<<endl;
		count=0;
	
	t--;
	}
}
