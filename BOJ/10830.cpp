#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix; // 2차원 vector를 matrix로 type 정의

void print_matrix(const matrix& A){ // 행렬 출력 함수
    int N = A.size();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}

matrix operator * (const matrix& A, const matrix& B){ // operator overloading, 연산자 재정의
    int N = A.size(); 
    matrix result(N, vector<long long>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for (int k = 0; k < N; k++){
                result[i][j] += A[i][k] * B[k][j]; // 행렬곱 계산
            }
            result[i][j] %= 1000; // 1000으로 나눈 나머지
        }
    }
    return result;
}

matrix power(matrix A, matrix I, int N, long long B){ // 행렬 제곱 계산 함수
    matrix result(N, vector<long long>(N));
	result = I; // identity matrix로 초기화
    // while문을 이용한 분할정복 거듭제곱 이용
    while (B){
        if (B % 2)
            result = result * A; // 연산자 재정의를 했기 때문에 *= 와 같은 형태 사용 불가능
        B /= 2;
        A = A * A;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); // 입출력 속도 향상

    int N;
    long long B;
    cin >> N >> B;
    matrix A(N, vector<long long>(N)); // N행 N열 행렬 선언
    matrix I(N, vector<long long>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j]; 
        }
        I[i][i] = 1;    // identity matrix 만들기
    }
	print_matrix(power(A, I, N, B)); // 행렬 거듭제곱 결과 출력
    return 0;
}