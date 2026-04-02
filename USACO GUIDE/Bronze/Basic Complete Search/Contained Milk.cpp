//6 de Febrero 2026 13:15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	freopen("badmilk.in","r",stdin);
	freopen("badmilk.out","w",stdout);
	ll n, m, d, s;
	cin >> n >> m >> d >> s;
	map<pll, ll> drink;
	map<ll, unordered_set<ll>> drinked;
	ff(i, 0, d){
		ll a, b, c;
		cin >> a >> b >> c;
		if(drink[{a, b}] == 0){
			drink[{a, b}] = c;
		}
		else{
			drink[{a, b}] = min(drink[{a, b}], c);
		}
		drinked[b].insert(a);
	}
	map<ll, ll> sick;
	ff(i, 0, s){
		ll a, b;
		cin >> a >> b;
		sick[a] = b;
	}
	ll maxx = 0;
	ff(bad, 1, m+1){
		ll c = drinked[bad].size();
		if(c == 0) continue;
		bool ok = true;
		for(auto &cur : sick){
			ll person = cur.fi, time = cur.se;
			if(drink[{person, bad}] == 0 || drink[{person, bad}] >= time){
				ok = false;
				break;
			}
		}
		if(ok){
			maxx = max(maxx, c);
		}
	}
	cout << maxx;
	
}
