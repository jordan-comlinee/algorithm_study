#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {

    long long answer = 0;

    for (int x = 1; x <= r2; ++x)
    {

        long long maxY = (long long)(sqrt((long long)r2 * r2 - (long long)x * x));
        long long minY = 0;

        if (x < r1)
        {
            minY = (long long)ceil(sqrt((long long)r1 * r1 - (long long)x * x));
        }

        //x�� ���� 1��и� ���� ���� ��� �⸴ x=0�϶��� ���� (x 4���ϱ� ���ؼ�)

        answer += (maxY - minY + 1);

        //������ ���ο��� �ִ� ���� ���ְ�, �ߺ����� ���� 1����ŭ ���ϱ�
    }
    return answer * 4;

    //1��и鿡���� ��� �߱� ������ 4��
}
