import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
  	Scanner sc = new Scanner(System.in);
  	while (sc.hasNextInt()) {
  		int n = sc.nextInt();
	    BigInteger fac = BigInteger.ONE;
	    for (int i = 2; i <= n; i++)
	      fac = fac.multiply(BigInteger.valueOf(i));
	    System.out.println(n + "!");
	    System.out.println(fac);
  	}
} }
