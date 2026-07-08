//7 de Julio 2026 23:51
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

ll sum(ll x){
	ll c = 0;
	while(x){
		c += x % 10;
		x /= 10;
	}
	return c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vl arr(n);
		set<ll> st;
		map<ll, ll> mp;
		ff(i, 0, n) cin >> arr[i], st.insert(i);
		while(m--){
			ll o;
			cin >> o;
			if(o == 1){
				ll l, r;
				cin >> l >> r;
				l--;
				r--;
				auto it = st.lower_bound(l);
				auto en = st.upper_bound(r);
				while(it != en){
					ll x = *it;
					//cout << x << ' ';
					arr[x] = sum(arr[x]);
					mp[x]++;
					auto cur = it;
					it++;
					if(mp[x] == 3) st.erase(cur);
				}
				//cout << ed;
			}
			else{
				ll x;
				cin >> x;
				cout << arr[x-1] << ed;
			}
		}
	}
	
}
