package org.programmers.string;
import java.util.*;

class 성격유형검사하기 {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();

        for (int i = 0; i < survey.length; i++) {

            if (choices[i] > 4) {
                hm.put(survey[i].substring(1), hm.getOrDefault(survey[i].substring(1), 0) + choices[i] - 4);
            } else {
                hm.put(survey[i].substring(0,1), hm.getOrDefault(survey[i].substring(0,1), 0)+ 4 - choices[i]);
            }
        }

        if (hm.getOrDefault("R", 0) >= hm.getOrDefault("T", 0)) answer += "R";
        else answer += "T";
        if (hm.getOrDefault("C", 0) >= hm.getOrDefault("F", 0)) answer += "C";
        else answer += "F";
        if (hm.getOrDefault("J", 0) >= hm.getOrDefault("M", 0)) answer += "J";
        else answer += "M";
        if (hm.getOrDefault("A", 0) >= hm.getOrDefault("N", 0)) answer += "A";
        else answer += "N";
        return answer;
    }
    
    public String solution2(String[] survey, int[] choices) {
        String answer = "";
        int i = 0;
        HashMap<String, Integer> report = new HashMap<>();
        for (String s : survey) {
            String first = s.substring(0,1);
            String second = s.substring(1);
            if (choices[i] < 4) {
                report.put(first, report.getOrDefault(first, 0) + (4-choices[i]));
            } else if (choices[i] > 4) {
                report.put(second, report.getOrDefault(second, 0) + (choices[i]-4));
            }
            i++;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(report.getOrDefault("T", 0) >report.getOrDefault("R", 0) ? "T" : "R");
        sb.append(report.getOrDefault("F", 0) >report.getOrDefault("C", 0) ? "F" : "C");
        sb.append(report.getOrDefault("M", 0) >report.getOrDefault("J", 0) ? "M" : "J");
        sb.append(report.getOrDefault("N", 0) >report.getOrDefault("A", 0) ? "N" : "A");
        return sb.toString();
    }
}