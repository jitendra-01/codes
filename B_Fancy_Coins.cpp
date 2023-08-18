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
    long long int n,k,a1,ak;
    cin>>n>>k>>a1>>ak;
    long long int max=(ak*k)+a1;
    long long int r=n-max;
    if(max==n)cout<<0<<"\n";
    else if(a1>=n%k){
        if(max>n)cout<<0<<"\n";
        else{
            if(r%k)
                cout<<r/k+1<<"\n";
            else
                cout<<r/k<<"\n";
        }
    }
    else{
        if(max>n)cout<<(n%k)-a1<<"\n";
        else{        
            cout<<(r/k)+(r%k)<<"\n";
        }
    }
    
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