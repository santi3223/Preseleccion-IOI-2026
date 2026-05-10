//9 de Mayo 2026 23:27
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	vl two(n), five(n);
	ff(i, 0, n){
		ll x;
		cin >> x;
		while(x % 2 == 0){
			two[i]++;
			x /= 2;
		}
		while(x % 5 == 0){
			five[i]++;
			x /= 5;
		}
	}
	
	vector<vl> dp(k+1, vl(5205, -1));
	dp[0][0] = 0;
	ff(i, 0, n){
		for(ll j = k-1; j >= 0; j--){
			for(ll f = 5200-five[i]; f >= 0; f--){
				if(dp[j][f] == -1) continue;
				dp[j+1][f+five[i]] = max(dp[j+1][f+five[i]], dp[j][f]+two[i]);
			}
		}
	}
	ll ans = 0;
	ff(f, 0, 5001){
		if(dp[k][f] == -1) continue;
		ans = max(ans, min(f, dp[k][f]));
	}
	cout << ans;
	
}

