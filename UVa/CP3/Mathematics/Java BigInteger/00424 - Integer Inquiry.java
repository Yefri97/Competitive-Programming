import java.math.BigInteger;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigInteger ans = new BigInteger("0");
    while (true) {
      BigInteger bi = sc.nextBigInteger();
      if (bi.compareTo(BigInteger.ZERO) == 0) break;
      ans = ans.add(bi);
    }
    System.out.println(ans);
  }

}