public class Book {
    private String title;
    private int year;
    private String author;
    public Book(String title,int year,String author){
        this.title=title;
        this.year=year;
        this.author=author;
    }
    public String getTitle(){
        return title;
    }
    public int getYear(){
        return year;
    }
    public String getAuthor(){
        return author;
    }

    @Override
    public String toString(){
        return "Title is "+title+"Year is "+year+"Author is "+"author";
    }
}
