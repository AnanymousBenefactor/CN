public class PrintBook extends Book{
    private String publisher;
    private int isbn;
    PrintBook(String title,int year,String author,String publisher,int isbn){
        super(title,year,author);
        this.publisher=publisher;
        this.isbn=isbn;
    }
    @Override
    public String toString(){
        return "Title is "+getTitle()+"\n"+"Year is "+getYear()+"\n"+"Author is "+getAuthor()+"\n"+"Publisher is "+publisher+"\n"+"ISBN is "+isbn+"\n";
    }

}
