//28 de Mayo 2026 16:27
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll maxx = -1e18, mi = 0, mj = 0;
		ff(i, 0, n){
			ff(j, 0, m){
				ll x;
				cin >> x;
				if(x > maxx){
					maxx = x;
					mi = i;
					mj = j;
				}
			}
		}
		//cout << mi << ' ' << mj << ed;
		ll hp = mi+1, ph = n-mi, vp = mj+1, pv = m-mj;
		//cout << hp << ' ' << ph << ' ' << vp << ' ' << pv << ed;
		cout << max(hp, ph)*max(vp, pv) << ed;
	}
	
}
