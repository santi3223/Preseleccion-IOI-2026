//26 de Mayo 2026 16:34
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

ll n;
vl c, p;

bool check(ll q){
	ll cur = 0;
	ff(i, 0, n){
		cur += p[i];
		cur -= q*c[i];
		if(cur < 0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	c = vl(n);
	p = vl(n);
	ff(i, 0, n) cin >> c[i];
	ff(i, 0, n) cin >> p[i];
	ll l = 0, r = 1e9, maxx = 0;
	while(l <= r){
		ll mid = l+(r-l)/2;
		if(check(mid)){
			maxx = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout << maxx;
}
