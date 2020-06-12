#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int num = 9;
    queue<pair<int, int>> q1;
    priority_queue<int> q2;

    for (int i = 0; i < priorities.size(); i++) {
        q1.push(make_pair(i, priorities[i]));
        // i��° ���� �ε����� i�� ���� ���� ����
        q2.push(priorities[i]);
    }
    while (!q1.empty()) {
        int i = q1.front().first; // �ε���
        int j = q1.front().second; // ��
        q1.pop();

        if (j == q2.top()) {
            q2.pop();
            answer++;

            if (i == location) {
                break;
            }
        }
        else {
            q1.push(make_pair(i, j));
        }
    }

    return answer;
}