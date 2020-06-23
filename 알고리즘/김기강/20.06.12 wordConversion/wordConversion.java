class Solution {
    int compare = 0;    //�ɸ� Ƚ�� ����
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] went = new boolean[words.length]; //��Ʈ��ũó�� ���� �� Ȯ�ο�
        
        for(int i = 0; i < words.length; i++) {
            if(words[i].equals(target)) {   //words �迭�� Ÿ���� ������ Ȯ���Ѵ�. ���� �����µ� �����ϱ� �ð��� �������� ����.
                toTarget(begin, target, words, went, 0);
            }
        }
        
        answer = compare;   //�ɸ� Ƚ��
        
        return answer;
    }
    
    public void toTarget(String begin, String target, String[] words, boolean[] went, int count) {
        for(int i = 0; i < words.length; i++) {
            if(begin.equals(target)) {      //�񱳸� ������ �Ͱ� target�� ������ compare�� �ٲ��ش�.
                compare = compare > count ? compare : count;
                //compare = Math.max(compare, count);   //���ϴ� �ٸ� ��� ã�ٰ� Math.max�� �־ ��ô�.
                return;
            }
            
            if(went[i] == true) {   //���� ���̸� �������� �Ѿ��.
                continue;
            }
            
            int check = 0;
            for(int j = 0; j < target.length(); j++) {      //���ڸ� ���Ѵ�.
                if(words[i].charAt(j) != begin.charAt(j)) {
                    check++;
                }
            }
            
            if(check == 1 && went[i] == false) {    //�� ���ڸ� �޶�� �̵� �����ϴ�.
                begin = words[i];
                went[i] = true;
                toTarget(begin, target, words, went, count+1);
            }
        }
        
    }
}