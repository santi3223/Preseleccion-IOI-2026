//8 de Marzo 2026 20:28
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
	ll q;
	cin >> q;
	vector<vl> sticks(q);
	ff(i, 0, q){
		ll n;
		cin >> n;
		while(n--){
			ll x;
			cin >> x;
			sticks[i].pb(x);
		}
		sort(all(sticks[i]));
	}
	ff(i, 0, q){
		ff(j, i+1, q){
			ff(k, j+1, q){
				ll st = sticks[i][0], mid = sticks[j][0];
				ll ib = 0, jb = 0;
				while(jb < sticks[j].size()){
					st = sticks[i][ib];
					mid = sticks[j][jb];
					ll find = max(mid+1LL-st, st+1LL-mid);
					ll pos = lower_bound(all(sticks[k]), find) - sticks[k].begin();
					//cout << st << " " << mid << " " << sticks[k][pos] << ed;
					if(st+mid > sticks[k][pos] && sticks[k][pos] >= find){
						//cout << find << ed;
						cout << i+1 << " " << st << " " << j+1 << " " << mid << " " << k+1 << " " << sticks[k][pos];
						return 0;
					}
					if(ib+1 < sticks[i].size() && sticks[i][ib] > sticks[j][jb]) ib++; // >
					else jb++;
				}
			}
		}
	}
	
	ff(i, 0, q){
		ff(j, i+1, q){
			ff(k, j+1, q){
				ll st = sticks[i][0], mid = sticks[j][0];
				ll ib = 0, jb = 0;
				while(jb < sticks[j].size()){
					st = sticks[i][ib];
					mid = sticks[j][jb];
					ll find = max(mid+1LL-st, st+1LL-mid);
					ll pos = lower_bound(all(sticks[k]), find) - sticks[k].begin();
					//cout << st << " " << mid << " " << sticks[k][pos] << ed;
					if(st+mid > sticks[k][pos] && sticks[k][pos] >= find){
						//cout << find << ed;
						cout << i+1 << " " << st << " " << j+1 << " " << mid << " " << k+1 << " " << sticks[k][pos];
						return 0;
					}
					if(ib+1 < sticks[i].size() && sticks[i][ib] < sticks[j][jb]) ib++; // <
					else jb++;
				}
			}
		}
	}
	
	cout << "NIE";
	return 0;
	
}
