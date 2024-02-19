#include <bits/stdc++.h>
using namespace std;
#define MAX 1010

int m, n;
char costa[MAX][MAX];
int di[] = { -1,  0,  0,  1 };
int dj[] = {  0, -1,  1,  0 };
int main(){
	int i, j, k, ii, jj;
	int cnt;
	scanf("%d %d ", &m, &n);
	for(i = 0; i < m; i++){
		fgets(costa[i], MAX, stdin);
		costa[i][n] = 0;
	}
	cnt = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(costa[i][j] == '.') continue;
			for(k = 0; k < 4; k++){
				ii = i+di[k];
				jj = j+dj[k];
				if((!(0 <= ii && ii < m && 0 <= jj && jj < n)) || costa[ii][jj] == '.'){
					cnt++;
					break;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}