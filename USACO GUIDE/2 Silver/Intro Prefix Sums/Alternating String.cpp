//30 de marzo 2026 16:06

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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		string arr;
		cin >> n >> arr;
		vector<vl> odd(n, vl(26, 0)), even(n, vl(26, 0));
		even[0][arr[0]-'a']++;
		ff(i, 1, n){
			ff(j, 0, 26){
				even[i][j] = even[i-1][j];
				odd[i][j] = odd[i-1][j];
			}
			if(i % 2 == 0) even[i][arr[i]-'a']++;
			else odd[i][arr[i]-'a']++;
		}
		ll minn = n+5;
		
		if(n % 2 == 0){ //no se puede reducir
			ff(a, 0, 26){
				ff(b, 0, 26){
					ll v1 = n/2-even[n-1][a], v2 = n/2-odd[n-1][b];
					minn = min(minn, v1+v2);
				}
			}
			cout << minn;
		}
		else{
			ff(delet, 0, n){
				ff(a, 0, 26){
					ff(b, 0, 26){
						ll lef_even = 0, lef_odd = 0;
						if(delet != 0){
							lef_even = even[delet-1][a];
							lef_odd = odd[delet-1][b];
						}
						ll lef = lef_even+lef_odd;
						
						ll rig_even = 0, rig_odd = 0;
						rig_even = odd[n-1][a]-odd[delet][a];
						rig_odd = even[n-1][b]-even[delet][b];
						ll rig = rig_even+rig_odd;
						minn = min(minn, n-1-(lef+rig));
					}
				}
			}
			cout << minn+1;
			
		}
		cout << ed;
	}
	
}
