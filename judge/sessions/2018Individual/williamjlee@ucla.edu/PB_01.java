
import java.util.*;
import java.io.*;
public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int c=0;c<t;c++){
            int save=0;
            for(int j=0;j<100;j++){
                if(in.nextInt()==1){
                    save=j;
                }
            }
            System.out.print(save+" ");
            for(int j=0;j<100;j++){
                if(in.nextInt()==1){
                    save=j;
                }
            }
            System.out.print(save+" ");
            for(int j=0;j<100;j++){
                if(in.nextInt()==1){
                    save=j;
                }
            }
            System.out.println(save);

        }
    }
}