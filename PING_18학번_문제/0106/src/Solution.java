//K번째 수 
//https://programmers.co.kr/learn/courses/30/lessons/42748?language=java#

class Solution {

    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for (int n = 0; n < commands.length; n++)
        {
            int index = 0;
            int[] ans = new int[commands[n][2]];

            for (int i = commands[n][0] - 1; i < commands[n][1]; i++)
            {
                if (index == 0)
                    ans[index++] = array[i];
                else if (index < commands[n][2])
                {
                    int num = array[i];
                    int t;
                    for (int j = 0; j <= index; j++)
                        if (ans[j] > num)
                        {
                            t = num;
                            num = ans[j];
                            ans[j] = t;
                        }

                    ans[index] = num;
                    index++;
                }
                else
                {
                    int num = array[i];
                    int t;
                    for (int j = 0; j < index; j++)
                        if (ans[j] > num)
                        {
                            t = num;
                            num = ans[j];
                            ans[j] = t;
                        }
                }
            }           
            answer[n] = ans[commands[n][2] - 1];
        }

        return answer;

    }
}

/*
 * 2차원 배열 크기 반환
 * arr = new int[3][4]
 * arr.length 줄의 개수 = 3
 * arr[0].length 줄의 배열 개수 = 4
 */

/*
 * 모범 답안
 import java.util.Arrays;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for(int i=0; i<commands.length; i++){
            int[] temp = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
            Arrays.sort(temp);
            answer[i] = temp[commands[i][2]-1];
        }

        return answer;
    }
}
 * 
 */