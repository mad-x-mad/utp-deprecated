import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class millionaire {
	
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
	
	
	static double[] p, v, prob;
	static int[] last_safe;
	
	
	static double reward_last_safe(int i) {
		int idx = last_safe[i];
		if (idx == -1)
			return 0.0;
		return v[idx];
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		int W = sc.nextInt();
		p = new double[N];
		v = new double[N];
		prob = new double[N];
		last_safe = new int[N];
		int lsafe = -1;
		for(int i = 0; i < N; i++) {
			String cad = sc.next();
			p[i] = sc.nextDouble();
			v[i] = sc.nextDouble();
			last_safe[i] = lsafe;
			if (cad.equals("safe"))
				lsafe = i;
		}
		double last_prob = 1.0;
		double last_happiness = 0;
		double max = 0;
		double acum_expected = 0;
		for(int i = 0; i < N; i++) {
			double current_happiness = Math.log(1.0 + (v[i] / W));
			double current_prob = last_prob * p[i];
			acum_expected -= last_prob * last_happiness;
			acum_expected +=  last_prob * (1 - p[i]) * Math.log(1.0 + ( reward_last_safe(i)/ W));
			acum_expected += current_prob * current_happiness;
			max = Math.max(max, acum_expected);
			//
			last_prob = current_prob;
			last_happiness = current_happiness;
		}
		String cad = String.format("$%.2f\n", (Math.exp(max) - 1.0) * W);
		cad = cad.replace(',' ,'.');
		System.out.print(cad);
	}

}
