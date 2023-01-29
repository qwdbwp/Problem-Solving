#include <iostream>
#include <limits.h> // INT_MAX를 이용하기 위해 헤더 불러오기
#include <algorithm>

using namespace std;

// DP[a][b] = a번째부터 b번째까지 페이지를 합친 최솟값
// cost[a] = a번째까지의 페이지 누적합
// cost[b] - cost[a-1] = a번째부터 b번째까지의 페이지 누적합
// DP[a][a] = page[a] = cost[a] - cost[a-1]
// DP[a][a+1] = page[a] + page[a+1]
// DP[a][b] = min(DP[a][m]+ DP[m+1][b] + cost[b] - cost[a-1], DP[a][b]) (a <= m < b)

int DP[501][501], page[501], cost[501]; // 전역변수로 선언해야 0으로 초기화되기 때문에 다 전역변수로 선언해야 함
int T, K;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); // 입출력 속도 향상
	
	cin >> T;
	
	while (T--){
		cin >> K;
		for (int i = 1; i <= K; i++){
			cin >> page[i];		// 페이지 값 넣어주기
			cost[i] = cost[i-1] + page[i];	// 지금까지의 누적합 넣어주기
		}
		for (int i = 1; i <= K; i++){
			for (int j = 1; j <= K-i; j++){
				DP[j][i+j] = INT_MAX;	// 최솟값을 계산해야 하기 때문에 최댓값으로 초기화
				for (int m = j; m < i+j; m++){
					DP[j][i+j] = min(DP[j][m] + DP[m+1][i+j] + cost[i+j] - cost[j-1], DP[j][i+j]);
					// 점화식 그대로 사용
				}
			}
		}
		cout << DP[1][K] << '\n'; // DP[1][K] = 1번째부터 K번째까지 페이지를 합친 최솟값 출력
	}
	
	return 0;
}