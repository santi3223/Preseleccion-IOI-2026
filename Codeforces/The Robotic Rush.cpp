//18 de Enero 2026 12:40
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k;
		cin >> n >> m >> k;
		vl arr(n), b(m);
		map<ll, char> pos;
		ff(i, 0, n){
			cin >> arr[i];
			pos[arr[i]] = 'r';
		}
		sort(all(arr));
		ff(i, 0, m){
			cin >> b[i];
			pos[b[i]] = 's';
		}
		string str;
		cin >> str;
		ll cc = 0;
		map<ll, ll> mp;
		ff(i, 0, k){
			if(str[i] == 'L'){
				cc--;
			}
			else{
				cc++;
			}
			if(mp[cc] == 0) mp[cc] = i+1;
		}
		
		/*cout << "RANGES" << ed;
		for(auto &x : mp){
			cout << x.fi << " " << x.se << ed;
		}
		cout << ed << ed;*/
		
		ll last = LLONG_MIN;
		vector<pll> near(n, {LLONG_MAX, LLONG_MAX});
		ll c = 0;
		for(auto &p : pos){
			if(p.se == 's'){
				last = p.fi;
			}
			else{
				if(last == LLONG_MIN){
					c++;
					continue;
				}
				near[c].fi = min(near[c].fi, abs(arr[c]-last));
				c++;
			}
		}
		/*cout << "NEAR" << ed;
		ff(i, 0, n){
			cout << near[i].fi << " " << near[i].se << ed;
		}
		cout << ed << " ========= " << ed;*/
		c = n-1;
		last = LLONG_MIN;
		for(auto it = pos.rbegin(); it != pos.rend(); it++){
			auto &p = *it;
			if(p.se == 's'){
				last = p.fi;
			}
			else{
				if(last == LLONG_MIN){
					c--;
					continue;
				}
				near[c].se = min(near[c].se, abs(arr[c]-last));
				c--;
			}
		}
		/*
		cout << "NEAR" << ed;
		ff(i, 0, n){
			cout << near[i].fi << " " << near[i].se << ed;
		}
		cout << ed << " ========= " << ed;
		*/
		vl ans(k, 0);
		ff(i, 0, n){
			ll aa = LLONG_MAX, bb = LLONG_MAX;
			if(mp[-near[i].fi] != 0){
				aa = mp[-near[i].fi]-1;
				//ans[mp[-near[i].fi]-1]--;
			}
			if(mp[near[i].se] != 0){
				bb = mp[near[i].se]-1;
				//ans[mp[near[i].se]-1]--;
			}
			ll best = min(aa, bb);
			if(best != LLONG_MAX) ans[best]--;
		}
		/*cout << "ANS" << ed;
		ff(i, 0, k){
			cout << ans[i] << " ";
		}
		cout << ed;*/
		ll x = n;
		ff(i, 0, k){
			x += ans[i];
			cout << x << " ";
		}
		cout << ed;
		
	}
}
