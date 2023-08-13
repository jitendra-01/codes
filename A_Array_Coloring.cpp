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
    int arr[n],s=0,o=0,e=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2)o++;
        else e++;
        // s+=arr[i];
    }
    if(o%2)cout<<"NO\n";
    else cout<<"YES\n";
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