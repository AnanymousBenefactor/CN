import java.util.*;
class Teacher extends Person {
    private int numCourses=0;
    private String[] courses=new String[5];
    public Teacher(String name,String address){
        super(name,address);
    }
    @Override
    public String toString(){
        return ("Teacher:"+getName()+"("+getAddress()+")");
    }
    public boolean addCourse(String course){
        for(int i=0;i<numCourses;i++){
            if(courses[i].equals(course))
            return false;
        }
        courses[numCourses]=course;
        numCourses++;
        return true;
    }
    public boolean removeCourse(String course){
        int index=-90;
        for(int i=0;i<numCourses;i++){
            if(courses[i].equals(course))
            index=i;
        }
        if(index==numCourses-1)
        {
            numCourses--;
            return true;
        }
        if(index==-90)
        return false;
        for(int j=index+1;j<numCourses;j++){
            courses[j-1]=courses[j];
        }
        numCourses--;
        return true;
        //return (index==-1)? false:true;
    }
    

}
