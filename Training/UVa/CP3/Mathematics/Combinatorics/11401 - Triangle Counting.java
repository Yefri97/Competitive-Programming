import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		BigInteger ans[] = new BigInteger[1000001];
		ans[0] = BigInteger.ZERO;
		for (int i = 1, j = 1; i <= 1000000; i += 2, j++) {
			ans[i] = ans[i - 1].add(BigInteger.valueOf(j));
			ans[i + 1] = ans[i].add(BigInteger.valueOf(j));
		}
		for (int i = 1; i <= 1000000; i++)
			ans[i] = ans[i].add(ans[i - 1]);
		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if (n < 3) break;
			System.out.println(ans[n - 3]);
		}
	}
}