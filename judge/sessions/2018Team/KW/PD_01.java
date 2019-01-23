
import java.util.*;
import java.io.*;
public class t_d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int c=0;c<t;c++){
            int n=in.nextInt();
            int k=in.nextInt();
            int[]arr=new int[n];
            for(int i=0;i<n;i++)
                arr[i]=in.nextInt();
            long[][]d = new long[n][k+1];
            d[0][1] = arr[0];
            if(arr[0]>arr[1]){
                d[1][1] = arr[0];
            }else {
                d[1][1] = arr[1];
            }
            for(int i=2;i<n;i++){
                for(int j=1;j<Math.min(k+1, i+1);j++){
                    if(i-2>=0) {
                        if (d[i - 1][j] > arr[i] + d[i - 2][j - 1]) {
                            d[i][j] = d[i - 1][j];

                        } else {
                            d[i][j] = arr[i] + d[i - 2][j - 1];
                        }
                    }
                }
            }
            System.out.println(d[n-1][k]);
        }
    }
}