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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

map<ll, ll> fib;

ll calc(ll i){
	if(fib[i]){
		return fib[i];
	}
	fib[i] = calc(i-1)+calc(i-2);
	return fib[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr(n);
	fib[1] = 1;
	fib[2] = 2;
	fib[0] = 1;
	vl ans1(n);
	ll prev = 0;
	ff(i, 0, n){
		cin >> arr[i];
		ans1[i] = prev+calc(arr[i]);
		prev += calc(arr[i]);
	}
	ll ult = 0;
	for(auto f : fib){
		ult = f.se;
	}
	while(ult <= ans1[n-1]){
		ll sz = fib.size();
		ult = calc(sz+1);
	}
	
	vl dp(ans1[n-1]+5, 0);
	dp[0] = 1;
	for(auto [id, f] : fib){
		if(id == 0) continue;
		for(ll i = dp.size(); i >= f; i--){
			dp[i] += dp[i-f];
		}
	}
	ff(i, 0, ans1.size()){
		cout << dp[ans1[i]] << ed;
	}
	
}

