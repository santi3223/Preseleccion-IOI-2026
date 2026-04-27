//7 de Marzo 2026 19:28
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
 
 
int main(){
	ll n, q;
	cin >> n >> q;
	vs arr(n);
	vector<vl> pref(n, vl(n));
	ff(i, 0, n) cin >> arr[i];
	ff(i, 0, n){
		ff(j, 0, n){
			ll a = 0, b = 0, c = 0, d = 0;
			if(i-1 >= 0) a = pref[i-1][j];
			if(j-1 >= 0) b = pref[i][j-1];
			if(i-1 >= 0 && j-1 >= 0) c = pref[i-1][j-1];
			if(arr[i][j] == '*') d++;
			pref[i][j] = a+b-c+d;
		}
	}
	/*ff(i, 0, n){
		ff(j, 0, n){
			cout << pref[i][j] << " ";
		}
		cout << ed;
	}
	cout << ed;*/
	while(q--){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		c--;
		d--;
		ll x = 0, y = 0, z = 0;
		if(b-1 >= 0) x = pref[c][b-1];
		if(a-1 >= 0) y = pref[a-1][d];
		if(a-1 >= 0 && b-1 >= 0) z = pref[a-1][b-1];
		cout << pref[c][d]-x-y+z << ed;
	}
}
