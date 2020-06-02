#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int depth = 0;
    int sip = 0;
    vector<int> box = { 0 };
    for (int i = 0; i < moves.size(); i++) // ���� �̱⸸ŭ ȸ�� 
    {
        sip = moves[i] - 1;
        // cout << "�̹� sip���� " << sip << endl;
        while (1)
        {
            if (depth == board.size())
            {
                depth = 0;
                break;
            }
            else if (board[depth][sip] == 0)
            {
                depth++;
            }
            else if (box.back() == board[depth][sip]) { // �ڽ��� ����ִ� ������ ���� ������ ��ĥ ��
                // cout << "box�� �־ ���� ������: " << box.back() << endl;
                box.pop_back();
                answer += 2;
                // cout << "�� ���� ��������: " << answer << endl;
                board[depth][sip] = 0;
                depth = 0;
                break;
            }
            else // ��ġ�� �ʾ��� �� ���� ���� box�� �ְ� break�� ����
            {
                box.push_back(board[depth][sip]);
                board[depth][sip] = 0;
                // cout << "box�� ���� ������: " << box.back() << endl;    
                depth = 0;
                break;
            }
        }
    }

    return answer;
}