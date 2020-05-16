#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int total=0;
    while(t--){
        int n;
        cin>>n;
        int a[4][4]={0};
        for(int i=0; i<n; i++){
            char x;
            int y;
            cin>>x>>y;
            switch(y){
                case 12: a[(int)(x-'A')][0]++;
                        break;
                case 3: a[(int)(x-'A')][1]++;
                        break;
                case 6: a[(int)(x-'A')][2]++;
                        break;
                case 9: a[(int)(x-'A')][3]++;
                        break;
            }
        }
        int max1=-400;
        int perm1[]= {0,1,2,3};
        int perm2[]={25,50,75,100};
        do{
            do{
            int sum=0;
            if(a[perm1[0]][0]==0) sum-=100;
            else sum+=a[perm1[0]][0]*perm2[0];
            if(a[perm1[1]][1]==0) sum-=100;
            else sum+=a[perm1[1]][1]*perm2[1];
            if(a[perm1[2]][2]==0) sum-=100;
            else sum+=a[perm1[2]][2]*perm2[2];
            if(a[perm1[3]][3]==0) sum-=100;
            else sum+=a[perm1[3]][3]*perm2[3];
            max1=max(max1,sum);
            
        }while(next_permutation(perm1, perm1+4));
            }while(next_permutation(perm2, perm2+4));
        cout<<max1<<endl;
        total+=max1;
    }
    cout<<total;
    return 0;
    
}