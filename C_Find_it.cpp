#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> vis(n,0);
    vector<int> res;
    int s=-1;
    vis[0]=1;
    int j=arr[0]-1,k=0;
    while(k<n){
        if(vis[j]==1){
            s=j;
            break;
        }
        vis[j]=1;
        j=arr[j]-1;
        k++;
    }
    if(s!=-1){
        res.push_back(s+1);
        int e=arr[s]-1;
        while(e!=s){
            res.push_back(e+1);
            e=arr[e]-1;
        }
    }
    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
