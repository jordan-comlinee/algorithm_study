#include <string>
#include <vector>
using namespace std;

const int ATTACK = 1;
const int HEAL = 2;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int R = board.size();
    int C = board[0].size();

    // �������� ���� ���� �迭 (R+2 �� C+2 ����ϸ� ����)
    vector<vector<int>> diff(R + 2, vector<int>(C + 2, 0));

    // ��ų ���� (���� �迭�� ����)
    for (auto s : skill) {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];

        if (type == ATTACK) degree = -degree;

        diff[r1][c1] += degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }

    // ���� ������
    for (int i = 0; i < R + 1; ++i) {
        for (int j = 1; j < C + 1; ++j) {
            diff[i][j] += diff[i][j - 1];
        }
    }

    // ���� ������
    for (int j = 0; j < C + 1; ++j) {
        for (int i = 1; i < R + 1; ++i) {
            diff[i][j] += diff[i - 1][j];
        }
    }

    // ���� board ��� �� answer ī��Ʈ
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            board[i][j] += diff[i][j];
            if (board[i][j] > 0) answer++;
        }
    }

    return answer;
}
