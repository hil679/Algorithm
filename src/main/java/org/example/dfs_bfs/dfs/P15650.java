package org.example.dfs_bfs.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P15650 {
    static int n;
    static int m;
    static int arr[] = new int [9]; //1~m번째 사용 n까지 커짐
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        for(int i = 1; i <= m; i++) {
            arr[i] = 1;
        }
        dfs(1, 1);

    }

    public static int dfs(int curStart, int depth) {

        if (depth > m) {
            for (int i = 1; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println(arr[m]);
            return 1;
        }
        for (int i = curStart; i <= n; i++) {
            arr[depth] = i;
            if (depth != 1 && arr[depth] <= arr[depth-1]) continue;
            dfs(curStart+1, depth+1);
        }
        return 0;
    }


}

