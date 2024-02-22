import java.util.*;

class Student extends Person {
    private int numCourses=0;
    private String[] courses=new String[5];
    private int[] grades=new int[5];
    public Student(String name,String address){
        super(name,address);
    }
    @Override
    public String toString(){
        return ("Student:"+getName()+"("+getAddress()+")");
    }
    public void addCourseGrade(String course,int grade){
        courses[numCourses]=course;
        grades[numCourses]=grade;
        numCourses++;
    }
    public void printGrades(){
        for(int i=0;i<numCourses;i++)
        System.out.println(courses[i]+":"+grades[i]);
    }
    public double getAverageGrade(){
        double avg=0;
        for(int i:grades){
            avg+=i;
        }
        return avg/numCourses;
    }
}
