//8 de Julio 2026 16:24
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
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<string> a(n);
	ff(i, 0, n) cin >> a[i];
	vector<pll> coord;
	coord.pb({0, 0});
	string ans = "";
	vector<pll> nxt;
	vector<vb> vis(n, vb(n, 0));
	while(coord.size()){
		ans += a[coord[0].fi][coord[0].se];
		char minn = 'Z';
		nxt.clear();
		for(auto [i, j] : coord){
			if(i+1 < n && (char)a[i+1][j] <= minn){
				if((char)a[i+1][j] < minn) nxt.clear(), minn = (char)a[i+1][j];
				if(!vis[i+1][j]) nxt.pb({i+1, j}), vis[i+1][j] = 1;
			}
			if(j+1 < n && (char)a[i][j+1] <= minn){
				if((char)a[i][j+1] < minn) nxt.clear(), minn = (char)a[i][j+1];
				if(!vis[i][j+1]) nxt.pb({i, j+1}), vis[i][j+1] = 1;
			}
		}
		coord.clear();
		for(auto x : nxt){
			coord.pb({x.fi, x.se});
		}
	}
	cout << ans;
	
}
