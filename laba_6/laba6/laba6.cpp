#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <chrono>
#define INT_MAX 32767

using namespace std;

struct hashNode {
    int phone{};
    string name{};
    hashNode* next{};

    hashNode(int ph, const string& nm)
        : phone{ ph }, name{ nm }, next{ nullptr }
    {}
};

size_t m_length;
vector<hashNode*> m_data;

void resize(size_t length) {
    m_length = length;
    m_data.resize(length, nullptr);
}

void addhash(int phone, const string& name) {
    int id = phone % m_length;
    hashNode* p = m_data[id];
    if (!p) {
        m_data[id] = new hashNode{ phone, name };
        return;
    }

    while (p->next) p = p->next;
    p->next = new hashNode{ phone, name };
}

void deletehash(int phone) {
    int id = phone % m_length;
    auto el = m_data[id];
    if (!el) {
        cout << "Элемент не найден\n";
        return;
    }
    if (el->phone == phone) {
        m_data[id] = el->next;
        delete el;
        cout << "Удалён\n";
        return;
    }
    while (el->next && el->next->phone != phone) el = el->next;
    if (el->next) {
        auto temp = el->next;
        el->next = el->next->next;
        delete temp;
        cout << "Удалён\n";
    }
    else {
        cout << "Элемент не найден\n";
    }
}

void searchhash(int phone) {
    auto start = chrono::high_resolution_clock::now();
    int id = phone % m_length;
    hashNode* p = m_data[id];
    while (p && p->phone != phone) p = p->next;
    auto end = chrono::high_resolution_clock::now();
    if (p) {
        cout << "Найден: " << p->name << "\nВремя: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "нс\n";
    }
    else {
        cout << "Элемент не найден\n";
    }
}

void outputtable() {
    int counter = 0;
    for (auto el : m_data) {
        counter++;
        if (!el) {
            cout << counter << " - " << "NULL" << '\n';
            continue;
        }
        cout << counter << " - |" << el->phone << " Имя: " << el->name << "|-->";
        while ((el = el->next))
            cout << "|" << el->phone << " Имя: " << el->name << "|-->";
        cout << "NULL\n";
    }
}

int menu() {
    int choice;
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Найти элемент\n";
    cout << "4. Вывести таблицу\n";
    cout << "5. Выйти\n";
    cout << "Выбор: ";
    cin >> choice;
    return choice;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    cout << "Введите размер таблицы \n";
    size_t size;
    cin >> size;

    resize(size);

    for (;;) {
        int phone;
        int choice = menu();

        if (choice < 0 || choice > 5) {
            cout << "Ошибка\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "\nНомер: ";
            while (true) {
                cin >> phone;
                if (phone > INT_MAX) {
                    cout << "Большое число\n";
                    continue;
                }
                break;
            }
            cin.ignore();
            cout << "\nИмя: ";
            string name;
            getline(cin, name);
            addhash(phone, name);
            break;
        }
        case 2:
            cout << "\nНомер: ";
            cin >> phone;
            deletehash(phone);
            break;
        case 3:
            cout << "\nНомер: ";
            cin >> phone;
            searchhash(phone);
            break;
        case 4:
            outputtable();
            break;
        case 5:
            return 0;
        }
    }
}
