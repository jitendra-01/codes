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

int isSubstring(string s1, string s2)
{
    int M = s1.size();
    int N = s2.size();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    string temp,t2;
    for(int i=0;i<n;i++){
        temp+="()";
        t2+="(";
    }
    for(int i=0;i<n;i++){
        t2+=")";
    }
    int t1,t;
    t1=isSubstring(s,temp);
    t=isSubstring(s,t2);
    if(t1==-1)cout<<"YES\n"<<temp<<"\n";
    else if(t==-1)cout<<"YES\n"<<t2<<"\n";
    else cout<<"NO\n";

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