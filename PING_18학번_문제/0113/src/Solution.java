//모의고사
//https://programmers.co.kr/learn/courses/30/lessons/42840?language=java

class Solution {
    public int[] solution(int[] answers) {
        int n = answers.length;
        int n1[] = {1, 2, 3, 4, 5};
        int n2[] = {2, 1, 2, 3, 2, 4, 2, 5};
        int n3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int c1 = 0, c2 = 0, c3 = 0;
        
        for (int i = 0; i < n; i++)
        {
        	if (n1[i % 5] == answers[i])
        		c1++;
        	if (n2[i % 8] == answers[i])
        		c2++;
        	if (n3[i%10] == answers[i])
        		c3++;
        }
        
        int max = c1;
        int index = 1;
        
        if (max == c2)
        	index++;
        else if (max < c2)
        	max = c2;
        
        if (max == c3)
        	index++;
        else if (max < c3)
        {
        	index = 1;
        	max = c3;
        }
        
        int answer[] = new int[index];
        
        index = 0;
        if(max == c1)
        	answer[index++] = 1;
        if (max == c2)
        	answer[index++] = 2;
        if (max == c3)
        	answer[index++] = 3;
        
        
        return answer;
    }
}

/*
 * max 구하는 법 (짧게)
 * int maxScore = Math.max(score[0], Math.max(score[1], score[2]));
 */