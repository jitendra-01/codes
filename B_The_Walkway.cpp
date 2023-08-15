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
    int n,m,d;
    cin>>n>>m>>d;
    int arr[m+2];
    arr[0]=1;
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    arr[m+1]=n;
    int temp[m+1];
    long long int ans=0,sum=0;
    for(int i=1;i<=m;i++){
        long long int in,last;
        if(i!=m){
            last=(arr[i+1]-arr[i-1]-1)/d;
            in=((arr[i]-arr[i-1]-1)/d)+((arr[i+1]-arr[i]-1)/d)+1;
        }
        if(i==m){
            last=(arr[i+1]-arr[i-1])/d;
            in=((arr[i]-arr[i-1]-1)/d)+((arr[i+1]-arr[i])/d)+1;
        }
        if(last<in && arr[i]!=1 )ans++;
        sum+=((arr[i]-arr[i-1]-1)/d)+1;
    }
    if(arr[1]!=1)sum+=1;
    sum+=(arr[m+1]-arr[m])/d;
    if(ans>0)
        cout<<sum-1<<" "<<ans<<"\n";
    else 
        cout<<sum<<" "<<m<<"\n";
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