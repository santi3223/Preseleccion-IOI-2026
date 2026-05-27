//26 de Mayo 2026 14:20
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	for(ll mask = 0; mask <= (1LL << n); mask++){
		ll cur = 0;
		for(ll i = 0; i < n; i++){
			if((mask >> i) & 1){
				cur += arr[i];
			}
			else cur -= arr[i];
			if(cur < 0) cur += 360;
			if(cur > 360) cur -= 360;
		}
		if(cur == 0){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}

