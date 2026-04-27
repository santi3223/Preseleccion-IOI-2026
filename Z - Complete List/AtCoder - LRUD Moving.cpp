//21 de Abril 2026 10:23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, a, b;
		cin >> n >> a >> b;
		if(((a+b) % 2 == 0 && n % 2 == 0) || n % 2 != 0){
			cout << "No" << ed;
			continue;
		}
		cout << "Yes" << ed;
		ll i = 0, j = 0;
		vector<vb> visited(n, vb(n, false));
		visited[a-1][b-1] = 1;
		bool aft = false;
		string sl(n-1, 'L'), sr(n-1, 'R');
		if(a != n){
			while(!(i == n-1 && j == n-1)){
				visited[i][j] = 1;
				/*cout << ed;
				cout << "_//////Visited///////" << ed;
				ff(id, 0, n){
					ff(jd, 0, n){
						cout << visited[id][jd] << ' ';
					}
					cout << ed;
				}
				cout << "/////////////////////" << ed;*/
				bool inn = false;
				if(a-1 <= i && i <= a) inn = true;
				ll qq = 0;
				if(i-1 >= 0 && !visited[i-1][j])qq++;
				if(j-1 >= 0 && !visited[i][j-1])qq++;
				if(j+1 < n && !visited[i][j+1])qq++;
				if(qq == 0){
					cout << 'D';
					i++;
					continue;
				}
				if(i == a+1){ aft = true; break;}
				if(inn){
					if(a % 2 != 0){
						if(a-1 == i){
							if(!visited[i+1][j]){
								cout << 'D';
								i++;
							}
							else{
								cout << 'R';
								j++;
							}
						}
						else{
							if(!visited[i-1][j]){
								cout << 'U';
								i--;
							}
							else{
								cout << 'R';
								j++;
							}
						}
					}
					else{
						if(a-1 == i){
							if(!visited[i+1][j]){
								cout << 'D';
								i++;
							}
							else{
								cout << 'L';
								j--;
							}
						}
						else{
							if(!visited[i-1][j]){
								cout << 'U';
								i--;
							}
							else{
								cout << 'L';
								j--;
							}
						}
					}
				}
				else{
					if(i % 2 == 0){
						cout << sr;
						j = n-1;
						if(i != n-1){
							cout << 'D';
							i++;
						}
					}
					else{
						cout << sl;
						cout << 'D';
						i++;
						j = 0;
					}
					
				}
			}
		}
		else{
			while(!(i == n-1 && j == n-1)){
				//cout << i << ' ' << j << ed;
				visited[i][j] = 1;
				bool inn = false;
				if(a-2 <= i && i <= a-1) inn = true;
				ll qq = 0;
				if(i-1 >= 0 && !visited[i-1][j])qq++;
				if(j-1 >= 0 && !visited[i][j-1])qq++;
				if(j+1 < n && !visited[i][j+1])qq++;
				
				/*cout << ed;
				cout << "_//////Visited///////" << ed;
				ff(id, 0, n){
					ff(jd, 0, n){
						cout << visited[id][jd] << ' ';
					}
					cout << ed;
				}
				cout << "/////////////////////" << ed;*/
				
				if(qq == 0){
					cout << 'D';
					i++;
					continue;
				}
				if(inn){
					if(a-2 == i){
						if(!visited[i+1][j]){
							cout << 'D';
							i++;
						}
						else{
							cout << 'R';
							j++;
						}
					}
					else{
						if(!visited[i-1][j]){
							cout << 'U';
							i--;
						}
						else{
							cout << 'R';
							j++;
						}
					}
				}
				else{
					if(i % 2 == 0){
						cout << sr;
						cout << 'D';
						i++;
						j = n-1;
					}
					else{
						cout << sl;
						cout << 'D';
						i++;
						j = 0;
					}
					
				}
			}
		}
		
		if(aft){
			while(!(i == n-1 && j == n-1)){
				if(j == n-1){
					cout << sl;
					cout << 'D';
					i++;
					j = 0;
				}
				else{
					cout << sr;
					j = n-1;
					if(i != n-1){
						cout << 'D';
						i++;
					}
				}
			}
		}
		/*cout << ed;
			cout << "_//////Visited///////" << ed;
			ff(id, 0, n){
				ff(jd, 0, n){
					cout << visited[id][jd] << ' ';
				}
				cout << ed;
			}
			cout << "/////////////////////" << ed;
		cout << i << ' ' << j << ' ' << 'F';*/
		cout << ed;
	}
}
