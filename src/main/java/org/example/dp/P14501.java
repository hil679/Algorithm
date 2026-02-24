package org.example.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class P14501 {
    public static int n;
    public static int schedule[][] = new int[16][2];
    public static int dp[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            schedule[i][0] = Integer.parseInt(st.nextToken());
            schedule[i][1] = Integer.parseInt(st.nextToken());
        }

//        if (schedule[1][0] > n) { => 있으면 안 됨, 2일째 일 받을 수도 있으니까
//            System.out.println(0);
//            return;
//        }


        dp = new int [n+1];
//        dp[1] = schedule[1][0];
        for (int i = 1; i <= n; i++) {
            solve(0, i);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
//            System.out.println(dp[i]);
        }
        System.out.println(ans);
    }

    public static void solve(int curValue, int curDate) {
        if (curDate > n) return;
        int endDate = curDate + schedule[curDate][0] - 1;
        if (endDate > n) return;
        dp[curDate] = max(dp[curDate], curValue + schedule[curDate][1]);
//        if (endDate <= n)
        for (int i = endDate+1; i<=n; i++) {
            solve(dp[curDate], i);
        }
    }
}
