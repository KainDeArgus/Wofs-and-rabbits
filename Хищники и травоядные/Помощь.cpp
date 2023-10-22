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

    cout << enter10 << tab << "���� ���� ������� � ���, ����� ����� �������� ����� ������������ �������� � ������������ ����������.\n      ��������� �������������� ������ ������ �� ����� � ������ ������������� �������� ����� ������� � �������.\n" << tab2 << tab2 << "�����!";
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

    cout << enter << enter << enter << tab << "��, ��� ����� ������������ - ��� 1) ������ ���������� �������; 2) ���������." << enter;
    cout << tab << "������� ������������ ��� < # >." << enter;
    cout << tab << "���������� ������������ ��� < o >." << enter;
    cout << tab << "���� � ������� ����� ������ ������ ����� �����������, �� �� ���������� ��������� ������ ��������." << enter;
    cout << tab << "���� � ������� ����� ������ ���������� ����� ������, �� 10 ���� ������ ����� �����������������." << enter;
    cout << tab << "�������� ��� � ��� �������� �� ���� � ��� �������� � ��������� �� 40 ����: < X >." << enter;
    cout << tab << "���� �� ����� ������ ����������� 2 ��������, �� ���������� ����������� ������ �� ����������." << enter;
    cout << tab << "��� �������� ����� � �����������, �� �������� �� ����� ���������." << enter;
    cout << tab << "���� �� �����, ����� ������ ����� ����� (>1600). �� �������� ��������." << enter;
    cout << tab << "�����!" << enter;
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
        cout << enter10 << tab2 << space20 << "<< ���� ���� >>" << enter2;
        cout << tab2 << space20 << "   ������� �������" << enter2;
        cout << tab2 << space20 << "   �����";
        break;
    case 2:
        cout << enter10 << tab2 << space20 << "   ���� ����" << enter2;
        cout << tab2 << space20 << "<< ������� ������� >>" << enter2;
        cout << tab2 << space20 << "   �����";
        break;
    case 3:
        cout << enter10 << tab2 << space20 << "   ���� ����" << enter2;
        cout << tab2 << space20 << "   ������� �������" << enter2;
        cout << tab2 << space20 << "<< ����� >>";
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