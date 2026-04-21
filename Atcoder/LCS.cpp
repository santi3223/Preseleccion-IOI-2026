//15 de Marzo 2026 17:57
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
	string s, t;
	cin >> s >> t;
	ll n = s.size(), m = t.size();
	vector<vl> dp(n+5, vl(m+5, 0));
	ff(i, 0, n){
		ff(j, 0, m){
			if(s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
			
		}
	}
	
	/*ff(i, 0, n+2){
		ff(j, 0, m+2){
			cout << dp[i][j];
		}
		cout << ed;
	}*/
	string ans = "";
	ll i = n, j = m;
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}
		else if(dp[i][j] == dp[i][j-1]){
			j--;
		}
		else{
			ans += s[i-1];
			i--;
			j--;
		}
	}
	reverse(all(ans));
	cout << ans;
}
