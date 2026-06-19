//18 de Junio 2026 13:30
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

int main(){
	ll n, m;
	cin >> n >> m;
	vl atk, def;
	ff(i, 0, n){
		string s;
		ll x;
		cin >> s >> x;
		if(s == "ATK") atk.pb(x);
		else def.pb(x);
	}
	vl arr(m);
	ff(i, 0, m) cin >> arr[i];
	sort(all(atk));
	sort(all(def));
	sort(rall(arr));
	
	/*for(auto x : atk) cout << x << ' ';
	cout << ed;
	for(auto x : def) cout << x << ' ';
	cout << ed;
	for(auto x : arr) cout << x << ' ';
	cout << ed << ed << ed;*/
	
	
	
	ll c = 0, maxx = 0;
	ff(len, 1, min(m, (ll)atk.size())+1){
		ll cur = 0;
		bool ok = true;
		ff(i, 0, len){
			if(arr[len-i-1] >= atk[i]){
				cur += arr[len-i-1]-atk[i];
			}
			else{
				ok = 0;
				break;
			}
		}
		if(ok) maxx = max(maxx, cur);
	}
	//cout << maxx << ed;
	if((ll)atk.size()+(ll)def.size() > arr.size()){
		//cout << "A";
		cout << maxx;
		return 0;
	}
	
	multiset<ll> st(all(arr));
	bool ok = true;
	sort(rall(atk));
	
	ff(i, 0, def.size()){
		auto it = st.upper_bound(def[i]);
		if(it == st.end()){
			ok = false;
			break;
		}
		st.erase(it);
	}
	if(!ok){
		cout << maxx;
		return 0;
	}
	
	ff(i, 0, atk.size()){
		auto it = st.lower_bound(atk[i]);
		if(arr[i] < atk[i]){
			ok = false;
			break;
		}
		c += *it-atk[i];
		st.erase(it);
	}
	if(!ok){
		cout << maxx;
		return 0;
	}
	
	for(auto x : st){
		c += x;
	}
	
	//cout << "OK";
	cout << max(maxx, c);
	
	
	
}
