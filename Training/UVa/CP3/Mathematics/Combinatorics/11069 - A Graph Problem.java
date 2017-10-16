import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		BigInteger ans[] = new BigInteger[101];
		ans[1] = BigInteger.ONE;
		ans[2] = ans[3] = BigInteger.ONE.add(BigInteger.ONE);
		for (int i = 4; i <= 100; i++)
			ans[i] = ans[i - 2].add(ans[i - 3]);
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt())
			System.out.println(ans[sc.nextInt()]);
	}
}