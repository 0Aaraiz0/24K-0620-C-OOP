#include "iostream"
using namespace std;

typedef struct 
{
    string title;
    string author;
    int year;
}book;


int main(){

    int num;

    cout<<"How many books you wanna add: "<<endl;
    cin>>num;

    book *books = new book[num];

    for(int i = 0 ; i < num; i++)
    {
        cout<<"Enter title of book"<<i+1<<":";
        cin>>books[i].title;
        cout<<"Enter author of book"<<i+1<<":";
        cin>>books[i].author;
        cout<<"Enter year of book"<<i+1<<":";
        cin>>books[i].year;
        cout<<"\n";
    }

    int year;
    cout<<"After what year of books you want to be displayed:";
    cin>>year;

    for(int i = 0 ; i < num ; i++){
        if(books[i].year > year)
        {
        cout<<"Book"<<i+1<<":"<<endl;
        cout<<"Author : "<<books[i].author<<endl;
        cout<<"Title : "<<books[i].title<<endl;
        cout<<"Year : "<<books[i].year<<endl;
        }
    }

    delete[] books;
}
