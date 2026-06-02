//1 de Junio 2026 23:06
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vector<vl> arr(n, vl(m));
		ff(i, 0, n){
			ff(j, 0, m){
				cin >> arr[i][j];
			}
		}
		if((n+m) % 2 == 0){
			cout << "NO" << ed;
			continue;
		}
		vector<vector<pll>> rang(n, vector<pll>(m, {1e18, -1e18}));
		rang[0][0] = {arr[0][0], arr[0][0]};
		ff(i, 0, n){
			ff(j, 0, m){
				if(i == 0 && j == 0) continue;
				if(i-1 >= 0){
					rang[i][j].fi = min(rang[i][j].fi, rang[i-1][j].fi+arr[i][j]);
					rang[i][j].se = max(rang[i][j].se, rang[i-1][j].se+arr[i][j]);
				}
				if(j-1 >= 0){
					rang[i][j].fi = min(rang[i][j].fi, rang[i][j-1].fi+arr[i][j]);
					rang[i][j].se = max(rang[i][j].se, rang[i][j-1].se+arr[i][j]);
				}
			}
		}
		auto [a, b] = rang[n-1][m-1];
		//cout << a << ' ' << b << ' ';
		if(a % 2 == 0 && a <= 0 && 0 <= b) cout << "YES" << ed;
		else cout << "NO" << ed;
	}
}
