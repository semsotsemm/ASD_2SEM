#include <iostream>

using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool areBracketsCorrect(const char str[]) {
    char stack[1000];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1 || !isMatching(stack[top], ch))
            {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

int main() {
    char input[1000];
    setlocale(LC_CTYPE, "Russian");
    cout << "Введите строку: ";
    cin.getline(input, 1000);
    areBracketsCorrect(input) ? cout << "Скобки расставлены верно\n" : cout << "Скобки расставлены не верно\n";
    return 0;
}