//2 de Julio 2026 17:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;
 
int main(){
	ll n;
	cin >> n;
	ll sum = n*(n+1)/2;
	if(sum % 2 != 0){
		cout << "NO";
		return 0;
	}
	cout << "YES" << ed;
	vb num(n+1, 0);
	vl ans;
	ll rem = sum/2;
	ll maxx = n;
	while(true){
		if(rem > maxx){
			ans.pb(maxx);
			num[maxx] = 1;
			rem -= maxx;
			maxx--;
		}
		else{
			ans.pb(rem);
			num[rem] = 1;
			break;
		}
	}
	cout << ans.size() << ed;
	for(auto x : ans) cout << x << ' ';
	cout << ed;
	cout << n-((ll)ans.size()) << ed;
	ff(i, 1, n+1) if(num[i] == 0) cout << i << ' ';
	
}
