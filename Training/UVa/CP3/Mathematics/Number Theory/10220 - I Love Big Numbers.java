import java.util.Scanner;
import java.math.BigInteger;

class Main {
   
 public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            BigInteger fact = new BigInteger("1");
            for (int i = 2; i <= n; i++)
                fact = fact.multiply(BigInteger.valueOf(i));
            String s = fact.toString();
            int ans = 0;
            for (int i = 0; i < s.length(); i++)
                ans += (s.charAt(i) - '0');
            System.out.println(ans);
        }
   }
}
