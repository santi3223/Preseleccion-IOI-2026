//4 de Julio 2026 18:43
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ordered_set<ll> st;
	for(ll i = 1; i <= n; i++){
		st.insert(i);
	}
	ll id = k;
	id %= (ll)st.size();
	while(st.size()){
		ll val = *st.find_by_order(id);
		cout << val << ' ';
		st.erase(val);
		id += k;
		if(st.size()) id %= (ll)st.size();
	}
}
