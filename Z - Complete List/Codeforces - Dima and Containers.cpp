//6 de Abril 2026 22:15
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

int main() {
	ll t;
	cin >> t;
	vl cur;
	ll x;
	while(cin >> x){
		if(x == 0){
			cout << 0 << ed;
		}
		else{
			ll id = 0;
			vector<pll> arr;
			arr.pb({x, id});
			while(cin >> x){
				if(x == 0) break;
				id++;
				arr.pb({x, id});
			}
			sort(rall(arr));
			vl ans(arr.size(), 0);
			ff(i, 0, min(3LL, (ll)arr.size())){
				ans[arr[i].se] = i+1;
			}
			ff(i, 0, ans.size()){
				if(ans[i] == 0) cout << "pushBack";
				if(ans[i] == 1) cout << "pushStack";
				if(ans[i] == 2) cout << "pushQueue";
				if(ans[i] == 3) cout << "pushFront";
				cout << ed;
			}
			
			if(x == 0){
				cout << min(3LL, (ll)arr.size()) << " ";
				if(arr.size() == 1) cout << "popStack";
				if(arr.size() == 2) cout << "popStack popQueue";
				if(arr.size() >= 3) cout << "popStack popQueue popFront";
				cout << ed;
			}
		}
		
	}
	
}
