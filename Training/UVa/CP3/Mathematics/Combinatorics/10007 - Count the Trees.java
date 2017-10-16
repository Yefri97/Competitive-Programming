import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		BigInteger ans[] = new BigInteger[301];
		ans[0] = BigInteger.ONE;
		for (int i = 1; i <= 300; i++) {
			ans[i] = ans[i - 1].multiply(BigInteger.valueOf(i));
			ans[i] = ans[i].multiply(BigInteger.valueOf(2 * (2 * i - 1)));
			ans[i] = ans[i].divide(BigInteger.valueOf(i + 1));
		}
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt()) {
			int n = sc.nextInt();
			if (n == 0) break;
			System.out.println(ans[n]);
		}
	}
}