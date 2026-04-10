package org.example.graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P34203 {
    public static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int edges[][] = new int[M+1][2];
        List<Integer>[] adj = new ArrayList[N+1];
        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[i][0] = u;
            edges[i][1] = v;
            adj[u].add(v);
            adj[v].add(u);
        }

        int D[][] =  new int[N+1][N+1];
        long total = 0;
        for (int i = 0; i <= N; i++) {
            Arrays.fill(D[i], -1);
        }

        for (int s = 1; s <= N; s++) {
            D[s][s] = 0;
            Queue<Integer> q = new LinkedList<>();
            q.add(s);
            while(!q.isEmpty()) {
                int u = q.poll();
                for(int v : adj[u]) {
//                    System.out.println("V="+v);
                    if(D[s][v] == -1) {
                        D[s][v] = D[s][u] + 1;
                        q.add(v);
                    }
                }
            }
            for (int i = 1; i <= N; i++) {
                total += D[s][i];
//                System.out.println(D[s][i]);
            }
        }

        long[] ans = new long[M+1];
        ans[M] = total;
        for (int i = M; i >= 2; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (D[u][v] > 0) {// 시간 줄이기
                for (int x = 1; x < N; x++) {
                    for (int y = x + 1; y <= N; y++) {
                        int newDist = Math.min(D[x][u] + D[v][y], D[x][v] + D[u][y]);
                        if (D[x][y] > newDist) {
                        /*
                        DIFF여야 하는 이유:
                        X -> Y = 10
                        x -> u -> 5 -> v -> y = 12
                        u-> v가 0이 되면 x ->y = 7
                        그러면 실제로는 3만큼 줄은 거지 5만큼 줄은 게 아니라서
                         */
                            int diff = D[x][y] - newDist;
                            D[x][y] = newDist;
                            D[y][x] = newDist;
                            total -= diff * 2;
                        }
                    }
                }
            }
            ans[i-1] = total;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= M; i++) {
            sb.append(ans[i]).append('\n');
        }
        System.out.println(sb);





    }

}
