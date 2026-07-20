//19 de Julio 2026 23:34
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	multiset<ll> st;
	ff(i, 0, n){
		ll a;
		cin >> a;
		st.insert(a);
	}
	ff(i, 0, m){
		ll a;
		cin >> a;
		auto x = st.upper_bound(a);
		if(x == st.begin()) cout << -1 << ed;
		else{
			x--;
			cout << *x << ed;
			st.erase(x);
		}
	}
	
}
