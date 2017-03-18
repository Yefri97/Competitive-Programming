import java.util.Scanner;
import java.math.BigInteger;

class Main {
  
  public static void main(String[] args) {
    final int MAX_N = 5000;
    BigInteger[] fib = new BigInteger[MAX_N + 10];
    fib[0] = BigInteger.ZERO; fib[1] = BigInteger.ONE;
    for (int i = 2; i < MAX_N + 10; i++)
      fib[i] = fib[i - 1].add(fib[i - 2]);
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int n = sc.nextInt();
      System.out.println("The Fibonacci number for " + n + " is " + fib[n]);
    }
  }

}