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
    int n,k;
    cin>>n>>k;
    int ans=0;
    if(n>7 && k>n){
        cout<<0<<"\n";
        return;
    }
    for(int i=ceil(double(n)/2.0);i<=n;i++){
        int t=2;
        int j=i,l=n;
        while(t<k){
            int m=(l-j);
            if(m>j || m<0 || m<ceil(double(j)/2.0)){
                break;
            }
            t++;
            l=j;
            j=m;
            if(t==k){
                ans++;
            }
        }
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