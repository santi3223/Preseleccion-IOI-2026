//8 de Mayo 2026 14:55
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

template<typename T>
using ordered_multiset = 
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ordered_multiset<pll> st;
	ff(i, 0, k-1){
		st.insert({arr[i], i});
	}
	ll mid = k;
	if(mid & 1) mid++;
	mid /= 2;
	mid--;
	ff(i, k-1, n){
		st.insert({arr[i], i});
		//cout << i << ' ';
		if(i >= k) st.erase(st.find({arr[i-k], i-k}));
		/*ff(j, 0, k){
			cout << st.find_by_order(j)->fi << ' ';
		}
		cout << ed;*/
		cout << st.find_by_order(mid)->fi << ' ';
	}
}
