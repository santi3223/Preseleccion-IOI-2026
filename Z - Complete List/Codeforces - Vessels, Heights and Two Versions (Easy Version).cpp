//7 de Junio 2026 14:38
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl h(n);
		ff(i, 0, n) cin >> h[i];
		ff(no, 0, n){
			vl a(n, 0), b(n, 0);
			ll i = no+1;
			i %= n;
			while(i != no){
				a[i] = max(a[(i-1+n)%n], h[(i-1+n)%n]);
				i++;
				i %= n;
			}
			i = (no-1+n)%n;
			while(i != no){
				ll nxt = i+1;
				nxt %= n;
				b[i] = max(b[nxt], h[i]);
				i = (i-1+n)%n;
			}
			/*ff(i, 0, n) cout << a[i] << ' ';
			cout << ed;
			ff(i, 0, n) cout << b[i] << ' ';
			cout << ed;*/
			ll c = 0;
			ff(i, 0, n){
				c += min(a[i], b[i]);
			}
			cout << c << ' ';
			
		}
		cout << ed;
		
	}
}
