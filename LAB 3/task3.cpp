#include <iostream>
using namespace std;


class Library{
    private:
    int flag =0;
    int count = 0;
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];

    public:
        void addBook(string book){
            bookList[count] = book;
            availableBooks[count] = book;
            count++;
            cout << book << " is added" << endl;
        }

        void lendBook(string book){
            for (int i = 0; i < 100; i++)
            {
                if (availableBooks[i] == book)
                {
                    availableBooks[i] = "Null";
                    borrowedBooks[i] = book;
                    cout << "Book is lended" << endl;
                    flag = 1;
                }
            }
            if (!flag){
                cout << "sorry,Book not available" << endl;
            }
        }
        

        int returnBook(string book){
            for (int i = 0; i < 100; i++)
            {
                if (availableBooks[i] == book){
                    cout << "Book is already in library" << endl;
                    return 0;
                }
            }
            for (int i = 0; i < 100; i++)
            {
                if (borrowedBooks[i] == book)
                {
                    availableBooks[i] = book;
                    borrowedBooks[i] = "Null";
                    cout << "book is returned" << endl;
                    flag = 1;
                }
            }
            if (!flag){
                cout << "Book is not in the system" << endl;
            }
            return 1;
        }
};

int main(){
    Library library1;
    library1.addBook("abrakadabra");
    library1.addBook("babyshark");
    library1.lendBook("abrakadabra");
    library1.returnBook("abrakadabra");
    library1.returnBook("abrakadabra");

    return 0;
}
