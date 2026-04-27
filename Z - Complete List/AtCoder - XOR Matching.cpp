//9 de Abril 2026 20:15
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
	ll m, k;
	cin >> m >> k;
	if(m == 0){
		if(k != 0) cout << -1;
		else cout << "0 0";
		return 0;
	}
	if(m == 1){
		if(k != 0) cout << -1;
		else cout << "0 0 1 1";
		return 0;
	}
	if(k >= (1 << m)){
		cout << -1;
		return 0;
	}
	if(k == 0){
		ff(i, 0, (1 << m)) cout << i << ' ';
		for(ll i = (1 << m)-1; i >= 0; i--) cout << i << ' ';
		return 0;	
	}
	vector<pll> arr;
	ff(i, 0, (1 << m)){
		arr.pb({min(i, i^k), max(i, i^k)});
	}
	sort(all(arr));
	arr.erase(unique(all(arr)), arr.end());
	
	for(ll i = 0; i < arr.size(); i += 2){
		cout << arr[i].fi << ' ' << arr[i].se << " ";
		cout << arr[i+1].fi << ' ' << arr[i+1].se << " ";
		cout << arr[i].se << ' ' << arr[i].fi << " ";
		cout << arr[i+1].se << ' ' << arr[i+1].fi << " ";
		
	}
	
}
