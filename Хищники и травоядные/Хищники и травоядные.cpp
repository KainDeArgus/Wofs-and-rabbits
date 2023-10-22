#include <iostream>
#include <conio.h>
#include <Windows.h>

#define tab2 "\t\t\t"
#define enter10 "\n\n\n\n\n\n\n\n\n\n"
#define enter2 "\n\n"
#define space20 "                    "

using namespace std;

extern void Game();
extern void Help(int switcher);

void StartMenu(int switcher)
{
    system("cls");

    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    switch (switcher)
    {
    case 1:
        cout << enter10 << tab2 << space20 << "<< Играть >>" << enter2;
        cout << tab2 << space20 << "   Помощь" << enter2;
        cout << tab2 << space20 << "   Выход";
        break;
    case 2:
        cout << enter10 << tab2 << space20 << "   Играть" << enter2;
        cout << tab2 << space20 << "<< Помощь >>" << enter2;
        cout << tab2 << space20 << "   Выход";
        break;
    case 3:
        cout << enter10 << tab2 << space20 << "   Играть" << enter2;
        cout << tab2 << space20 << "   Помощь" << enter2;
        cout << tab2 << space20 << "<< Выход >>";
        break;
    }
    int choice = _getch();
    if (choice == 224) {
        choice = _getch();
    }
    if (choice == 72) {
        if (switcher != 1)
            StartMenu(switcher - 1);
        else
            StartMenu(3);
    }
    if (choice == 80) {
        if (switcher != 3)
            StartMenu(switcher + 1);
        else
            StartMenu(1);
    }
    if (choice == 13 || choice == 32)
    {
        switch (switcher)
        {
        case 1:
            Game();
            break;
        case 2:
            Help(1);
        case 3:
            exit;
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	system("color F0");

    StartMenu(1);
}