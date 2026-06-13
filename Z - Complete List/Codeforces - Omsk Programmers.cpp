//12 de Junio 2026 11:37
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
const long double PI = acos(-1.0);

map<pll, ll> dp;
ll X;

ll solve(ll a, ll b){
	if(a > b) swap(a, b);
	if(a == b) return 0;
	pll state = {a, b};
	if(dp.count(state)) return dp[state];
	ll ans = b-a;
	ans = min(ans, 1 + solve(a, b / X));
	return dp[state] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b >> X;
		dp.clear();
		cout << solve(a, b) << ed;
	}
	
}
