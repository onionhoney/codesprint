import java.util.Scanner;

public class B {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int i = 0; i < cases; i++){
			int m = input.nextInt();
			int n = input.nextInt();
			int k = input.nextInt();
			int h = 0;
			int v = 0;
			for(int j = 0; j < k; j++){
				int x1 = input.nextInt();
				int y1 = input.nextInt();
				int x2 = input.nextInt();
				int y2 = input.nextInt();
				if(x1==x2)
					h++;
				if(y1==y2)
					v++;
			}
			System.out.println(h*v);
		}
	}
}