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
void build(vector<ll>& node,vector<ll>& arr,ll s,ll e,ll cur){
    if(s==e){
        node[cur]=arr[s];
        return;
    }
    ll m=s+(e-s)/2;
    build(node,arr,s,m,2*cur);
    build(node,arr,m+1,e,2*cur+1);
    node[cur]=min(node[2*cur],node[2*cur+1]);
}
int mini(vector<ll>& node,ll b,ll c,ll s,ll e,ll cur){
    if(s>=b && e<=c)return node[cur];
    if(e<b || s>c)return 1e9+1;
    ll m=s+(e-s)/2;
    return min(mini(node,b,c,s,m,2*cur),mini(node,b,c,m+1,e,2*cur+1));
}
void update(vector<ll>& node,vector<ll>& arr,ll b,ll c,ll s,ll e,ll cur){
    if(s==e){
        node[cur]=c;
        arr[b]=c;
        return;
    }
    ll m=s+(e-s)/2;
    if(b<=m)
        update(node,arr,b,c,s,m,2*cur);
    else
        update(node,arr,b,c,m+1,e,2*cur+1);
    node[cur]=min(node[2*cur],node[2*cur+1]);
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    arr.push_back(0);
    vector<ll> node(4*n+1);
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    build(node,arr,1,n,1);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(node,arr,b+1,c,1,n,1);
        }
        else cout<<mini(node,b+1,c,1,n,1)<<"\n";
    }
}
int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}