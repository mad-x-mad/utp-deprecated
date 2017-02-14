import java.util.Scanner;


public class egg {
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int safe = 1;
		int break_ = K;
		for(int i = 0; i < N; i++) {
			int t = sc.nextInt();
			String cad = sc.next();
			if (cad.equals("SAFE"))
				safe = Math.max(safe, t);
			else
				break_ = Math.min(break_, t);
		}
		System.out.println((safe + 1) + " " + (break_ - 1));
	}

}
