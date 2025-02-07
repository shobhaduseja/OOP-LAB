//shobha duseja//
//24K-1006//

#include <iostream>
using namespace std;

struct Book{
    string title;
    string author;
    int year;
};

Book* createBooks(int n){
    Book* books = new Book[n];
    cout << "Books are created" << endl;
    return books;
}

void populateArray(Book* books, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter  required details for book: " << i+1 << ": " << endl;
        cout << "TITLE: ";
        cin.ignore();
        getline(cin, books[i].title);
        cout << "AUTHOR: ";
        getline(cin, books[i].title);
        cout << "YEAR: ";
        cin >> books[i].year;
        cout << endl;
    }
    
}
void displayBooks(Book* books, int n){
    int Year;
    cout << "Enter a year to see books published after it: ";
    cin >> Year;
    cout << "\nBooks published after " << Year << ":"<<endl;
    bool found=false;
    for (int i = 0; i < n; i++)
    {
        if(books[i].year > Year){
            found = true;
            cout << "Book "<<i+1<<" :\n"<< books[i].title <<"\n"<< books[i].author <<"\n"<<books[i].year<< endl;
        }
    }
    if (!found) {
        cout << "No books found published after " << Year << ".\n";
    }
}
void free(Book* books){
    delete[] books;
    cout << endl << "memory deallocated!!" << endl;
}
int main(){
    int size;
    cout << "Kindly enter the number of books: ";
    cin >> size;
    Book* books = createBooks(size);
    populateArray(books, size);
    displayBooks(books, size);
    free(books);
    return 0;
}
