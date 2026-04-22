//8 de Marzo 2026 19:47
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
	//brute force
	ll q;
	cin >> q;
	vector<vl> sticks(q);
	vector<pll> arr;
	vl start(q);
	ff(i, 0, q){
		ll n;
		cin >> n;
		start[i] = arr.size();
		while(n--){
			ll x;
			cin >> x;
			sticks[i].pb(x);
			arr.pb({i, x});
		}
	}
	ff(i, 0, start[q-2]){
		ll st = arr[i].se;
		ff(j, start[arr[i].fi+1], start[q-1]){
			ll mid = arr[j].se;
			ff(k, start[arr[j].fi+1], arr.size()){
				ll en = arr[k].se;
				if(st+mid > en && mid+en > st && st+en > mid){
					cout << arr[i].fi+1 << " " << st << " " << arr[j].fi+1 << " " << mid << " " << arr[k].fi+1 << " " << en;
					return 0;
				}
			}
		}
	}
	cout << "NIE";
	
	
}
