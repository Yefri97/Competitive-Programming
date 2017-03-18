import java.math.BigInteger;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      BigInteger a = sc.nextBigInteger();
      BigInteger b = sc.nextBigInteger();
      System.out.println(a.multiply(b));
    }
  }
  
}
