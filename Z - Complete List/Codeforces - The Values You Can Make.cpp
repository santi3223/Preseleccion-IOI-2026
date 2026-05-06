//5 de Mayo 2026 20:13
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, k;
	cin >> n >> k;
	bool dp[2][k+5][k+5];
	memset(dp, false, sizeof(dp));
	dp[0][0][0] = true;
	ff(i, 1, n+1){
		ll cur = i%2;
		ll prev = 1-cur;
		ll x;
		cin >> x;
		ff(j, 0, k+1){
			ff(y, 0, j+1){
				dp[cur][j][y] = dp[prev][j][y];
				if(j >= x){
					dp[cur][j][y] |= dp[prev][j-x][y];
					if(y >= x) dp[cur][j][y] |= dp[prev][j-x][y-x];
				}
			}
		}
	}
	vl pos;
	ff(i, 0, k+1) if(dp[n%2][k][i]) pos.pb(i);
	cout << pos.size() << ed;
	for(auto x : pos) cout << x << ' ';
}
