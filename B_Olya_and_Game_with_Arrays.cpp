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
    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> t;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            t.push_back(x);
        }
        a.push_back(t);
    }
    int s=INT_MAX;
    vector<int> l;
    for(int i=0;i<n;i++){
        int l1,l2;
        if(a[i][0]>a[i][1]){
            l1=a[i][1];
            l2=a[i][0];
        }
        else{
            l2=a[i][1];
            l1=a[i][0];
        }
        s=min(s,min(a[i][0],a[i][1]));
        for(int j=2;j<a[i].size();j++){
            s=min(a[i][j],s);
            if(l1>a[i][j]){
                l2=l1;
                l1=a[i][j];
            }
            else if(l2>a[i][j]){
                l2=a[i][j];
            }
        }
        l.push_back(l2);
    }
    sort(l.begin(),l.end());
    long long int ans=s;
    for(int i=1;i<n;i++){
        ans+=l[i];
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