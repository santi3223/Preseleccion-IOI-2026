//2 de Mayo 2026 08:21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>
ll MOD = 998244353;

int main(){
	ll c = 1;
	string s;
	cin >> s;
	ll n = s.size(), ans = 0;
	ff(i, 1, n){
		if(s[i] == s[i-1]){
			ans += c*(c+1)/2;
			c = 1;
		}
		else c++;
		if(ans > MOD) ans %= MOD;
	}
	ans += c*(c+1)/2;
	cout << ans%MOD;
}
