import java.util.Scanner;

public class B {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int i = 0; i < cases; i++){
			int m = input.nextInt();
			int n = input.nextInt();
			int k = input.nextInt();
			int h = 1;
			int v = 1;
			for(int j = 0; j < k; j++){
				int x1 = input.nextInt();
				int y1 = input.nextInt();
				int x2 = input.nextInt();
				int y2 = input.nextInt();
				if(x1==x2 && x1 != 0 && x1 != m)
					h++;
				if(y1==y2 && y1 != 0 && y1 != n)
					v++;
			}
			System.out.println(h*v);
		}
		input.close();
	}
}