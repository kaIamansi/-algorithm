class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        boolean[] check = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(check[i] == false) {
                netCheck(n, i, computers, check);
                answer++;
            }
        }
        
        return answer;
    }
    
    public void netCheck(int n, int idx, int[][] computers, boolean[] check) {
        check[idx] = true;
        
        for(int i = 0; i < n; i++) {
            if(check[i] == false && idx != i && computers[idx][i] == 1) {
                netCheck(n, i, computers, check);
            }
        }
    }   
}
//////////////////////////////////////////////////////////////////////////////////////////////////
/* ���� �õ�
class Solution {
    public int solution(int n, int[][] computers) {
        int answer = n;
        
        for(int i = 0; i < n; i++) {
            for(int j = i;  j < n; j++) {
                if(computers[i][j] == 1 && i != j) {
                    answer--;
                    computers[j][j] = 0;    //���� �ߺ��� ���ֱ� ���� �־�����, ������ ��Ȳ������ ����
                }
            }
        }
        
        return answer;
    }
}
*/