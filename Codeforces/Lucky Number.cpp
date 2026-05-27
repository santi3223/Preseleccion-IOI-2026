//26 de Mayo 2026 17:33
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

ll f(ll c1, ll c2, ll c3, ll c4){
	if(c1 < 0 || c2 < 0 || c3 < 0 || c4 < 0) return -1;
	if(c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0){
		ll minn = min({c1, c2, c3, c4});
		return 2*minn+f(c1-minn, c2-minn, c3-minn, c4-minn);
	}
	ll maxx = 0;
	
	if(c2 < 1 && c4 < 1) maxx = max(maxx, 1+f(c1-2, c2, c3-1, c4));
	if(c3 < 1 && c4 < 1) maxx = max(maxx, 1+f(c1-1, c2-2, c3, c4));
	if(c1 < 1 && c3 < 1) maxx = max(maxx, 1+f(c1, c2-1, c3, c4-2));
	if(c1 < 1 && c2 < 1) maxx = max(maxx, 1+f(c1, c2, c3-2, c4-1));
	
	if(c3 < 1 && c4 < 1) maxx = max(maxx, min(c1/3, c2));
	if(c2 < 1 && c4 < 1) maxx = max(maxx, min(c3/3, c1));
	if(c1 < 1 && c3 < 1) maxx = max(maxx, min(c2/3, c4));
	if(c1 < 1 && c2 < 1) maxx = max(maxx, min(c4/3, c3));
	
	if(c4 < 1 && c3 < 1 && c2 < 1) maxx = max(maxx, c1/5);
	if(c1 < 1 && c3 < 1 && c4 < 1) maxx = max(maxx, c2/5);
	if(c1 < 1 && c2 < 1 && c4 < 1) maxx = max(maxx, c3/5);
	if(c1 < 1 && c2 < 1 && c3 < 1) maxx = max(maxx, c4/5);
	
	
	maxx = max(maxx, 1+f(c1-1, c2, c3, c4-1));
	maxx = max(maxx, 1+f(c1, c2-1, c3-1, c4));

	return maxx;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vl c(5, 0);
	ll n;
	cin >> n;
	ff(i, 0, n){
		ll x;
		cin >> x;
		c[x%5]++;
	}
	//cout << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << ' ' << c[4] << ed;
	cout << c[0]+f(c[1], c[2], c[3], c[4]);
}
