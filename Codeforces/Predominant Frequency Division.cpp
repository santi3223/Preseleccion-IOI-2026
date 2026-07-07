//6 de Julio 2026 11:03
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		vl q1(3, 0), q2(3, 0);
		ff(i, 0, n-2){
			q1[arr[i]-1]++;
		}
		q2[arr[n-2]-1]++;
		ll l = n-3, r = n-2;
		bool ok = false;
		//cout << l << ' ' << r << ed;
		while(l >= 0){
			while(l >= 0 && q1[0] < q1[1]+q1[2]){
				q1[arr[l]-1]--;
				q2[arr[l]-1]++;
				l--;
			}
			if(l < 0) break;
			while(l < r && q2[0]+q2[1] < q2[2]){
				q2[arr[r]-1]--;
				r--;
			}
			if(q1[0] >= q1[1]+q1[2] && q2[0]+q2[1] >= q2[2] && q1[0]+q1[1]+q1[2] > 0 && q2[0]+q2[1]+q2[2] > 0 && l < r && r < n-1){
				/*cout << "FIN" << ed;
				cout << l << ' ' << r << ed;
				cout << q1[0] << ' ' << q1[1] << ' ' << q1[2] << ed;
				cout << q2[0] << ' ' << q2[1] << ' ' << q2[2] << ed;
				cout << "====================" << ed;*/
				ok = true;
				break;
			}
			/*cout << l << ' ' << r << ed;
			cout << q1[0] << ' ' << q1[1] << ' ' << q1[2] << ed;
			cout << q2[0] << ' ' << q2[1] << ' ' << q2[2] << ed;
			
			cout << "+++++++++++++++++++++" << ed;*/
			q1[arr[l]-1]--;
			q2[arr[l]-1]++;
			l--;
		}
		cout << (ok ? "YES" : "NO") << ed;
		
	}
}
