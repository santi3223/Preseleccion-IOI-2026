//8 de Abril 2026 22:52
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
#define ed "\n"
#define vs vector<string>
 
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(rall(arr));
		ll x, y, a, b, k;
		cin >> x >> a >> y >> b >> k;
		vl pref(n);
		if(x < y){
			swap(x, y);
			swap(a, b);
		}
		ff(i, 0, n){
			if((i+1) % a == 0) pref[i] += 1;
			if((i+1) % b == 0) pref[i] += 2;
		}
		/*cout << "PREF" << ed;
		ff(i, 0, n) cout << pref[i] << ' ';
		cout << ed << ed;*/
		vl one, two, three;
		ff(i, 0, n){
			if(pref[i] == 1) one.pb(i);
			if(pref[i] == 2) two.pb(i);
			if(pref[i] == 3) three.pb(i);
		}
		ll l = 1, r = n, ans = -1;
		while(l <= r){
			ll mid = l+(r-l)/2;
			long double cur = 0.0;
			ll pos3 = upper_bound(all(three), mid-1)-three.begin();
			ll pos2 = upper_bound(all(two), mid-1)-two.begin();
			ll pos1 = upper_bound(all(one), mid-1)-one.begin();
			ff(i, 0, pos3){
				long double div = (long double)arr[i]/100.0;
				long double X = x, Y = y;
				cur += div*(X+Y);
			}
			long double v1 = 0.0, v2 = 0.0;
			ff(i, pos3, pos3+pos1){
				long double div = (long double)arr[i]/100.0;
				long double X = x, Y = y;
				v1 += div*X;
			}
			ff(i, pos3+pos1, pos3+pos2+pos1){
				long double div = (long double)arr[i]/100.0;
				long double X = x, Y = y;
				v1 += div*Y;
			}
			
			ff(i, pos3, pos3+pos2){
				long double div = (long double)arr[i]/100.0;
				long double X = x, Y = y;
				v2 += div*Y;
			}
			ff(i, pos3+pos2, pos3+pos2+pos1){
				long double div = (long double)arr[i]/100.0;
				long double X = x, Y = y;
				v2 += div*X;
			}
			
			//cout << cur << ed << v1 << ' ' << v2 << ed << ed;
			cur += max(v1, v2);
			long double K = k;
			//cout << pos1 << ' ' << pos2 << ' ' << pos3 << ed;
			//cout << mid << "  " << cur << ed << ed;
			if(cur >= K){
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
			
		}
		cout << ans << ed;
	}
}
