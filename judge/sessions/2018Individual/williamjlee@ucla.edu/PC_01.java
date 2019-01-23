
import java.util.*;
import java.io.*;
public class recons {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int c=0;c<t;c++){
            int rooms=in.nextInt();
            int edge = in.nextInt();
            int create=in.nextInt();
            //HashSet<Integer>[]can=new [rooms];
            HashSet<Integer>[]can = new HashSet[rooms];
            for(int i=0;i<rooms;i++)
                can[i]=new HashSet<>();
            for(int i=0;i<edge;i++){
                can[in.nextInt()-1].add(in.nextInt()-1);
            }
            int[]groups=new int[rooms];
            boolean[]v=new boolean[rooms];
            int num=0;
            for(int i=0;i<rooms;i++){
                if(!v[i]){
                    dfs(i, can, v, groups, num);
                    num++;
                }
            }

            HashMap<Integer, Integer>hm=new HashMap<>();
            for(int i=0;i<groups.length;i++){
                if(!hm.containsKey(groups[i])){
                    hm.put(groups[i], 1);
                }else{
                    hm.put(groups[i], hm.get(groups[i])+1);
                }
            }
            ArrayList<Integer>counts=new ArrayList<>();
            for(Integer k: hm.keySet())
                counts.add(hm.get(k));
            Collections.sort(counts);
            int ind=Math.max(0, counts.size()-create-1);
            long get=0;
            for(int i=0;i<ind;i++)
                get+=(counts.get(i)*(counts.get(i)-1))/2;
            long sum=0;
            for(int i=ind;i<counts.size();i++)
                sum+=counts.get(i);
            get+=(sum*(sum-1))/2;
            System.out.println(get);

        }
    }
    public static void dfs(int room, HashSet<Integer>[]can, boolean[]v, int[]groups, int group){
        if(v[room])
            return;
        v[room]=true;
        groups[room]=group;
        for(Integer next: can[room]){
            if(!v[next])
                dfs(next, can, v, groups, group);
        }
    }

}