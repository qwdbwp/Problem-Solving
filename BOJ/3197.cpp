#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); // 입력 속도 향상

    int R, C, ans = 0;
    string map[1501];        // 호수를 나타낼 문자열 배열
    int visited[1501][1501]; // BFS에서 방문여부 체크할 배열
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};         // 상하좌우 확인을 위한 좌표
    queue<pair<int, int>> find, water; // 백조를 찾는 데 쓰이는 find, 얼음 녹이는 데 쓰이는 water
    // find = 현재 물이면서, 백조가 전에 탐색해 보지 않았던 곳; water = 현재 물인 곳
    vector<pair<int, int>> swan; // 백조의 위치를 나타앨 벡터

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '.')
                water.push(make_pair(i, j)); // 물이면 water에 push
            else if (map[i][j] == 'L')
            {
                water.push(make_pair(i, j));     // 백조면 얼음이 아니기 때문에 water에 push
                swan.push_back(make_pair(i, j)); // 백조 좌표 swan에 넣기
                map[i][j] = '.';                 // map 물로 바꿔주기
            }
        }
    }

    find.push(swan[0]); // 첫번째 백조 큐에 넣어서 탐색 시작
    visited[swan[0].first][swan[0].second] = 1;

    while (1)
    {
        queue<pair<int, int>> f_tmp, w_tmp; // 중복 탐색을 방지하기 위해 다음에 물로 바뀌는 좌표들만 저장
        // BFS로 백조가 갈 수 있는 모든 길 탐색
        while (!find.empty())
        {
            int x = find.front().first;
            int y = find.front().second;
            find.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny])
                {
                    continue; // 인덱스를 벗어나거나 이미 방문했으면 넘어감
                }
                else if (swan[1] == make_pair(nx, ny))
                {
                    cout << ans; // 백조 찾았으면 걸린 시간 출력하고 종료
                    return 0;
                }
                else if (map[nx][ny] == 'X')
                {
                    f_tmp.push(make_pair(nx, ny));
                    // 지금은 얼음이지만 다음에는 물이므로 다음에 탐색하기 위해 임시 큐에 push
                }
                else
                    find.push(make_pair(nx, ny)); // 방문하지 않은 물 좌표면 현재 큐에 push해서 탐색

                visited[nx][ny] = 1;
            }
        }
        find = f_tmp; // 다음 탐색 좌표가 담긴 큐로 바꿔주기
        ans++;
        // 물 상하좌우 좌표를 녹이는 BFS
        while (!water.empty())
        {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                {
                    continue;
                }
                else if (map[nx][ny] == 'X')
                {
                    w_tmp.push(make_pair(nx, ny));
                    map[nx][ny] = '.';
                    // 지금은 얼음이지만 다음은 물이고 방문하지 않았으므로 다음에 탐색하기 위해 임시 큐에 push
                }
            }
        }
        water = w_tmp; // 다음 탐색을 위해 큐 바꿔주기
    }
}