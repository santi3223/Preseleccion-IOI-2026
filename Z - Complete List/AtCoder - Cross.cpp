//22 de Enero 2026 22:25
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
	ll h, w;
	cin >> h >> w;
	ll n = min(h, w);
	vector<string> arr(h);
	ff(i, 0, h) cin >> arr[i];
	vl ans(n, 0);
	ff(i, 1, h-1){
		ff(j, 1, w-1){
			if(arr[i][j] == '#' && arr[i-1][j-1] == '#' && arr[i-1][j+1] == '#' && arr[i+1][j-1] == '#' && arr[i+1][j+1] == '#'){
				ff(x, 2, n){
					if(i+x >= h || j+x >= w || arr[i+x][j+x] != '#'){
						ans[x-2]++;
						break;
					}
				}
			}
		}
	}
	ff(i, 0, n){
		cout << ans[i] << " ";
	}
}

