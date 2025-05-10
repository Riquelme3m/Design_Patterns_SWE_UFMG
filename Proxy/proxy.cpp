#include <iostream>
#include <map>

std::map<int, std::string> books{{1, "The little prince"}, {2, "war and peace"}, {3, "1984"}, {4, "To kill a mockingbird"}, {5, "Pride and prejudice"}};

std::map<int, std::string> booksCache{{1, "The little prince"}, {2, "war and peace"}};

class BookSearchInterface
{
private:
public:
    virtual std::string getBook(int INSB) = 0;
};

class BookSearch : public BookSearchInterface
{
private:
public:
    std::string getBook(int INSB)
    {
        auto it = books.find(INSB);
        if (it != books.end())
        {
            return it->second;
        }
        else
        {
            return "Book not found";
        }
    }
};

class BookSearchProxy : public BookSearchInterface
{

private:
    BookSearchInterface *base;

public:
    BookSearchProxy(BookSearchInterface *_base)
    {
        base = _base;
    }

    std::string getBook(int ISBN)
    {

        auto it = booksCache.find(ISBN);
        
        if (it != booksCache.end())
        {   
            std::cout<<"Cacha was called"<<std::endl;
            return it->second;
        }
        else
        {
            std::cout<<"Object base function was called!"<<std::endl;
            return base->getBook(ISBN);
        }
        
    }
};


int main(){

    BookSearch* baseObject = new BookSearch();

    BookSearchProxy* x = new BookSearchProxy(baseObject);

    std::cout<<x->getBook(3)<<std::endl;


    return 0;
}