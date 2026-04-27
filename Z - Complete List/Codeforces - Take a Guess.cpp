//11 de Marzo 2026 22:49	
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

ll ask(string s, ll a, ll b){
	cout << s << " " << a << " " << b << ed;
	ll c;
	cin >> c;
	return c;
}

ll sum(ll a, ll b){
	ll andd = ask("and", a, b);
	ll orr = ask("or", a, b);
	ll xorr = ~andd & orr;
	return 2*andd+xorr;
}

int main(){
	ll n, k;
	cin >> n >> k;
	ll ab = sum(1, 2);
	ll ac = sum(1, 3);
	ll bc = sum(2, 3);
	vl arr;
	arr.pb((ab+ac-bc)/2);
	arr.pb(ab-arr[0]);
	arr.pb(ac-arr[0]);
	ff(i, 3, n){
		arr.pb(sum(i, i+1) - arr.back());
	}
	sort(all(arr));
	cout << "finish " << arr[k-1] << ed;
}
