package org.example.recursive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P1759 {
    public static List<Character> alpha = new ArrayList<>();
    public static int n, c;
    public static boolean smallCases[] = new boolean[26];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        initSmallCases();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < c; i++) {
            alpha.add(st.nextToken().charAt(0));
        }

        Collections.sort(alpha); //배열이면 -> Arrays.sort(arr);
//        for (int i = 0; i < c; i++) {
//            System.out.println(alpha.get(i));
//        }
        for (int i = 0; i < c; i++) {
            int small = 0;
            int large = 0;
            if (smallCases[alpha.get(i) - 'a']) small++;
            else large++;

            getCases(1, alpha.get(i).toString(), small, large);
        }


    }

    public static void getCases(int depth, String pw, int small, int large) {
        if (depth == n) {
            if (small > 0 && large > 1)
                System.out.println(pw);
//                System.out.println(small +" "+ large+" "+ pw);
            return;
        }
        for (int i = 1; i < c; i++) {
            Character curAlpha = alpha.get(i);
            if (curAlpha <= pw.charAt(pw.length()-1)) continue;
            if (smallCases[curAlpha - 'a']) small++;  // "aeiou".indexOf(result[i])
            else large++;
            getCases(depth+1, pw+curAlpha, small, large);

            if (smallCases[curAlpha - 'a']) small--;
            else large--;
        }

    }

    public static void initSmallCases() {
        smallCases[0] = true;
        smallCases['e' - 'a'] = true;
        smallCases['i' - 'a'] = true;
        smallCases['o' - 'a'] = true;
        smallCases['u' - 'a'] = true;
    }



}
