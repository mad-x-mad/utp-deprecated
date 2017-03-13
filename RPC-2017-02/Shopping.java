import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Shopping {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()) {
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	
	static class RMQ {
		int[][] M;
		long[] a;
		public RMQ(long[] array) {
			int s;
			for(s = 0; 1<<s <= array.length; s++);
			M = new int[array.length][s];
			a = array;
			init();
		}
		void init() {
			for(int i = 0; i < a.length; i++)
				M[i][0] = i;
			for(int j = 1; (1<<j) - 1 < a.length; j++)
				for(int i = 0; i + (1<<j) - 1 < a.length; i++) {
					int first = M[i][j - 1];
					int second = M[i + (1<<(j-1))][j - 1];
					if (a[first] < a[second])
						M[i][j] = first;
					else
						M[i][j] = second;
				}
		}
		int queryIdx(int l, int r) {
			int tam = r - l + 1;
			int log;
			for(log = 0; 1<<log <= tam; log++);
			log--;
			int f = M[l][log];
			int s = M[r - (1<<log) + 1][log];
			if (a[f] < a[s])
				return f;
			return s;
		}
		long queryValue(int l, int r){
			return a[queryIdx(l, r)];
		}
	}
	
	static int binsearch(int from, long x) {
		int low = from;
		int high = N - 1;
		if (rmq.queryValue(low, high) > x)
			return N;
		while(low < high) {
			int mid = (low + high)/2;
			if (rmq.queryValue(from, mid) <= x)
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
	
	static long solve(int l, int r, long v) {
		long x = v;  
		while(l < r) {
			x = x % rmq.a[l];
			l = binsearch(l + 1, x);
		}
		if (l == r)
			x = x % rmq.a[l];
		return x;
	}
	
	static RMQ rmq;
	static int N, Q;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		N = sc.nextInt();
		Q = sc.nextInt();
		long[] array = new long[N];
		for(int i = 0; i < N; i++)
			array[i] = sc.nextLong();
		rmq = new RMQ(array);
		for(int i = 0; i < Q; i++) {
			long v = sc.nextLong();
			int l = sc.nextInt() - 1;
			int r = sc.nextInt() - 1;
			bw.write(solve(l, r, v)+"\n");
		}
		bw.flush();
	}

}
