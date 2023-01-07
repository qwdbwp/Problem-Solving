import sys
input = sys.stdin.readline  # 입력 받는 속도 향상

N, K = map(int, input().split())

W, V = [0], [0]  # 인덱싱을 위해 0이 들어있는 리스트로 초기화

for i in range(N):
    w, v = map(int, input().split())
    W.append(w)
    V.append(v)

# DP[i][j] = 용량을 j만큼 사용하면서 첫 i개의 물건의 가장 가치가 높은 부분집합
# 1 <= j <= K, 1 <= i <= N

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]  # dp 배열 초기화

for i in range(N+1):
    for j in range(K+1):
        if i == 0 or j == 0:
            dp[i][j] = 0    # 0번째 열, 0번째 행은 0으로 초기화
            continue
# 최대무게보다 현재무게가 더 크면 현재 물건을 추가하지 않고 전 칸 가치 그대로
        if j - W[i] < 0:
            dp[i][j] = dp[i-1][j]
        else:
            # 최대무게보다 현재무게가 작거나 같으면 현재 물건을 추가했을 때의 가치와
            # 현재 물건을 위한 무게를 비웠을 때의 가치에 현재 물건 가치를 더한 것 중 큰 값
            dp[i][j] = max(dp[i-1][j], V[i]+dp[i-1][j-W[i]])

print(dp[N][K])
