#include <iostream>
#include <limits.h> // LONG_MAX 사용을 위해 헤더 불러오기
#include <algorithm> // min 사용을 위해 헤더 불러오기
#include <vector>

using namespace std;

// 행렬 곱은 무조건 순서대로 해야 함
// DP[a][b] = a번째 행렬부터 b번째 행렬까지의 곱에 필요한 곱셈 연산의 최솟값
// DP[a][a] = 0
// DP[a][a+1] = a.r * a.c * (a+1).c = a.r * (a+1).r * (a+1).c
// DP[a][b] = a~b를 k 기준으로 둘로 나누어 a~k까지의 최소 곱셈 연산 + k+1~b까지의 최소 곱셈 연산 + a행렬의 행 * k행렬의 열 * b헹렬의 열의 최솟값
// DP[a][b] = min(DP[a][k] + DP[k+1][b] + a.r * k.c * b.c, DP[a][b]) (a <= k < b)

int N;
vector<pair<long int, long int>> matrix(501); // 행렬 선언
vector<vector<long int>> DP(501, vector<long int>(501,LONG_MAX)); // DP를 LONG_MAX로 초기화

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); // 입출력 속도 향상
	
	cin >> N;
	
	for (int i = 1; i <= N; i++){
		cin >> matrix[i].first >> matrix[i].second; // 행렬의 행과 열 받기
		DP[i][i] = 0; // 하나만 계산할 경우 곱셈 횟수는 0
		DP[i-1][i] = matrix[i-1].first * matrix[i].first * matrix[i].second;
		// 두 개의 행렬곱일 경우 앞 행렬의 행 * 뒤 행렬의 행 * 뒤 행렬의 열
	}
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N-i; j++){
			for (int k = j; k < i+j; k++){
				DP[j][i+j] = min(DP[j][i+j], DP[j][k] + DP[k+1][i+j] + matrix[j].first * matrix[k].second * matrix[i+j].second);
				// 점화식 그대로 사용
			}
		}
	}
	cout << DP[1][N]; // 1번째 행렬부터 N번째 행렬까지의 곱에 필요한 최소 곱셈 연산
}
