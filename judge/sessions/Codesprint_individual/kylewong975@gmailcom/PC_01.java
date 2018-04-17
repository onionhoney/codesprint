import java.util.*;
public class CodeSprintLA1 {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.next());
		for(int i = 0; i < testCases; i++)
		{
			int row = Integer.parseInt(in.next());
			int col = Integer.parseInt(in.next());
			int a = Integer.parseInt(in.next());
			int b = Integer.parseInt(in.next());
			a--; b--; //make it 0 based
			char arr[][] = new char[row][col];
			for(int x = 0; x < arr.length; x++)
			{
				String t = in.next();
				for(int y = 0; y < arr[x].length; y++)
				{
					arr[x][y] = t.charAt(y);
				}
			}
			boolean barr[][] = new boolean[row][col];
			//may not need below
			for(int x = 0; x < barr.length; x++)
			{
				for(int y = 0; y < barr[x].length; y++)
				{
					barr[x][y] = false;
				}
			}
			String ans = "";
			barr[a][b] = true;
			while(true)
			{
				if(a > 0 && arr[a - 1][b] == '#' && !barr[a-1][b])
				{
					ans+="U"; //U before L
					barr[a-1][b] = true;
					a--;
				}
				else if (a < row - 1 && arr[a + 1][b] == '#' && !barr[a + 1][b])
				{
					ans += "D"; //D before R
					barr[a + 1][b] = true;
					a++;
				}
				else if (b > 0 && arr[a][b - 1] == '#' && !barr[a][b - 1])
				{
					ans += "L"; //L before U
					barr[a][b - 1] = true;
					b--;
				}
				else if (b < col - 1 && arr[a][b + 1] == '#' && !barr[a][b + 1])
				{
					ans += "R"; //R before D
					barr[a][b + 1] = true;
					b++;
				}
				else
				{
					System.out.println(ans);
					break;
				}
			}
		}
		in.close();
		
	}
}

/*int testCases;
	cin >> testCases;
	for (int x = 0; x < testCases; x++)
	{
		int row, col;
		cin >> row >> col;
		int a, b;
		cin >> a >> b; //whisker start position 1-based
		char** arr = new char*[row];
		for (int i = 0; i < row; i++)
			arr[i] = new char[col];

		for (int x = 0; x < row; x++)
		{
			string t;
			cin >> t;
			for (int y = 0; y < col; y++)
			{
				arr[x][y] = t[y];
			}
		}
		bool** barr = new bool*[row];
		for (int i = 0; i < row; i++)
			barr[i] = new bool[col];

		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				barr[x][y] = false;
			}
		}
		string ans;
		//array initialized
		
		while (true)
		{
			cout << "enter" << endl;
			//start at whisker position
			int x = a - 1;
			int y = b - 1;
			barr[x][y] = true;
			if (x > 0 && arr[x - 1][y] == '#' && !barr[x-1][y])
			{
				ans += "L";
				barr[x - 1][y] = true;
				x--;
			}
			else if (x < row - 1 && arr[x + 1][y] == '#' && !barr[x + 1][y])
			{
				ans += "R";
				barr[x + 1][y] = true;
				x++;
			}
			else if (y > 0 && arr[x][y - 1] == '#' && !barr[x][y - 1])
			{
				ans += "U";
				barr[x][y - 1] = true;
				y--;
			}
			else if (y < col - 1 && arr[x][y + 1] == '#' && !barr[x][y + 1])
			{
				ans += "D";
				barr[x][y + 1] = true;
				y++;
			}
			else
			{
				cout << ans << endl;
				break;
			}
		}
		

		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				cout << arr[x];
			}
			cout << endl;
		}

		delete[] arr;
		delete[] barr;
	}
 */
