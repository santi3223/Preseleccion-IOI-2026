#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vl> conexiones;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll R, C, K;
	cin >> R >> C >> K;
	ll cr = 0, cc = 0, k = 1;
	bool up = true;
	ll ans = 0;
	bool border = false;
	while(k <= K){
		/*if(cr < 0 || R <= cr || cc < 0 || C <= cc){
			cout << "ERROR" << ed << cr << ' ' << cc << ed;
			cout << k << ' ' << ans << ed << ed;
			ff(i, 0, R){
				ff(j, 0, C){
					cout << trac[i][j] << "   ";
				}
				cout << ed;
			}
			return 0;
		}*/
		//cout << cr << ' ' << cc << ' ' << k << ed;
		//trac[cr][cc] = k;
		
		if((cr & cc) == 0) ans++;
		k++;
		if(k > K) break;
		if(border){
			if(!up){
				//cout << "E" << ed;
				cr++;
				cc--;
			}
			else{
				//cout << "F" << ed;
				cr--;
				cc++;
			}
			border = false;
			continue;
		}
		
		
		if(cr == R-1 && !up){
			//cout << "A" << ed;
			cc++;
			up = true;
			border = true;
		}
		else if(cc == 0 && !up){
			//cout << "B" << ed;
			cr++;
			up = true;
			border = 1;
		}
		else if(cc == C-1 && up){
			//cout << "C" << ed;
			cr++;
			up = false;
			border = 1;
		}
		else if(cr == 0 && up){
			//cout << "D" << ed;
			cc++;
			up = false;
			border = 1;
		}
		else if(!up){
			//cout << "E" << ed;
			cr++;
			cc--;
		}
		else{
			//cout << "F" << ed;
			cr--;
			cc++;
		}
	}
	/*ff(i, 0, R){
		ff(j, 0, C){
			cout << trac[i][j] << "   ";
		}
		cout << ed;
	}
	cout << ed;*/
	cout << ans;
}



VOY AL BANHO
