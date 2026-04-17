//28 de Enero 2026 18:40
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

string n;
vector<vector<vector<vl>>> dp;

ll ok(ll pos, ll sum, ll mod, ll tight, ll target){
	if(sum > target) return 0;
	if(pos == n.size()){
		return (sum == target && mod == 0);
	}
	ll &res = dp[pos][sum][mod][tight];
	if(res != -1) return res;
	res = 0;
	ll limit = 9;
	if(tight != 0) limit = n[pos]-'0';
	ff(d, 0, limit+1){
		ll nwtig = (tight != 0 && d == limit);
		ll nwsum = sum+d;
		ll nwmod = (mod*10+d)%target;
		res += ok(pos+1, nwsum, nwmod, nwtig, target);
	}
	return res;
}

int main(){
	cin >> n;
	ll c = 0;
	ff(s, 1, 127){
		dp.assign(n.size(), vector<vector<vl>>(s+1, vector<vl>(s, vl(2, -1))));
		c += ok(0, 0, 0, 1, s);
	}
	cout << c;
	
}
