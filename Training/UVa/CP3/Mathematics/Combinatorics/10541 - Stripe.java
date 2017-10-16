import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	static BigInteger comb(int n, int k) {
		if (k > n - k)
			k = n - k;
		BigInteger ans = BigInteger.ONE;
		for (int i = 1; i <= k; i++, n--) {
			ans = ans.multiply(BigInteger.valueOf(n));
			ans = ans.divide(BigInteger.valueOf(i));
		}
		return ans;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int l = sc.nextInt(), k = sc.nextInt(), x = 0;
			for (int i = 0; i < k; i++)
				x += sc.nextInt();
			int n = l - x;
			BigInteger ans = k > n + 1 ? BigInteger.ZERO : comb(n + 1, k);
			System.out.println(ans);
		}
	}
}