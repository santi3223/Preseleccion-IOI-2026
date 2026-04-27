//23 de Enero 2026 18:03
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
	ll h, w, q;
	cin >> h >> w >> q;
	vector<string> arr(h, string(w, '.'));
	ll i = 0, j = 0, dir = 0;// u r d l = 0 1 2 3
	while(q--){
		if(arr[i][j] == '.'){
			arr[i][j] = '#';
			dir++;
			dir %= 4;
			if(dir == 0){
				i--;
				i += h;
				i %= h;
			}
			if(dir == 1){
				j++;
				j %= w;
			}
			if(dir == 2){
				i++;
				i %= h;
			}
			if(dir == 3){
				j--;
				j += w;
				j %= w;
			}
		}
		else{
			arr[i][j] = '.';
			dir--;
			dir += 4;
			dir %= 4;
			if(dir == 0){
				i--;
				i += h;
				i %= h;
			}
			if(dir == 1){
				j++;
				j %= w;
			}
			if(dir == 2){
				i++;
				i %= h;
			}
			if(dir == 3){
				j--;
				j += w;
				j %= w;
			}
		}
	}
	ff(id, 0, h){
		cout << arr[id] << ed;
	}
}
