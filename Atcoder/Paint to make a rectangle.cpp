//23 de Enero 2026 16:08
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
	vector<string> arr(h);
	ll xmin = LLONG_MAX, ymin = LLONG_MAX, xmax = LLONG_MIN, ymax = LLONG_MIN;
	ff(i, 0, h){
		cin >> arr[i];
		ff(j, 0, w){
			if(arr[i][j] == '#'){
				xmin = min(xmin, j);
				ymin = min(ymin, i);
				xmax = max(xmax, j);
				ymax = max(ymax, i);
			}
		}
	}
	ff(i, ymin, ymax+1){
		ff(j, xmin, xmax+1){
			if(arr[i][j] == '.'){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";

}
