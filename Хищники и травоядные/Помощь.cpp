#include <iostream>
#include <conio.h>
#include <Windows.h>

#define enter endl
#define tab "\t"
#define tab2 "\t\t\t"
#define enter10 "\n\n\n\n\n\n\n\n\n\n"
#define enter2 "\n\n"
#define space20 "                    "

using namespace std;

extern void StartMenu(int switcher);

void Help(int switcher);

void GameTask() {
    system("cls");

    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    cout << enter10 << tab << "Суть игры состоит в том, чтобы найти гармонию между численностью хищников и численностью травоядных.\n      Пытайтесь минимизировать потери любого из видов и просто наслаждайтесь картиной дикой природы в консоли.\n" << tab2 << tab2 << "Удачи!";
    cout << enter << tab2 << tab;
    system("pause");
    Help(3);
}

void GameProcess() {
    system("cls");

    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    cout << enter << enter << enter << tab << "Всё, что может пользователь - это 1) ввести количество существ; 2) наблюдать." << enter;
    cout << tab << "Хищники обозначаются как < # >." << enter;
    cout << tab << "Травоядные обозначаются как < o >." << enter;
    cout << tab << "Если в радиусе одной клетки хищник учует травоядного, то от последнего останутся только косточки." << enter;
    cout << tab << "Если в радиусе одной клетки травоядное учует зелень, то 10 дней травка будет восстонавливаться." << enter;
    cout << tab << "Примерно раз в год животным не везёт и они попадают в катаклизм на 40 дней: < X >." << enter;
    cout << tab << "Если на одной клетке встречаются 2 существа, то начинается смертельная борьба за территорию." << enter;
    cout << tab << "Все животные живут в заповеднике, из которого не могут выбраться." << enter;
    cout << tab << "Игра не любит, когда зверей очень много (>1600). Не обижайте бедняжку." << enter;
    cout << tab << "Удачи!" << enter;
    cout << tab;
    system("pause");
    Help(3);
}

void Help(int switcher) {
	system("cls");

    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

	switch (switcher)
	{
    case 1:
        cout << enter10 << tab2 << space20 << "<< Цель игры >>" << enter2;
        cout << tab2 << space20 << "   Игровой процесс" << enter2;
        cout << tab2 << space20 << "   Назад";
        break;
    case 2:
        cout << enter10 << tab2 << space20 << "   Цель игры" << enter2;
        cout << tab2 << space20 << "<< Игровой процесс >>" << enter2;
        cout << tab2 << space20 << "   Назад";
        break;
    case 3:
        cout << enter10 << tab2 << space20 << "   Цель игры" << enter2;
        cout << tab2 << space20 << "   Игровой процесс" << enter2;
        cout << tab2 << space20 << "<< Назад >>";
        break;
    }
	int choice = _getch();
    if (choice == 224) {
        choice = _getch();
    }
    if (choice == 72) {
        if (switcher != 1)
            Help(switcher - 1);
        else
            Help(3);
    }
    if (choice == 80) {
        if (switcher != 3)
            Help(switcher + 1);
        else
            Help(1);
    }
    if (choice == 13 || choice == 32)
    {
        switch (switcher)
        {
        case 1:
            GameTask();
            break;
        case 2:
            GameProcess();
            break;
        case 3:
            StartMenu(1);
            break;
        }
    }
}