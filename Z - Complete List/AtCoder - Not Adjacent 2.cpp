//2 de Mayo 2026 09:24
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
	string s;
	cin >> s;
	vl dp(3, 0);
	for(auto &c : s){
		if(c == 'a'){
			ll add = (1+dp[1]+dp[2])%MOD;
			dp[0] = (dp[0]+add)%MOD;
		}
		else if(c == 'b'){
			ll add = (1+dp[0]+dp[2])%MOD;
			dp[1] = (dp[1]+add)%MOD;
		}
		else{
			ll add = (1+dp[1]+dp[0])%MOD;
			dp[2] = (dp[2]+add)%MOD;
		}
	}
	cout << (dp[0]+dp[1]+dp[2])%MOD;
}
