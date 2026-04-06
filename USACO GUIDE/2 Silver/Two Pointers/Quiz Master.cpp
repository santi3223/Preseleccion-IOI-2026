//28 de Febrero 2026 22:41
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
#define ed "\n"
#define vb vector<bool>

vector<vl> factors;

void facc(){
	factors = vector<vl>(100005);
	ff(i, 2, 100005){
		for(ll j = i; j < 100005; j += i){
			factors[j].pb(i);
		}
	}
}

int main(){
	facc();
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		vl count(m+1, 0);
		count[0] = n+5;
		count[1] = n+5;
		sort(all(arr));
		ll l = 0, r = 0;
		ll amo = 0;
		for(auto &x : factors[arr[r]]){
			if(x > m) break;
			amo++;
			count[x]++;
		}
		ll minn = LLONG_MAX;
		while(l < n){
			//cout << l << " " << r << ed;
			if(amo == m-1){
				minn = min(minn, arr[r]-arr[l]);
			}
			if((amo != m-1 || l+1 > r) && r+1 < n){
				r++;
				for(auto &x : factors[arr[r]]){
					if(x > m) break;
					count[x]++;
					if(count[x] == 1){
						amo++;
					}
				}
			}
			else{
				l++;
				for(auto &x : factors[arr[l-1]]){
					if(x > m) break;
					count[x]--;
					if(count[x] == 0){
						amo--;
					}
				}
			}
		}
		if(minn == LLONG_MAX) minn = -1;
		cout << minn << ed;
	}
}
