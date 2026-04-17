//23 de Enero 2026 12:46
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
	ll n, q;
	cin >> n >> q;
	deque<pll> arr;
	ff(i, 1, n+1){
		arr.pb({i, 0});
	}
	while(q--){
		ll o;
		cin >> o;
		if(o == 2){
			ll p;
			cin >> p;
			p--;
			cout << arr[p].fi << " " <<arr[p].se << ed;
		}
		else{
			char c;
			cin >> c;
			pll cur = arr.front();
			if(c == 'U'){
				arr.push_front({cur.fi, cur.se+1});
			}
			if(c == 'D'){
				arr.push_front({cur.fi, cur.se-1});
			}
			if(c == 'L'){
				arr.push_front({cur.fi-1, cur.se});
			}
			if(c == 'R'){
				arr.push_front({cur.fi+1, cur.se});
			}
			arr.pop_back();
			
		}
	}
	 
	
}
