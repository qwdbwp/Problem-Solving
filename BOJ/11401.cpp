#include <iostream>
using namespace std;

#define mod 1000000007

// 이항계수 공식 nCk = n!/{k!(n-k)!} = {n*(n-1)*...*(n-k+1)}/k!
// 나머지연산 분배법칙 (A*B)%C = (A%C * B%C)%C
// 페르마의 소정리: a^p ≡ a(mod p), a^(p-1) ≡ 1(mod p), a^(p-2) ≡ a^(-1)(mod p)
//                 (a는 정수, p는 소수)

// 분할정복을 이용한 거듭제곱 계산
long long pow(long long N, long long K) {
    long long ans = 1;
    while(K){
        if (K % 2){
            ans = (ans * N) % mod;
        }
        N = (N * N) % mod;
        K /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);   
    cin.tie(0);

    long long N, K;
    cin >> N >> K;

    long long A = 1, B = 1; 

    // A = n*(n-1)*...*(n-k+1), B = k!
    for (int i = N; i > N - K + 1; i--)
        A = (A * i) % mod;
    for (int i = 1; i < K; i++)
        B = (B * i) % mod;

    cout << A * pow(B, mod - 2) % mod; // A/B % P = AB^(-1)%P = AB^(P-2)%P

    return 0;
}