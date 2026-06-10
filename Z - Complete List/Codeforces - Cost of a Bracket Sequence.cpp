//9 de Junio 2026 22:52
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
		ll n, k;
		string s;
		cin >> n >> k >> s;
		vl l, r;
		ff(i, 0, n){
			if(s[i] == '(') l.pb(i);
			if(s[i] == ')') r.pb(i);
		}
		ll szl = l.size(), szr = r.size();
		string best(n, '0');
		string removed(n, '0');
		//cout << "SIZE " << szl << ' ' << k << ' ' << szr << ed;
		ll minn = 1e18;
		ff(posl, 0, min(szl, k)+1){
			ll posr = min(k-posl, szr);
			removed = string(n, '0');
			ff(i, 0, posl){
				removed[l[i]] = '1';
			}
			ff(i, szr-posr, szr){
				removed[r[i]] = '1';
			}
			ll q = 0, cur = 0;
			ff(i, 0, n){
				if(removed[i] == '1') continue;
				if(s[i] == '(') cur++;
				else{
					if(cur != 0){
						q++;
						cur--;
					}
				}
			}
			//cout << posl << ' ' << posr << ' ' << q << ed;
			if(q < minn){
				best = removed;
				minn = q;
			}
		}
		cout << best << ed;
	}
}
