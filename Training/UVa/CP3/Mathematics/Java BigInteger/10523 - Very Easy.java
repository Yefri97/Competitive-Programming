import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt()) {
			int n = sc.nextInt(), a = sc.nextInt();
			BigInteger x = BigInteger.valueOf(a), ans = BigInteger.ZERO;
			for (int i = 1; i <= n; i++) {
				ans = ans.add(BigInteger.valueOf(i).multiply(x));
				x = x.multiply(BigInteger.valueOf(a));
			}
			System.out.println(ans);
		}
	}
}