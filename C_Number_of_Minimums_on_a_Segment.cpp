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
void build(vector<pair<ll,ll>>& node,vector<ll>& arr,ll s,ll e,ll cur){
    if(s==e){
        node[cur].first=arr[s];
        node[cur].second=1;
        return;
    }
    ll m=s+(e-s)/2;
    build(node,arr,s,m,2*cur);
    build(node,arr,m+1,e,2*cur+1);
    if(node[2*cur].first<node[2*cur+1].first){
        node[cur].first=node[2*cur].first;
        node[cur].second=node[2*cur].second;
    }
    else if(node[2*cur].first>node[2*cur+1].first){
        node[cur].first=node[2*cur+1].first;
        node[cur].second=node[2*cur+1].second;
    }
    else{
        node[cur].first=node[2*cur+1].first;
        node[cur].second=node[2*cur+1].second+node[2*cur].second;
    }
}
pair<ll,ll> mini(vector<pair<ll,ll>>& node,ll b,ll c,ll s,ll e,ll cur){
    if(s>=b && e<=c){
        pair<int,int> res;
        res.first=node[cur].first;
        res.second=node[cur].second;
        return res;
    }
    if(e<b || s>c)return {1e15,0};
    ll m=s+(e-s)/2;
    pair<ll,ll> r;
    pair<ll,ll> r1=mini(node,b,c,s,m,2*cur);
    pair<ll,ll> r2=mini(node,b,c,m+1,e,2*cur+1);
    if(r1.first<r2.first){
        r.first=r1.first;
        r.second=r1.second;
    }
    else if(r1.first>r2.first){
        r.first=r2.first;
        r.second=r2.second;
    }
    else{
        r.first=r1.first;
        r.second=r1.second+r2.second;
    }
    return r;
}
void update(vector<pair<ll,ll>>& node,vector<ll>& arr,ll b,ll c,ll s,ll e,ll cur){
    if(s==e){
        node[cur].first=c;
        node[cur].second=1;
        arr[b]=c;
        return;
    }
    ll m=s+(e-s)/2;
    if(b<=m)
        update(node,arr,b,c,s,m,2*cur);
    else
        update(node,arr,b,c,m+1,e,2*cur+1);
    if(node[2*cur].first<node[2*cur+1].first){
        node[cur].first=node[2*cur].first;
        node[cur].second=node[2*cur].second;
    }
    else if(node[2*cur].first>node[2*cur+1].first){
        node[cur].first=node[2*cur+1].first;
        node[cur].second=node[2*cur+1].second;
    }
    else{
        node[cur].first=node[2*cur+1].first;
        node[cur].second=node[2*cur+1].second+node[2*cur].second;
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    arr.push_back(0);
    vector<pair<ll,ll>> node(4*n+1);
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
        else{
            pair<ll,ll> ans;
            ans=mini(node,b+1,c,1,n,1);
            cout<<ans.first<<" "<<ans.second<<"\n";
        }
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