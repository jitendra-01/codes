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

void solve()
{
    int n;
    cin>>n;
    int l=n*(n-1)/2;
    int arr[l];
    map<int,int> mp;
    int m=-INT_MAX;
    for(int i=0;i<l;i++){
        cin>>arr[i];
        mp[arr[i]]++;
        m=max(m,arr[i]);
    }
    int c=n-1;
    vector<int> res;
    for(auto i:mp){
        while(i.second!=0){
            cout<<i.first<<" ";
            i.second-=c;
            c--;
        }
    }
    cout<<m<<"\n";
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