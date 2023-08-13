#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define pb push_back
#define F 1000000007
#define S second
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
template <typename T>
ostream &operator<<(ostream &os, vector<T> &intermediate_array)
{
    for (auto &a : intermediate_array)
        cout << a << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &intermediate_array)
{
    for (auto &a : intermediate_array)
        cin >> a;
    return is;
}

bool check(int m,int k,int n,int arr[]){
    for(int i=0;i<n;i++){
        long long t=0;
        for(int j=i;j<n;j++){
            if(arr[j]+(j-i)>=m)return true;
            t+=(m-(j-i)-arr[j]);
            if(t>k)break;
        }
    }
    return false;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long s=0,e=1e9,ans=0;
    while(s<=e){
        int m=s+(e-s)/2;
        if(check(m,k,n,arr)){
            s=m+1;
            ans=m;
        }
        else e=m-1;
    }
    cout<<ans<<"\n";    
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}