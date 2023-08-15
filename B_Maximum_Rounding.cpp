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
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    long long int p=s.size()+1;
    for(int i=s.size()-1;i>=0;i--){
        if(p!=s.size()+1){
            s[i]='0';
        }
         if(int(s[i])>=int('5')){
            p=i;
            s[p]='0';
        }
    }
    for(int i=p+1;i<s.size();i++){
        s[i]+=1;
        if(int(s[i])>=int('5')){
            s[i]='0';
        }
        else break;
    }
    if(s[s.size()-1]=='0')s.push_back('1');
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
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