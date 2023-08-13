#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>t;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            t[arr[i]]++;
        }
        map<int,int> mp;
        for(auto it:t){
            int k=1;
            int j=k*(it.first);
            while(j<=n){
                mp[j]+=it.second;
                k++;
                j=k*(it.first);
            }
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        cout<<ans<<"\n";
    }
}