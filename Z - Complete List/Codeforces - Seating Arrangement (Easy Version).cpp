//8 de Junio 2026 23:13
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, x, s;
		string str;
		cin >> n >> x >> s >> str;
		ll amb = 0;
		for(char c : str) if(c == 'A') amb++;
		ll maxx = 0;
		ff(q, 0, amb+1){
			map<ll, ll> mp;
			set<ll> emp, occ;
			ff(i, 0, x) emp.insert(i);
			ll c = 0, ca = 0;
			ff(i, 0, n){
				char cur = str[i];
				if(cur == 'A'){
					if(ca >= q){
						cur = 'E';
					}
					else cur = 'I';
					ca++;
				}
				ll pos = -1;
				if(cur == 'I'){
					if(emp.size()){
						c++;
						pos = *emp.begin();
						emp.erase(pos);
						occ.insert(pos);
						mp[pos]++;
					}
				}
				else{
					if(occ.size()){
						c++;
						pos = *occ.begin();
						mp[pos]++;
					}
				}
				if(pos != -1){
					if(mp[pos] == s) occ.erase(pos);
				}
				
			}
			maxx = max(maxx, c);
		}
		cout << maxx << ed;
		
	}
}
