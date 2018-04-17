import java.util.Scanner;

public class A {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int tests = input.nextInt();
		for(int i = 0; i < tests; i++){
			int types = input.nextInt();
			int cap = input.nextInt();
			int[][] f = new int[types][2];
			for(int j = 0; j < types; j++){
				f[j][0] = input.nextInt();
				f[j][1] = input.nextInt();
			}
			int beauty = 0;
			while(cap > 0){
				int max = f[0][0];
				int im = 0;
				for(int j = 0; j < types; j++){
					if(f[j][0] >= max){
						max = f[j][0];
						im = j;
					}
				}
				int use = Math.min(cap, f[im][1]);
				beauty += use * f[im][0];
				cap -= use;
				f[im][1] -= use;
			}
			System.out.println(beauty);
		}
		input.close();
	}
}
