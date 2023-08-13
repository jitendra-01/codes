#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        map<long long int,long long int>m1,m2,m3,m4,m5;
        long long int ans=0;
        vector<pair<long long int,long long int>> a(n,{0,0});
        for(long long int i=0;i<n;i++){
            long long int x,y;
            cin>>x>>y;
            a[i].first=x;
            a[i].second=y;
            m1[x]++;
            m2[y]++;
            m3[(x-y)]++;
            m4[(x+y)]++;
        }
        for(long long int i=0;i<n;i++){
            long long int x=a[i].first;
            long long int y=a[i].second;
            ans+=m1[x]-1+m2[y]-1+m3[(x-y)]-1+m4[x+y]-1;
        } 
        cout<<ans<<"\n";
    }
}