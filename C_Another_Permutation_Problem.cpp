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
    long long int ans=0;
    for(int i=1;i<=n;i++){
        long long int t=0,j=1;
        for(j=1;j<=n-i;j++){
            t+=(j*j);
            // cout<<t<<" ";
        }
        long long int t1=0,l=0;
        for(int k=j;k<=n;k++){
            t+=(k*(n-l));
            t1=max(t1,(k*(n-l)));
            l++;
        }
        t=t-t1;
        ans=max(ans,t);
        // cout<<t<<"\n";
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