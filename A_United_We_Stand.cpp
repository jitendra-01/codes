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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b;
    vector<int> c;
    sort(a,a+n);
    int s=a[0];
    b.push_back(a[0]);
    int i=1;
    while(i<n &&  a[i]==s){
        b.push_back(a[i]);
        i++;
    }
    while(i<n){
        c.push_back(a[i]);
        i++;
    }
    if(b.size()==0 || c.size()==0) {
        cout<<-1<<"\n";
        return ;
    }
    cout<<b.size()<<" "<<c.size()<<"\n";
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    cout<<"\n";
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