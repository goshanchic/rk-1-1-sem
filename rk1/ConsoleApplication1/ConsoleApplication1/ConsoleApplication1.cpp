#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct Book {
    char* title = nullptr;
    char* author = nullptr;
    int year = 0;
    int copies = 0;
};

// Функция для ввода данных о книге
void inputBook(Book& book, int index) {
    string tempTitle, tempAuthor;

    cout << "Введите название книги " << index + 1 << ": ";
    getline(cin, tempTitle);
    book.title = new char[tempTitle.size() + 1];
    strcpy_s(book.title, tempTitle.size() + 1, tempTitle.c_str());

    cout << "Введите автора книги " << index + 1 << ": ";
    getline(cin, tempAuthor);
    book.author = new char[tempAuthor.size() + 1];
    strcpy_s(book.author, tempAuthor.size() + 1, tempAuthor.c_str());

    cout << "Введите год издания книги " << index + 1 << ": ";
    cin >> book.year;

    cout << "Введите количество копий книги " << index + 1 << ": ";
    cin >> book.copies;
    cin.ignore(); // Очистка буфера ввода после числа
}

//  для сравнения названий книг
bool compareBooks(const Book& a, const Book& b) {
    if (a.title && b.title) { // Проверка, что строки title инициализированы
        return strcmp(a.title, b.title) < 0;
    }
    return false;
}

//  инфо о книге
void printBook(const Book& book, int index) {
    cout << index + 1 << ". " << book.title << " - Автор: " << book.author
        << ", Год издания: " << book.year
        << ", Количество копий: " << book.copies << endl;
}

// Функция для очистки памяти, выделенной под строки
void deleteBook(Book& book) {
    delete[] book.title;
    delete[] book.author;
    book.title = nullptr;
    book.author = nullptr;
}

int main() {
    const int numBooks = 2;  // Установлено фикс кол-во книг для удобство проверки

    // Динамическое выделение памяти для массива книг
    Book* library = new Book[numBooks];

    // Ввод данных о книгах
    for (int i = 0; i < numBooks; ++i) {
        inputBook(library[i], i);
    }

    // Сортировка книг по названию
    sort(library, library + numBooks, compareBooks);

    // Вывод отсортированного списка книг
    cout << "Список книг в библиотеке:";
    for (int i = 0; i < numBooks; ++i) {
        printBook(library[i], i);
    }

    // Освобождение памяти
    for (int i = 0; i < numBooks; ++i) {
        deleteBook(library[i]);
    }
    delete[] library;

    return 0;
}
