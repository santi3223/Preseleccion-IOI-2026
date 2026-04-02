//13 de Marzo 2026 16:51
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
#define ed endl
#define vs vector<string>

int main(){
	ll n, m, q;
	cin >> n >> m >> q;
	vector<vl> grid(n+5, vl(m+5, 0));
	ff(i, 1, n+1){
		ff(j, 1, m+1){
			char c;
			cin >> c;
			grid[i][j] = c-'0';
		}
	}
	
	vector<vl> pref(n+5, vl(m+5, 0));
	ff(i, 1, n+1){
		ff(j, 1, m+1){
			pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
			if(grid[i][j]){
				if(!grid[i-1][j] && !grid[i][j-1]){
					pref[i][j]++;
				}
				if(grid[i-1][j] && grid[i][j-1]){
					pref[i][j]--;
				}
			}
		}
	}
	
	vector<vl> hpref(n+5, vl(m+5, 0)), vpref(n+5, vl(m+5, 0));
	ff(i, 1, n+1){
		ff(j, 1, m+1){
			hpref[i][j] = hpref[i][j-1];
			vpref[i][j] = vpref[i-1][j];
			if(grid[i][j]){
				hpref[i][j] += !grid[i][j-1];
				vpref[i][j] +=  !grid[i-1][j];
			}
		}
	}
	while(q--){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll ok = grid[a][b];
		
		ok += hpref[a][d]-hpref[a][b];
		ok += vpref[c][b]-vpref[a][b];
		ok += pref[c][d]-pref[a][d]-pref[c][b]+pref[a][b];
		cout << ok << ed;
	}
	
}
