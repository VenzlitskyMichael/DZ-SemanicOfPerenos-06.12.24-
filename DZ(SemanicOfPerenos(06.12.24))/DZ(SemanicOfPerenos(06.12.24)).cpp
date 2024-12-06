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
        cout << "������� ������: ";
        getline(cin, Author);

        cout << "������� ����� �����: ";
        getline(cin, Text);

        cout << "������� ���������� �������: ";
        cin >> Pages;

        cout << "������� ��� �������: ";
        cin >> Year;
    }

    void Print() const {
        cout << "�����: " << (Author.empty() ? "�� ������" : Author) << endl;
        cout << "����� �����: " << (Text.empty() ? "�� ������" : Text) << endl;
        cout << "���������� �������: " << Pages << endl;
        cout << "��� �������: " << Year << endl;
    }
};

int main() {
    setlocale(0, "ru");

    Book book1;
    book1.Input();

    cout << "\n���������� � �����:\n";
    book1.Print();

    cout << "\n����������� �������...\n";
    Book book2 = move(book1);

    cout << "���������� � ����� ������� (����� �����������):\n";
    book2.Print();

    cout << "\n���������� �� �������� ������� (����� �����������):\n";
    book1.Print();

    return 0;
}
