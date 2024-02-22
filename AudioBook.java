public class AudioBook extends Book{
    private int size;
    private int length;
    private String name;
    AudioBook(String title,int year,String author,int size,int length,String name){
        super(title,year,author);
        this.size=size;
        this.length=length;
        this.name=name;
    }
    public String toString(){
        return "Title is "+getTitle()+"\n"+"Year is "+getYear()+"\n"+"Author is "+getAuthor()+"\n"+"Book size in MB is "+size+"\n"+"Audio length is "+length+"\n"+"Playback artist's name is "+name+"\n";
    }
}
