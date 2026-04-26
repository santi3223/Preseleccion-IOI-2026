//25 de Abril 2026 22:50
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
	ll n, m, q;
	cin >> n >> m >> q;
	vl mp(m, 0);
	ff(i, 0, n){
		ll x;
		cin >> x;
		x--;
		mp[x]++;
	}
	vector<pll> arr;
	ff(i, 0, m){
		arr.pb({mp[i], i});
	}
	sort(all(arr));
	vector<pll> query(q);
	ff(i, 0, q){
		ll x;
		cin >> x;
		x -= n;
		query[i] = {x, i};
	}
	sort(all(query));
	ordered_set<ll> st;
	ll cur = 1;
	vl ans(q, -1);
	ff(i, 0, m-1){
		ll upp = cur+(arr[i+1].fi-arr[i].fi)*(i+1);
		st.insert(arr[i].se);
		ll qi = lower_bound(all(query), pll{cur, 0LL}) - query.begin();
		for(ll j = qi; j < q && query[j].fi < upp; j++){
			ans[query[j].se] = *st.find_by_order((query[j].fi-cur)%(i+1));
		}
		cur = upp;
	}
	
	ff(i, 0, q){
		if(ans[query[i].se] == -1){
			ans[query[i].se] = (query[i].fi-cur)%m;
		}
	}
	ff(i, 0, q){
		cout << ans[i]+1 << ed;
	}
	
}
