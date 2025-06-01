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
        cout << "������� �� ������\n";
        return;
    }
    if (el->phone == phone) {
        m_data[id] = el->next;
        delete el;
        cout << "�����\n";
        return;
    }
    while (el->next && el->next->phone != phone) el = el->next;
    if (el->next) {
        auto temp = el->next;
        el->next = el->next->next;
        delete temp;
        cout << "�����\n";
    }
    else {
        cout << "������� �� ������\n";
    }
}

void searchhash(int phone) {
    auto start = chrono::high_resolution_clock::now();
    int id = phone % m_length;
    hashNode* p = m_data[id];
    while (p && p->phone != phone) p = p->next;
    auto end = chrono::high_resolution_clock::now();
    if (p) {
        cout << "������: " << p->name << "\n�����: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "��\n";
    }
    else {
        cout << "������� �� ������\n";
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
        cout << counter << " - |" << el->phone << " ���: " << el->name << "|-->";
        while ((el = el->next))
            cout << "|" << el->phone << " ���: " << el->name << "|-->";
        cout << "NULL\n";
    }
}

int menu() {
    int choice;
    cout << "1. �������� �������\n";
    cout << "2. ������� �������\n";
    cout << "3. ����� �������\n";
    cout << "4. ������� �������\n";
    cout << "5. �����\n";
    cout << "�����: ";
    cin >> choice;
    return choice;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    cout << "������� ������ ������� \n";
    size_t size;
    cin >> size;

    resize(size);

    for (;;) {
        int phone;
        int choice = menu();

        if (choice < 0 || choice > 5) {
            cout << "������\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "\n�����: ";
            while (true) {
                cin >> phone;
                if (phone > INT_MAX) {
                    cout << "������� �����\n";
                    continue;
                }
                break;
            }
            cin.ignore();
            cout << "\n���: ";
            string name;
            getline(cin, name);
            addhash(phone, name);
            break;
        }
        case 2:
            cout << "\n�����: ";
            cin >> phone;
            deletehash(phone);
            break;
        case 3:
            cout << "\n�����: ";
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
