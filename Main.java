import java.util.*;
public class Main {
    static int i=0;
    static int p=0;
    static Student[] students=new Student[5];
    static Teacher[] teachers=new Teacher[5];
    public static int getIndex(String n){
        for(int j=0;j<i;j++){
            if(students[j].getName().equals(n)){
                return j;
            }
        }
        return -1;
    }
    public static int getTeacherIndex(String n){
        for(int j=0;j<p;j++){
            if(teachers[j].getName().equals(n)){
                return j;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int index;
        String name;
        while(true){
        System.out.println("1.Add Student"+"\n"+"2.Add Course Grade"+"\n"+"3.Print Grades"+"\n"+"4.Print Avg Grade"+"\n"+"5.Print all students"+"\n"+"6.Add Teacher"+"\n"+"7.Add course"+"\n"+"8.Remove Course"+"\n"+"9.Print all teachers");
        System.out.println("Enter option:");
        int option=sc.nextInt();
        if(option==-1)
        break;
        switch(option){
            case 1:
            System.out.println("Enter student name and address:");
            students[i]=new Student(sc.next(),sc.next());
            i++;
            break;
            case 2:
            System.out.println("Enter student name");
            name=sc.next();
            index=getIndex(name);
            System.out.println(index);
            System.out.println("Enter course name and mark");
            students[index].addCourseGrade(sc.next(), sc.nextInt());
            break;
            case 3:
            System.out.println("Enter student name");
            name=sc.next();
            index=getIndex(name);
            System.out.println(index);
            students[index].printGrades();
            break;
            case 4:
            System.out.println("Enter student name");
            name=sc.next();
            index=getIndex(name);
            System.out.println("Average grade is "+students[index].getAverageGrade());
            break;
            case 5:
            for(int k=0;k<i;k++){
                System.out.println(students[k].toString());
            }
            break;
            case 6:
            System.out.println("Enter teacher name and address:");
            teachers[p]=new Teacher(sc.next(),sc.next());
            p++;
            break;
            case 7:
            System.out.println("Enter teacher name");
            name=sc.next();
            index=getTeacherIndex(name);
            System.out.println(index);
            System.out.println("Enter course name");
            boolean result=teachers[index].addCourse(sc.next());
            if(result){
                System.out.println("Added successfully");
            }
            else
            System.out.println("Course already exists");
            break;
            case 8:
            System.out.println("Enter teacher name");
            name=sc.next();
            index=getTeacherIndex(name);
            System.out.println(index);
            System.out.println("Enter course name");
            boolean res=teachers[index].removeCourse(sc.next());
            if(res){
                System.out.println("Deleted successfully");
            }
            else
            System.out.println("Course doesn't exists");
            break;
            case 9:
            for(int k=0;k<p;k++){
                System.out.println(teachers[k].toString());
            }
            break;
            default:
            System.out.println("Enter valid option");


        }


    }
}
}

