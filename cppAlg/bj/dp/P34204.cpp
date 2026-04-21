#include <stdio.h>
#include <stdlib.h> // qsort 함수를 위해 필요

// 제약 조건에 따른 최대 크기로 전역 배열 선언
// N <= 5000, C <= 1,000,000
int A[5001]; // 각 물건 무게
long long prefix_sum[5002]; // 무게 누적합
long long dp[1000001]; // 훔친 물건 최대 dp

// qsort를 위한 비교 함수
int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

// 두 long long 값 중 더 큰 값을 반환하는 함수
long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    // 입력을 받기 위한 변수 선언
    int N, K, C;
    scanf("%d %d %d", &N, &K, &C);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    // 1. 물건 무게를 오름차순으로 정렬
    qsort(A, N, sizeof(int), compare);
//5 1 6
//1 2 3 4 5
    // 2. 누적 합 배열 생성
    // 1 3 6 10 15
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    // 상훈이가 아무것도 챙기지 않는 경우 (m = 0)
    if (K <= N) {
        dp[0] = prefix_sum[K];
    }

    // 4. 상훈이가 m개의 물건을 챙기는 경우 계산
    for (int m = 1; m <= N - K; ++m) {
        long long bag_weight = prefix_sum[m]; // 상훈이가 미리 가져간 물건 무게
        if (bag_weight > C) {
            break;
        }
        long long stolen_weight = prefix_sum[m + K] - prefix_sum[m]; // 훔친 물건 무게
        dp[bag_weight] = stolen_weight; //max(dp[bag_weight], stolen_weight); // 기존 값과 새로 훔친 물건 무게 값
    }

    // 5. "용량 x 이하" 조건 처리
    // 가방 무게를 **정확히 i**로 맞췄을 때의 결과(dp[i])와 (정확히 i조합 없을 수도)
    // 가방 무게를 i-1 이하로 맞췄을 때
    for (int i = 1; i <= C; ++i) {
        dp[i] = max(dp[i], dp[i-1]);
    }

    // 6. 결과 출력
    for (int i = 1; i <= C; ++i) {
        printf("%lld\n", dp[i]);
    }

    return 0;
}