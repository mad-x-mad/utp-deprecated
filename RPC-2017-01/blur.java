import java.util.Scanner;
import java.util.TreeSet;


public class blur {
	
	
	
	static long gcd(long a, long b) {
		if (a == 0) return 1;
		while(b != 0) {
			long tmp = a;
			a = b;
			b = tmp % b;
		}
		return a;
	}
	
	
	static class Frac implements Comparable<Frac>{
		long n;
		long d;
		public Frac(long nn, long dd) {
			n = nn;
			d = dd;
			long gcd = gcd(nn, dd);
			//System.out.println(n + " " + d + " " + gcd);
			n /= gcd;
			d /= gcd;
		}
		Frac Add(Frac o){
			return new Frac(n * o.d + d * o.n, d * o.d);
		}
		Frac Multiply(Frac c) {
			return new Frac(n * c.n, d * c.d);
		}
		@Override
		public int compareTo(Frac o) {
			if (n == o.n)
				return Long.compare(d, o.d);
			return Long.compare(n, o.n);
		}
	}
	
	
	static int W, H, B;
	
	static Frac blur(int x, int y, Frac[][] matrix) {
		Frac ret = new Frac(0, 1);
		for(int i = -1; i < 2; i++){
			for(int j = -1; j < 2; j++){
				Frac current = matrix[(x + i + H) % H][(y + j + W) % W];
				ret = ret.Add(current);
			}
		}
		return ret.Multiply(new Frac(1, 9));
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		W = sc.nextInt();
		H = sc.nextInt();
		B = sc.nextInt();
		Frac[][] matrix = new Frac[H][W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				matrix[i][j] = new Frac(sc.nextInt(), 1);
			}
		}
		for(int c = 0; c < B; c++) {
			Frac[][] nmatrix = new Frac[H][W];
			for(int i = 0; i < H; i++) {
				for(int j = 0; j < W; j++) {
					nmatrix[i][j] = blur(i, j, matrix);
				}
			}
			matrix =nmatrix;
		}
		TreeSet<Frac> set = new TreeSet<Frac>();
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				set.add(matrix[i][j]);
			}
		}
		System.out.println(set.size());
	}

}
