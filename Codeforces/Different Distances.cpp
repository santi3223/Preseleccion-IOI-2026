//9 de Junio 2026 11:01
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
const long double PI = acos(-1.0);

vl convert(vl cur){
	vl ans, base;
	if(cur.size() == 2){
		base = {1,2,2,1,1,2,1,2};
	}
	if(cur.size() == 3){
		base = {1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};
	}
	if(cur.size() == 4){
		base = {1, 4, 3, 4, 4, 3, 3, 1, 2, 1, 2, 3, 4, 2, 2, 1 };
	}
	if(cur.size() == 5){
		base = {5, 3, 2, 4, 1, 2, 2, 4, 4, 5, 3, 5, 2, 1, 3, 1, 5, 4, 1, 3};
	}
	ff(i, 0, base.size()){
		ans.pb(cur[base[i]-1]);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		set<ll> st;
		ff(i, 1, n+1) st.insert(i);
		vl arr;
		while(st.size()){
			vl cur;
			if(st.size() == 6){
				for(auto x : st){
					if(cur.size() == 3) break;
					cur.pb(x);
				}
			}
			else{
				for(auto x : st){
					if(cur.size() == 5) break;
					cur.pb(x);
				}
			}
			
			vl o = convert(cur);
			for(auto x : o) arr.pb(x);
			for(auto x : cur) st.erase(x);
		}
		for(auto x : arr) cout << x << ' ';
		cout << ed;
	}
	
}
