#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y){
    if(y%4==0){
        if(y%100==0){
            if(y%400==0) return true;
        }
        else return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    int m1, m2, y1,y2;
    vector<int> req;
    int i=1;
    int  day=4;
    while(i!=401){
        if(day==6){
            req.push_back(i);
        }
        else if(day==7 and (!isLeap(i))){
            req.push_back(i);
        }
        if(isLeap(i)){
            day= (day+2)%7;
            if(day==0) day=7;
        }
        else{
            day= (day+1)%7;
            if(day==0) day=7;
        }
        i++;
    }
    // for(int i=0; i<req.size(); i++){
    //     cout<<req[i]<<endl;
    // }
    while(t--){
        cin>>m1>>y1>>m2>>y2;
        if(m1>2) y1++;
        if(m2<2) y2--;
        int div1=y1%400;
        int div2= y2%400;
        int ans=0;
        if(y2<y1){
            cout<<0<<endl;
            continue;
        }
        if(y2-y1<400 and div1<=div2){
            for(int i=0; i<req.size(); i++){
                if(req[i]<div1) continue;
                else if(req[i]>div2) break;
                else ans++;
                //cout<<"reach"<<endl;
            }
        }
        else{
            for(int i=0; i<req.size(); i++){
                if(req[i]<div1) continue;
                else ans++;
            
            }
            for(int i=0; i<req.size(); i++){
                if(req[i]>div2) break;
                else ans++;
            }
            y1=((y1/400)+1)*400;
            //y2=((y2/400)-1)*400;
            ans += req.size()*((y2-y1)/400);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}