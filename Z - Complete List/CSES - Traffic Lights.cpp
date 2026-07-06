//4 de Julio 2026 16:09
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
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x, n;
	cin >> x >> n;
	multiset<ll> sz = {x};
	set<ll> st = {0, x};
	ff(i, 0, n){
		ll pos;
		cin >> pos;
		ll ri = *st.lower_bound(pos);
		ll le = *prev(st.lower_bound(pos));
		sz.erase(sz.find(ri-le));
		sz.insert(pos-le);
		sz.insert(ri-pos);
		st.insert(pos);
		
		cout << *prev(sz.end()) << ' ';
	}
}
