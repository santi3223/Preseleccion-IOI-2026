//2 de Junio 2026 23:01
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const ll MOD = 1e9+7;

int main(){
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[b-1].pb(a-1);
	}
	vector<vl> dp((1 << n), vl(n, 0));
	dp[1][0] = 1;
	ff(s, 2, (1 << n)){
		if((s&1) == 0) continue;
		if((s & (1 << (n-1))) && s != ((1 << n) - 1)) continue;
		ff(en, 0, n){
			if((s & (1 << en)) == 0) continue;
			ll prev = s - (1 << en);
			for(auto x : conexiones[en]){
				if((s & (1 << x))){
					dp[s][en] += dp[prev][x];
					if(dp[s][en] >= MOD) dp[s][en] %= MOD;
				}
			}
		}
	}
	cout << dp[(1 << n)-1][n-1];
	
}
