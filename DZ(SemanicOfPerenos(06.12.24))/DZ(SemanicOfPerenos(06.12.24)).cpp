#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string Author;
    string Text;
    int Pages;
    int Year;
public:
    Book() : Pages(0), Year(0) {}
    Book(const string& author, const string& text, int pages, int year)
        : Author(author), Text(text), Pages(pages), Year(year) {}

    Book(const Book& obj) = delete;
    Book& operator=(const Book& obj) = delete;

    Book(Book&& obj) 
        : Author(move(obj.Author)),
        Text(move(obj.Text)),
        Pages(obj.Pages),
        Year(obj.Year) {
        obj.Pages = 0;
        obj.Year = 0;
    }

    Book& operator=(Book&& obj) {
        if (this != &obj) {
            Author = move(obj.Author);
            Text = move(obj.Text);
            Pages = obj.Pages;
            Year = obj.Year;
            obj.Pages = 0;
            obj.Year = 0;
        }
        return *this;
    }

    void Input() {
        cout << "Введите автора: ";
        getline(cin, Author);

        cout << "Введите текст книги: ";
        getline(cin, Text);

        cout << "Введите количество страниц: ";
        cin >> Pages;

        cout << "Введите год издания: ";
        cin >> Year;
    }

    void Print() const {
        cout << "Автор: " << (Author.empty() ? "Не задано" : Author) << endl;
        cout << "Текст книги: " << (Text.empty() ? "Не задано" : Text) << endl;
        cout << "Количество страниц: " << Pages << endl;
        cout << "Год издания: " << Year << endl;
    }
};

int main() {
    setlocale(0, "ru");

    Book book1;
    book1.Input();

    cout << "\nИнформация о книге:\n";
    book1.Print();

    cout << "\nПеремещение объекта...\n";
    Book book2 = move(book1);

    cout << "Информация о новом объекте (после перемещения):\n";
    book2.Print();

    cout << "\nИнформация об исходном объекте (после перемещения):\n";
    book1.Print();

    return 0;
}
