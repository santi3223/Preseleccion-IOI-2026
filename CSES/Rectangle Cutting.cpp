//7 de Julio 2026 14:08
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
const ll MOD = 1e9+7;
 
vector<vl> dp;
 
ll calc(ll a, ll b){
	if(a > b) swap(a, b);
	if(a == b) return 0;
	if(a == 1){
		return b-1;
	}
	if(dp[a][b] != 1e9) return dp[a][b];
	ff(i, 1, a){
		dp[a][b] = min(dp[a][b], calc(i, b)+calc(a-i, b)+1);
	}
	ff(i, 1, b){
		dp[a][b] = min(dp[a][b], calc(a, i)+calc(a, b-i)+1);
	}
	return dp[a][b];
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp = vector<vl>(505, vl(505, 1e9));
	ll a, b;
	cin >> a >> b;
	/*ff(i, 1, a+1){
		ff(j, 1, b+1){
			cout << calc(i, j) << ' ';
		}
		cout << ed;
	}*/
	cout << calc(a, b);
}
