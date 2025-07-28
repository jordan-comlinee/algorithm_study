#include <string>
#include <vector>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

bool isInRange(int x, int y, int c, int r)
{
    return (0 <= x && x < c && 0 <= y && y < r);
}

int checkDir(char d)
{
    switch (d)
    {
    case 'N':
        return 0;
        break;
    case 'S':
        return 1;
        break;
    case 'W':
        return 2;
        break;
    case 'E':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0);
    int c = park.size();
    int r = park[0].size();
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            if (park[i][j] == 'S')
            {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    for (auto route : routes)
    {
        int k = route[2] - '0';
        int d = checkDir(route[0]);
        int nx = answer[0];
        int ny = answer[1];
        bool valid = true;
        for (int i = 0; i < k; ++i)
        {
            nx += dx[d];
            ny += dy[d];
            if (!isInRange(nx, ny, c, r) || park[nx][ny] == 'X')
            {
                valid = false;
                break;
            }
        }

        if (valid) {
            answer[0] = nx;
            answer[1] = ny;
        }
    }
    return answer;
}