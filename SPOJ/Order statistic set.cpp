//22 de Julio 2026 21:33
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
	ll q;
	cin >> q;
	ordered_set<ll> st;
	while(q--){
		char c;
		ll x;
		cin >> c >> x;
		if(c == 'I'){
			st.insert(x);
		}
		if(c == 'D'){
			st.erase(x);
		}
		if(c == 'K'){
			x--;
			if((ll)st.size() <= x) cout << "invalid" << ed;
			else cout << *st.find_by_order(x) << ed;
		}
		if(c == 'C'){
			cout << st.order_of_key(x) << ed;
		}
	}
}
