import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) {
		BigInteger fib[] = new BigInteger[1001];
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.ONE.add(BigInteger.ONE);
		for (int i = 2; i < 1001; i++)
			fib[i] = fib[i - 2].add(fib[i - 1]);
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt())
			System.out.println(fib[sc.nextInt()]);
	}
}