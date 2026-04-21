//14 de Marzo 2026 21:14
//DP contest
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

int main(){
	
	ll n, W;
	cin >> n >> W;
	vl w(n), v(n);
	ll s = 0;
	ff(i, 0, n){
		cin >> w[i] >> v[i];
		s += v[i];
	}
	vl dp(s+5, 1e18);
	dp[0]= 0;
	ff(i, 0, n){
		for(ll x = s; x >= v[i]; x--){
			dp[x] = min(dp[x], dp[x-v[i]]+w[i]);
		}
	}
	ll c = 0;
	ff(i, 0, s+5){
		if(dp[i] <= W) c = i;
	}
	cout << c;
	
}
