//7 de Junio 2026 10:53
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n == 10){
			cout << -1 << ed;
			continue;
		}
		ll res = n%12;
		ll pal = res;
		if(res == 10) pal = 22;
		if(res == 11) pal = 11;
		cout << pal << ' ' << (n-pal) << ed;
		
	}
}
