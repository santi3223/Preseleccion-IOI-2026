//11 de Marzo 2026 11:40
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
#define ed "\n"
#define vs vector<string>
 
vl conexiones, ord, ans;
unordered_set<ll> st;
ll sav;
 
void dfs(ll cur){
	sav = ans[cur];
	if(sav != 0){
		return;
	}
	ord.pb(cur);
	ll sz = st.size();
	st.insert(cur);
	if(st.size() == sz){
		st.clear();
		return;
	}
	dfs(conexiones[cur]);
}
 
int main(){
	ll n;
	cin >> n;
	conexiones = vl(n);
	ans = vl(n, 0);
	ff(i, 0, n){
		ll x;
		cin >> x;
		x--;
		conexiones[i] = x;
		if(i == x) ans[i] = 1;
	}
	
	ff(id, 0, n){
		if(ans[id] != 0) continue;
		ord.clear();
		sav = 0;
		dfs(id);
		if(sav != 0){
			for(ll i = ord.size()-1;i >= 0; i--){
				ans[ord[i]] = sav+(ord.size()-i);
			}
		}
		else{
			unordered_set<ll> ok;
			ll pos = -1;
			for(ll i = ord.size()-1;i >= 0; i--){
				ll sz = ok.size();
				ok.insert(ord[i]);
				if(ok.size() == sz){
					pos = i-1;
					break;
				}
			}
			for(auto &p : ok){
				ans[p] = ok.size();
			}
			ll sz = ok.size();
			for(ll i = pos; i >= 0; i--){
				ans[ord[i]] = sz+pos-i+1;
			}
			
		}
	}
	ff(i, 0, n){
		cout << ans[i] << " ";
	}
	
}
