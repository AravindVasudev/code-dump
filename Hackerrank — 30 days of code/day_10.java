import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String bn = Integer.toBinaryString(n);
        int count = 0, maxCount = 0;
        for(char ch: bn.toCharArray()) {
            if(ch == '0') {
                maxCount = maxCount > count ? maxCount : count;
                count = 0;
            }
            else count++;
        }
        maxCount = maxCount > count ? maxCount : count;
        System.out.println(maxCount);
    }
}
