//10 de Julio 2026 20:57
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
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
	vector<vl> ans(n, vl(n, -1));
	vector<vb> col(n, vb(2*n, 0)), row = col;
	ff(i, 0, n){
		col[i][i] = row[i][i] = col[i][0] = row[i][0] = 1;
		ans[i][0] = ans[0][i] = i;
		ans[i][i] = 0;
		
	}
	ff(i, 2, n){
		ff(j, 1, i){
			ff(k, 0, 2*n){
				if(row[i][k] == 0 && col[j][k] == 0){
					row[i][k] = col[j][k] = col[i][k] = row[j][k] = 1;
					ans[i][j] = ans[j][i] = k;
					break;
				}
			}
		}
	}
	ff(i, 0, n){
		ff(j, 0, n) cout << ans[i][j] << ' ';
		cout << ed;
	}
	
}
