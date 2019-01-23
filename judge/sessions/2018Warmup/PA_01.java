import java.util.*;
public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        int[]arr=new int[t];
        for(int i=0;i<t;i++)
            arr[i]=in.nextInt();
        long[]d=new long[100001];
        d[1]=1;
        d[2]=1;
        for(int i=3;i<100001;i++){
            d[i]=(d[i-1]+d[i-2])%100000007;
        }
        for(int i=0;i<t;i++){
            System.out.println(d[arr[i]]);
        }
    }
}
