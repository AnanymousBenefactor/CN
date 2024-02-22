import java.util.*;
public class Count1{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter n");
        int n=sc.nextInt();
        int[][] nums=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Math.random()<0.4){
                    nums[i][j]=0;
                }
                else
                nums[i][j]=1;
            }
        }
        System.out.println("Random matrix is");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(nums[i][j]);
            }
            System.out.println();
        }
        int[] row=new int[n];
        int[] col=new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        System.out.println(Arrays.toString(row));
        System.out.println(Arrays.toString(col));
        ArrayList<Integer> r=new ArrayList<>();
        ArrayList<Integer> c=new ArrayList<>();
        Integer maxr=0;
        r.add(0);
        for(int i=1;i<n;i++){
            if(row[i]>row[maxr])
            {
                maxr=i;
                r.clear();
                r.add(maxr);
            }
            else if(row[i]==row[maxr] && i!=maxr){
                r.add(i);
            }
        }
        Integer maxc=0;
        c.add(0);
        for(int i=1;i<n;i++){
            if(col[i]>col[maxc])
            {
                maxc=i;
                c.clear();
                c.add(maxc);
            }
            else if(col[i]==col[maxc] && i!=maxc){
                c.add(i);
            }
        }
        System.out.println("The largerst row index: "+r.toString());
        System.out.println("The largest column index: "+c.toString());


        sc.close();
    }
}