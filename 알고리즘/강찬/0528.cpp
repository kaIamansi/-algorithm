#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    //string answer = "";
    //unordered_map<string, int> hashmap1;
    //for (int i = 0; i < participant.size(); i++)
    //{
    //    hashmap1.insert(unordered_map<string, int>::value_type(participant[i], i));
    //    // �̸�, ��ȣ�� ����
    //}

    //for (int i = 0; i < completion.size(); i++)
    //{
    //    hashmap1.erase(completion[i]);
    //}

    //answer = hashmap1.begin()->first;

    //return answer;

    // ���� ���� �ڵ�

    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            // answer ���ٲ�°� ������ ������ ����
            break;

        }
    }
    return answer;
}

int main()
{
    vector<string> vec1, vec2;
    vec1.push_back("leo");
    vec1.push_back("kiki");
    vec1.push_back("eden");
    vec2.push_back("eden");
    vec2.push_back("kiki");
    cout << solution(vec1, vec2) << endl;
}