#include <iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    int publication_year;
    string genre;
};
void inputBooks(Book BOOKS[])
{
    for (int i = 0; i < 6; ++i)
    {
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Enter the title of book: ";
        cin >> BOOKS[i].title;
        cout << "Enter the name of author: ";
        cin >> BOOKS[i].author;
        cout << "Enter the publication Year of book: ";
        cin >> BOOKS[i].publication_year;
        cout << "Enter the Genre of book: ";
        cin >> BOOKS[i].genre;
        cout << endl << endl;
    }
}
void categorizeBooks(const Book BOOKS[], Book fiction[], Book nonFiction[], int& fictionCount, int& nonFictionCount)
{
    fictionCount = nonFictionCount = 0;

    for (int i = 0; i < 6; i++)
    {
        if (BOOKS[i].genre == "Fiction" || BOOKS[i].genre == "fiction")
        {
            fiction[fictionCount++] = BOOKS[i];
        }
        else
        {
            nonFiction[nonFictionCount++] = BOOKS[i];
        }
    }
}
void findEarliestBooks(const Book BOOKS[], int count, Book& earliestBook)
{
    earliestBook = BOOKS[0];
    for (int i = 1; i < count; ++i)
    {
        if (BOOKS[i].publication_year < earliestBook.publication_year)
        {
            earliestBook = BOOKS[i];
        }
    }
}
void displayBooks(const Book BOOKS[], int count, const Book& earliestBook)
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Title: " << BOOKS[i].title << "\n";
        cout << "Author: " << BOOKS[i].author << "\n";
        cout << "Publication Year: " << BOOKS[i].publication_year << "\n";
        cout << "Genre: " << BOOKS[i].genre << "\n";
        cout << endl;
    }
    cout << "Earliest Published Book:\n";
    cout << "Title: " << earliestBook.title << "\n";
    cout << "Author: " << earliestBook.author << "\n";
    cout << "Publication Year: " << earliestBook.publication_year << "\n";
    cout << "Genre: " << earliestBook.genre << "\n";
}
int main()
{
    Book BOOKS[6];
    Book fiction[6], nonFiction[6];
    int fictionCount, nonFictionCount;
    inputBooks(BOOKS);

    categorizeBooks(BOOKS, fiction, nonFiction, fictionCount, nonFictionCount);
    Book earliestFiction, earliestNonFiction;
    findEarliestBooks(fiction, fictionCount, earliestFiction);
    findEarliestBooks(nonFiction, nonFictionCount, earliestNonFiction);

    cout << "Fiction Books:\n";
    displayBooks(fiction, fictionCount, earliestFiction);
    cout << endl;
    cout << "\nNon-Fiction Books:\n";
    displayBooks(nonFiction, nonFictionCount, earliestNonFiction);
    return 0;
}
