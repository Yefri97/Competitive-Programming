import java.util.Scanner;
import java.math.BigInteger;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while (t-- > 0) {
      BigInteger y = sc.nextBigInteger();
      BigInteger x_prev = y, x_curr;
      while (true) {
        x_curr = x_prev.add(y.divide(x_prev)).shiftRight(1);
        if (x_curr.compareTo(x_prev) == 0) break;
        x_prev = x_curr;
      }
      System.out.println(x_curr);
      if (t != 0) System.out.print("\n");
    }
  }

}