import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true){
        System.out.println("1.Add audio book"+"\n"+"2.Add Print Book");
        System.out.println("Enter option:");
        int option=sc.nextInt();
        if(option==-1)
        break;
        switch(option){
            case 1:
            System.out.println("Enter title,year,author,size,length,name");
            AudioBook a=new AudioBook(sc.next(), sc.nextInt(),sc.next(), sc.nextInt(), sc.nextInt(),sc.next());
            System.out.println(a.toString());
            break;
            case 2:
            System.out.println("Enter title,year,author,publisher,ISBN");
            PrintBook b=new PrintBook(sc.next(), sc.nextInt(),sc.next(), sc.next(), sc.nextInt());
            System.out.println(b.toString());

        }
    }
}
}
