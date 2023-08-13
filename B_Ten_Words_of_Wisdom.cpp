#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0,in=0;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if(a<=10){
                if(b>ans){
                    ans=b;
                    in=i+1;
                }
            }
        }
        cout<<in<<"\n";
    }
    return 0;
}