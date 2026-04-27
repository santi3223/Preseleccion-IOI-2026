//22 de Enero 2026 22:13
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

ll h, w;
vector<string> arr, b;

bool check(ll s, ll t){
	ff(i, 0, h){
		ff(j, 0, w){
			if(arr[(i+s)%h][(j+t)%w] != b[i][j]) return false;
		}
	}
	return true;
}

int main(){
	cin >> h >> w;
	arr = vector<string>(h);
	b = vector<string>(h);
	ff(i, 0, h) cin >> arr[i];
	ff(i, 0, h) cin >> b[i];
	ff(s, 0, h){
		ff(t, 0, w){
			if(check(s, t)){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
