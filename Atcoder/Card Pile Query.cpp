//25 de Abril 2026 9:25
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
#define ed endl
#define vs vector<string>



int main(){
	ll n, q;
	cin >> n >> q;
	vl tp(n, -1), bot(n, -1), root(n);
	vl isroot(n);
	ff(i, 0, n){root[i] = i; isroot[i] = i;}
	while(q--){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		//cout << "IN " << a << ' ' << b << ed;
		if(isroot[a] != -1){
			root[isroot[a]] = -1;
			isroot[a] = -1;
		}
		else{
			ll lo = bot[a];
			tp[lo] = -1;
		}
		bot[a] = b;
		tp[b] = a;
		/*cout << "ISROOT ";
		ff(i, 0, n) cout << isroot[i]+1 << ' ';
		cout << ed << "ROOT ";
		ff(i, 0, n) cout << root[i]+1 << ' ';
		cout << ed << "TOP ";
		ff(i, 0, n) cout << tp[i]+1 << ' ';
		cout << ed << "BOTTOM ";
		ff(i, 0, n) cout << bot[i]+1 << ' ';
		cout << ed << ed;*/
	}
	ff(i, 0, n){
		ll c = 0, cur = root[i];
		while(cur != -1){
			c++;
			cur = tp[cur];
		}
		cout << c << ' ';
	}
	
}
