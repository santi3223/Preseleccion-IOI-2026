//27 de Ferbrero 2026 15:37
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
#define ed "\n"
#define vb vector<bool>

int main(){
	string str;
	cin >> str;
	ll n = str.size();
	vector<vl> dp(n, vl(n, 0));
	vector<vb> pal(n, vb(n, false));
	for(ll i = n-1; i >= 0; i--){
		dp[i][i] = pal[i][i] = 1;
		ff(j, i+1, n){
			pal[i][j] = (pal[i+1][j-1] || j-i==1) && (str[i] == str[j]);
			dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+pal[i][j];
		}
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		cout << dp[l-1][r-1] << ed;
	}
}
