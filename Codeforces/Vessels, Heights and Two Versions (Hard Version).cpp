//7 de Junio 2026 19:58
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl h(n);
		ll mx = 0;
		ff(i, 0, n){
			cin >> h[i];
			if(h[mx] < h[i]) mx = i;
		}
		vl path(n-1);
		ff(i, 0, n-1){
			path[i] = h[(mx+i+1)%n];
		}
		vl l(n), r(n);
		vector<vl> stk;
		ll sum = 0;
		ff(i, 0, n-1){
			ll c = 1;
			while(!stk.empty() && stk.back()[0] <= path[i]){
				sum -= stk.back()[0]*stk.back()[1];
				c += stk.back()[1];
				stk.pop_back();
			}
			stk.pb({path[i], c});
			sum += path[i]*c;
			l[i+1] = sum;
		}
		stk.clear();
		sum = 0;
		//ff(i, 0, n-1) cout << path[i] << ' ';
		//cout << ed;
		for(ll i = n-2; i >= 0; i--){
			ll c = 1;
			while(!stk.empty() && stk.back()[0] <=path[i]){
				sum -= stk.back()[0]*stk.back()[1];
				c += stk.back()[1];
				stk.pop_back();
			}
			stk.pb({path[i], c});
			sum += path[i]*c;
			r[i] = sum;
		}
		/*ff(i, 0, n) cout << l[i] << ' ';
		cout << ed;
		ff(i, 0, n) cout << r[i] << ' ';
		cout << ed;*/
		vl ans(n);
		ff(i, 0, n) ans[(mx+i+1)%n] = l[i]+r[i];
		for(auto x : ans) cout << x << ' ';
		cout << ed;
		
	}
}
