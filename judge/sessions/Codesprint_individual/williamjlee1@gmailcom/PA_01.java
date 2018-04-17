package code;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by william_lee on 1/28/17.
 */
public class a {
    public static void main(String[] args) {


        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int c=1;c<=t;c++){
            int n=in.nextInt();
            int bl=in.nextInt();
            f[] arr=new f[n];
            for(int i=0;i<n;i++){
                arr[i]=new f(in.nextInt(),in.nextInt());
            }
            Arrays.sort(arr);
            long a=0;
            for(int i=arr.length-1;i>=0;i--){
                if(bl<=0)
                    break;
                while(bl>0 && arr[i].num>0){
                    a+=arr[i].beu;
                    arr[i].num--;
                    bl--;
                }
            }
            System.out.println(a);
        }
    }

}
class f implements Comparable{
    int beu;
    int num;
    public f(int b,int n){
        beu=b;
        num=n;
    }
    public int compareTo(Object o){
        f oth=(f)o;
        return new Integer(beu).compareTo(oth.beu);
    }
}
