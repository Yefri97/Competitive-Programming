import java.math.BigInteger;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      int n = sc.nextInt(), k = sc.nextInt();
      if (n == 0 && k == 0) break;
      BigInteger limit = sc.nextBigInteger();
      BigInteger fac = BigInteger.ONE;
      int ok = 1;
      for (int i = 2; i <= n - k + 1; i++) {
        fac = fac.multiply(BigInteger.valueOf(i));
        if (fac.compareTo(limit) > 0) { ok = 0; break; }
      }
      if (ok == 1)
        System.out.println(fac);
      else
        System.out.println("descartado");
    }
  }

}