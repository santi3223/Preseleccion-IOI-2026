//2 de Abril 2026 21:59
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
#define ed endl
#define vs vector<string>

vl st;

ll comp(ll i){
	return lower_bound(all(st), i) - st.begin();
}

int main(){
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, pll>> v1(n);
	vector<pll> v2(q);
	ff(i, 0, n){
		ll a, b, c;
		cin >> a >> b >> c;
		st.pb(a);
		st.pb(b);
		v1[i] = {a, {b, c}};
	}
	ff(i, 0, q){
		ll a, b;
		cin >> a >> b;
		st.pb(a);
		st.pb(b);
		v2[i] = {a, b};
	}
	sort(all(st));
	st.erase(unique(all(st)), st.end());
	vl width(st.size()+5), diff(st.size()+5), val(st.size()+5);
	
	for(auto &a : v1){
		diff[comp(a.fi)+1] += a.se.se;
		diff[comp(a.se.fi)+1] -= a.se.se;
	}
	ff(i, 1, st.size()){
		width[i] = st[i]-st[i-1];
	}
	ff(i, 1, st.size()){
		val[i] = val[i-1]+diff[i];
	}
	vl pref(st.size()+5);
	ff(i, 1, st.size()){
		pref[i] = pref[i-1]+val[i]*width[i];
	}
	ff(i, 0, q){
		cout << pref[comp(v2[i].se)]-pref[comp(v2[i].fi)] << ed;
	}
}
