from collections import deque


def solution(queue1, queue2):
    queue1 = deque(queue1)
    queue2 = deque(queue2)  # 두 리스트를 큐로 만들기
    sum1 = sum(queue1)
    sum2 = sum(queue2)
    total = sum1 + sum2  # 각 큐의 총합과 둘의 원소 합 구하기
    n = len(queue1)  # 예외처리를 위한 n 구하기
    answer = 0  # 정답 초기화

    if total % 2:  # 총합이 짝수라면 같게 만들 수 없으므로 -1 리턴
        return -1

    while sum1 != sum2 and answer <= 3 * n:  # 두 합이 같거나 3n을 넘으면 stop
        if sum1 > sum2:
            l = queue1.popleft()
            queue2.append(l)
            sum1 -= l
            sum2 += l
        else:
            l = queue2.popleft()
            queue1.append(l)
            sum1 += l
            sum2 -= l
        answer += 1

    return answer if answer <= 3*n else -1
