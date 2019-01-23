
import java.util.*;
import java.io.*;
public class t_a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int c=0;c<t;c++){
            int n=in.nextInt();
            int k=in.nextInt();
            String str = in.next();
            int dir=0;
            int cntR=0;
            int cntL=0;
            for(int i=0;i<str.length();i++){
                if(str.charAt(i)=='R') {
                    cntL=0;
                    cntR++;
                }
                else if(str.charAt(i)=='L') {
                    cntR=0;
                    cntL++;
                }
                if(cntR==k){
                    dir--;
                    cntR=0;
                    cntL=0;
                } else if(cntL==k){
                    dir++;
                    cntR=0;
                    cntL=0;
                }
            }
            System.out.println(dir);
        }
    }
}