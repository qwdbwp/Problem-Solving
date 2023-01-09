#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, a, max_val, min_val;
    cin >> N;

    priority_queue<int> max_queue;                            // 우선순위 큐 사용
    priority_queue<int, vector<int>, greater<int>> min_queue; // 내림차순 우선순위 큐 정의
    // 우선순위 큐 선언 방식: priority_queue<type, container, compare> name;

    // 최대큐의 크기 - 최소큐의 크기 = 1
    // 최소큐의 top() >= 최대큐의 top()
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (max_queue.size() == min_queue.size())
        {
            max_queue.push(a); // 두 큐의 크기가 같으므로 최대큐에 삽입
        }
        else
        {
            min_queue.push(a); // 크기가 다르면 최소큐에 삽입
        }
        if (max_queue.size() && min_queue.size() && max_queue.top() > min_queue.top())
        {
            // 두 큐에 값이 있는데 최대큐의 top이 최소큐의 top보다 크면 두 큐의 top을 바꿔 줌
            max_val = max_queue.top();
            min_val = min_queue.top();
            max_queue.pop();
            min_queue.pop();
            max_queue.push(min_val);
            min_queue.push(max_val);
        }
        cout << max_queue.top() << '\n'; // 최대힙의 top이 중간값에 해당
    }
}