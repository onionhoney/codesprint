

import java.util.*;
import java.io.*;
public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int c=0;c<t;c++){
            int tot=in.nextInt();
            int p=in.nextInt(); int q=in.nextInt();
            TreeSet<Integer>ts=new TreeSet<>();
            for(int i=0;i<p;i++){
                ts.add(in.nextInt());
            }
            int max=0;
            for(int i=0;i<q;i++){
                int num=in.nextInt();
                if(ts.contains(tot-num)){
                    max=tot;
                    break;
                } else{
                    Integer x = ts.lower(tot-num);
                    if(x!=null)
                        max=Math.max(max, x+num);
                }
            }
            System.out.println(max);
        }
    }
}