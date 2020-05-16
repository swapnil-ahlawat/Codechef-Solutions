// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n+1];
        unordered_map<int, int> umap;
        vector<vector<int>> v;
        vector<int> l1, l2;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            umap[a[i]]=i;
        }
        int count=0, i1, i2, i3, temp;
        bool flag=false;
        for(int i=1; i<=n; i++){
            if(i!=a[i] && a[i]!=-1){
                i1= i;
                i2= a[i];
                i3= umap[i];
                if(i2==i3){
                    l1.push_back(i1);
                    l2.push_back(i2);
                    a[i2]=-1;
                    continue;
                }
                count++;
                v.push_back({i1, i2, i3});
                umap[a[i1]]=i2;
                umap[a[i2]]=i3;
                umap[a[i3]]=i1;
                temp=a[i3];
                a[i3]=a[i2];
                a[i2]=a[i1];
                a[i1]=temp;

            }
            
        }
       
        if(l1.size()&1) {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0; (i+1)<l1.size(); i+=2){
            i1=l1[i];
            i2=l1[i+1];
            i3=l2[i];
            count++;
            v.push_back({i1, i2, i3});
            i1=i3;
            i2=l2[i+1];
            i3=l1[i+1];
            count++;
            v.push_back({i1, i2, i3});
        }
        
        cout<<count<<endl;
        for(int i=0; i<v.size(); i++){
            cout<<v[i][0]<<' '<<v[i][1]<<' '<<v[i][2]<<endl;
        }
     } 
    
    return 0;
} 