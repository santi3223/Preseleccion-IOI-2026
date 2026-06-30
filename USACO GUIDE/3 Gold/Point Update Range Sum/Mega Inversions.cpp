//28 de Junio 2026 21:59
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
		arr[i]--;
	}
	vl hi(n, 0), lo(n, 0);
	ordered_set<pll> st;
	ff(i, 0, n){
		hi[i] = (ll) st.size() - st.order_of_key({arr[i], 1e9});
		st.insert({arr[i], i});
	}
	st.clear();
	for(ll i = n-1; i >= 0; i--){
		st.insert({arr[i], i});
		lo[i] = st.order_of_key({arr[i], -1});
	}
	ll c = 0;
	ff(i, 0, n){
		c += lo[i]*hi[i];
	}
	cout << c;
	
	
}
