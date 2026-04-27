//26 de Abril 2026 21:35
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
	vl dp(5e5+5, 0);
	ll n, C;
	cin >> n >> C;
	ll c = 0, maxx = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(x == C) c++;
		else dp[x] = max(dp[x], c)+1;
		maxx = max(maxx, dp[x]-c);
	}
	cout << c+maxx;
	
}
