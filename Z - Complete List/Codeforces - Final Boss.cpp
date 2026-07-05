//4 de Julio 2026 23:33
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
	ll t;
	cin >> t;
	while(t--){
		ll h, n;
		cin >> h >> n;
		vl a(n), b(n);
		ll l = 0, r = 0;
		ff(i, 0, n) cin >> a[i];
		ff(i, 0, n){
			cin >> b[i];
			r = max(r, b[i]);
		}
		r *= h;
		r += 5;
		ll ans = 0;
		while(l <= r){
			ll mid = l+(r-l)/2;
			ll cur = 0;
			ff(i, 0, n){
				cur += a[i]*(mid/b[i])+a[i];
				if(cur > h){
					cur = h;
					break;
				}
			}
			if(cur >= h){
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		cout << ans+1 << ed;
		
	}
}
