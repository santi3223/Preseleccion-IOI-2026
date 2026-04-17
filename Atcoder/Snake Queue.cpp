//23 de Enero 2026 14:46
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll q;
	cin >> q;
	deque<pll> arr;
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll l;
			cin >> l;
			if(arr.empty()){
				arr.pb({l, l});
				continue;
			}
			pll last = arr.back();
			arr.pb({last.fi+l, l});
		}
		else if(o == 2){
			arr.pop_front();
		}
		else{
			ll k;
			cin >> k;
			k--;
			if(k == 0){
				cout << 0 << ed;
				continue;
			}
			ll origin = arr[0].fi-arr[0].se+1;
			cout << arr[k-1].fi-origin+1 << ed;
		}
		/*cout << " ";
		ff(i, 0, arr.size()){
			cout << arr[i].fi << " " << arr[i].se << ",  ";
		}
		cout << ed;
		cout << "=================" << ed << ed;*/
	}
}
