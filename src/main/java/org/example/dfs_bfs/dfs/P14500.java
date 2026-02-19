package org.example.dfs_bfs.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class P14500 {
    public static int maxSum = 0;
    public static int board[][] = new int [500][500];
    public static boolean visited[][] = new boolean[500][500]; // false 자동초기화
    public static int dx[] = {1, -1, 0, 0};
    public static int dy[] = {0, 0, 1, -1};
    public static int n, m;

    public static int dfs(int x, int y, int depth, int sum) {
        if(depth == 4) {
            // System.out.println(maxSum);
            return maxSum = max(maxSum, sum);
        }

        for (int i= 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dfs(nx, ny, depth+1, sum+board[nx][ny]);
            visited[nx][ny] = false;
        }
        return maxSum;
    }

    public static void checkT(int x, int y) {
        int val = board[x][y];
        int minVal = 1001;
        int depth = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            val += board[nx][ny];
            minVal = min(board[nx][ny], minVal);
            depth++;
            // System.out.println(val+" "+depth+ " "+x+" "+y+" "+maxSum);
        }

        if (depth == 4) maxSum = max(maxSum, val);
        else if (depth == 5) maxSum = max(maxSum, val - minVal);
        // System.out.println(x+" "+y+" "+maxSum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] size = br.readLine().split(" ");
        n = Integer.parseInt(size[0]);
        m = Integer.parseInt(size[1]);

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
//            Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = true;
                dfs(i, j, 1, board[i][j]);
                visited[i][j] = false;
                checkT(i, j);
            }
        }

        System.out.println(maxSum);
    }
}
