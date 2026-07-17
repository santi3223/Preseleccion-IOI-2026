//7 de Julio 2026 22:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vl a(n), b(m);
	ff(i, 0, n) cin >> a[i];
	ff(i, 0, n) cin >> b[i];
	vector<vl> dp(n+1, vl(m+1, 0));
	ff(i, 1, n+1){
		ff(j, 1, m+1){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	/*ff(i, 0, n+1){
		ff(j, 0, m+1){
			cout << dp[i][j] << ' ';
		}
		cout << ed;
	}*/
	vl ans;
	ll i = n, j = m;
	while(i != 0 && j != 0 && dp[i][j] != 0){
		if(a[i-1] == b[j-1]){
			ans.pb(a[i-1]);
			i--;
			j--;
			continue;
		}
		if(dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}
	reverse(all(ans));
	cout << ans.size() << ed;
	for(auto x : ans) cout << x << ' ';
}
