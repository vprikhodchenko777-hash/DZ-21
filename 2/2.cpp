
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Book
{
private:
    char title[100];
    char author[50];
    int pages = 0;
    int year = 0;

public:
    void setTitle(const char* newTitle)
    {
        strcpy_s(title, 100, newTitle);
    }

    void setAuthor(const char* newAuthor)
    {
        strcpy_s(author, 50, newAuthor);
    }

    bool setPages(int newPages)
    {
        if (newPages < 1 || newPages > 5000)
            return false;

        pages = newPages;
        return true;
    }

    bool setYear(int newYear)
    {
        if (newYear < 1450 || newYear > 2026)
            return false;

        year = newYear;
        return true;
    }

    const char* getTitle() { return title; }
    const char* getAuthor() { return author; }
    int getPages() { return pages; }
    int getYear() { return year; }

    bool isThick();
    void print();
};

inline bool Book::isThick()
{
    return pages > 500;
}

void Book::print()
{
    cout << "Название: " << title << endl;
    cout << "Автор: " << author << endl;
    cout << "Страниц: " << pages << endl;
    cout << "Год: " << year << endl;

    if (isThick())
        cout << "Книга толстая" << endl;

    cout << endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Book a, b;

    a.setTitle("Война и мир");
    a.setAuthor("Толстой");
    a.setPages(1200);
    a.setYear(1869);

    b.setTitle("Гарри Поттер");
    b.setAuthor("Роулинг");
    b.setPages(350);
    b.setYear(1997);

    if (!b.setYear(3000))
        cout << "Ошибка: неверный год!" << endl;

    a.print();
    b.print();

    return 0;
}
