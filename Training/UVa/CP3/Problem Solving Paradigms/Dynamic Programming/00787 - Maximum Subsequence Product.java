// Max 1D Range Sum
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
 public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            List<BigInteger> lb = new ArrayList<BigInteger>();
            int n;
            while (sc.hasNext() && (n = sc.nextInt()) != -999999)
                lb.add(BigInteger.valueOf(n));
            BigInteger result = lb.get(0);
            for (int i = 0; i < lb.size(); i++) {
                BigInteger val = lb.get(i);
                result = result.max(val);
                for (int j = i - 1; j >= 0; j--) {
                    val = val.multiply(lb.get(j));
                    result = result.max(val);
                }
            }
            System.out.println(result);
        }
   }
}
