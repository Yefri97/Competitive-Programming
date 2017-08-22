import java.util.Scanner;
import java.math.BigInteger;

class Main {
   
 public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt();
            if (n == 0) break;
            BigInteger fact = new BigInteger("1");
            for (int i = 2; i <= n; i++)
                fact = fact.multiply(BigInteger.valueOf(i));
            String s = fact.toString();
            int freq[] = new int[10];
            for (int i = 0; i < s.length(); i++)
                freq[s.charAt(i)-'0']++;
            System.out.println(n + "! --");
            for (int i = 0; i < 10; i++) {
                System.out.printf("    (%d)", i);
                System.out.printf("%5d", freq[i]);
                if (i == 4) System.out.printf("\n");
            }
            System.out.printf("\n");
        }
   }
}
