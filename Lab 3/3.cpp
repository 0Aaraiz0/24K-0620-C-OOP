#include <iostream>
using namespace std;

class Library {
private:
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];
    int bookCount;
    int availableBookCount;
    int borrowedBookCount; 

public:
    Library(string a, string b, string c, int k) {
        bookList[0] = a;
        bookList[1] = b;
        bookList[2] = c;
        bookCount = k;
        availableBookCount = k; 
        borrowedBookCount = 0; 

        for (int i = 0; i < bookCount; i++) {
            availableBooks[i] = bookList[i];
        }
    }

    void addBooks() {
        if (bookCount >= 100) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }
        
        cout << "Enter book to add: ";
        cin>>bookList[bookCount];
        
        availableBooks[availableBookCount] = bookList[bookCount]; 
        bookCount++;
        availableBookCount++;
    }

    void lendBooks() {
        string lbook;
        cout << "Enter book to lend: ";
        cin>>lbook;

        for (int i = 0; i < availableBookCount; i++) {
            if (lbook == availableBooks[i]) {
                borrowedBooks[borrowedBookCount++] = lbook; 

                for (int j = i; j < availableBookCount - 1; j++) {
                    availableBooks[j] = availableBooks[j + 1];
                }

                availableBookCount--; 
                cout << "Book borrowed successfully." << endl;
                return;
            }
        }
        cout << "Book not available." << endl;
    }

    void returnBooks() {
        string rbook;
        cout << "Enter book to return: ";
        cin>>rbook;

        for (int i = 0; i < borrowedBookCount; i++) {
            if (rbook == borrowedBooks[i]) {
                availableBooks[availableBookCount++] = rbook; 

                for (int j = i; j < borrowedBookCount - 1; j++) {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }

                borrowedBookCount--;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found in borrowed list." << endl;
    }
};

int main() {
    Library library("Money", "Black", "Hispanic", 3);

    int ch;
    while (true) {
        cout << "\n1. Add Book" << endl;
        cout << "2. Lend Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                library.addBooks();
                break;
            case 2:
                library.lendBooks();
                break;
            case 3:
                library.returnBooks();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}
