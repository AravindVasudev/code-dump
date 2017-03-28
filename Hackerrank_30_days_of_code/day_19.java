import java.io.*;
import java.util.*;

interface AdvancedArithmetic{
   int divisorSum(int n);
}

//Write your code here

class Calculator implements AdvancedArithmetic {
    public int divisorSum(int n) {
        int count = n;
        for(int i = 1; i <= n / 2; i++) {
            if(n % i == 0) count += i;
        }

        return count;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();

      	AdvancedArithmetic myCalculator = new Calculator();
        int sum = myCalculator.divisorSum(n);
        System.out.println("I implemented: " + myCalculator.getClass().getInterfaces()[0].getName() );
        System.out.println(sum);
    }
}
