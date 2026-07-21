//20 de Julio 2026 10:54
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
	ll n, k;
	cin >> n >> k;
	vl a(n);
	ff(i, 0, n) cin >> a[i];
	vl v1, v2;
	ll sz1 = n/2;
	ff(mask, 0, (1 << sz1)){
		ll c = 0;
		ff(i, 0, sz1){
			if(mask & (1 << i)){
				if(c+a[i] > k){
					c = -1;
					break;
				}
				c += a[i];
			}
		}
		if(c == -1) continue;
		v1.pb(c);
	}
	ll sz2 = n-sz1;
	ff(mask, 0, (1 << sz2)){
		ll c = 0;
		ff(i, 0, sz2){
			if(mask & (1 << i)){
				if(c+a[sz1+i] > k){
					c = -1;
					break;
				}
				c += a[sz1+i];
			}
		}
		if(c == -1) continue;
		v2.pb(c);
	}
	sort(all(v1));
	sort(all(v2));
	
	ll c = 0;
	ll prev = 0, i = 0;
	while(prev < v1.size()){
		i = upper_bound(all(v1), v1[prev]) - v1.begin()-1;
		ll l = lower_bound(all(v2), k-v1[prev]) - v2.begin(), r = upper_bound(all(v2), k-v1[prev]) - v2.begin()-1;
		c += (i-prev+1)*(r-l+1);
		prev = i+1;
	}
	cout << c;
}
