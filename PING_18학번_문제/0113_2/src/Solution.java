//체육복
//https://programmers.co.kr/learn/courses/30/lessons/42862?language=java#
import java.util.Arrays;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int l = 0, r = 0;
        
        Arrays.sort(lost);
        Arrays.sort(reserve);
        
        while(l < lost.length && r < reserve.length)
        {
        	if (lost[l] == reserve[r])
        	{
        		lost[l] = -1;
        		reserve[r] = -1;
        		l++;
        		r++;
        	}
        	else if (lost[l] > reserve[r])
        		r++;
        	else
        		l++;
        }
        
        r = 0;
        l = 0;
        
        while(l < lost.length && r < reserve.length)
        {
        	if (lost[l] == -1)
        		l++;
        	else if (reserve[r] == -1)
        		r++;
        	else if ((lost[l]- reserve[r]) == -1 || (lost[l]- reserve[r]) == 1 || lost[l] == reserve[r])
        	{
        		answer++;
        		l++;
        		r++;
        	}
        	else if (lost[l] > reserve[r])
        		r++;
        	else
        		l++;
        }
        
        answer += n - lost.length;
        return answer;
    }
}

/*
 * 모범답안
 * class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] people = new int[n];
        int answer = n;

        for (int l : lost) 
            people[l-1]--;
        for (int r : reserve) 
            people[r-1]++;

        for (int i = 0; i < people.length; i++) {
            if(people[i] == -1) {
                if(i-1>=0 && people[i-1] == 1) {
                    people[i]++;
                    people[i-1]--;
                }else if(i+1< people.length && people[i+1] == 1) {
                    people[i]++;
                    people[i+1]--;
                }else 
                    answer--;
            }
        }
        return answer;
    }
}
 */
