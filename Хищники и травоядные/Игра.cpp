#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <string>

// моды

#define enter endl
#define tab "\t"
#define tab2 "\t\t"
#define enter10 "\n\n\n\n\n\n\n\n\n\n"
#define enter2 "\n\n"
#define space20 "                    "

using namespace std;

int RabbitMaxCount(0), VolfMaxCount(0), MaxRabbitAge(0), MaxVolfAge(0), RabbitDeadCount(0), VolfDeadCount(0), GrassWasEaten(0);
const int width = 80, height = 20;
bool GameOver = false;
int Timer = 1;
int CataclismeTimer = 0;

void Statistic() {
	cout << enter << "Статистика: " << enter;;
	cout << "Максимальное количество травоядных за всю игру: " << RabbitMaxCount << enter;
	cout << "Максимальное количество хищников за всю игру: " << VolfMaxCount << enter << enter;;
	cout << "Максимальный возраст травоядного за всю игру: " << MaxRabbitAge << enter;
	cout << "Максимальный возраст хищника за всю игру: " << MaxVolfAge << enter << enter;
	cout << "Всего травоядных умерло: " << RabbitDeadCount << enter;
	cout << "Всего хищников умерло: " << VolfDeadCount << enter << enter;
	cout << "Всего травы было съедено: " << GrassWasEaten << enter;
}

void End() {
	system("cls");
	cout << enter10 << tab2 << tab2 << "Никто не выжил! Попробуйте изменить количество существ и может быть что-то изменится..." << enter;
	Statistic();
	system("pause");
}

void CheckPozition(vector<vector<char>>& cataclisme,vector<vector<int>>& volf, vector<vector<int>>& rabbit) {
	if (!rabbit.empty()) {
		for (int i = 0; i < volf.size(); i++) {
			for (int j = 0; j < rabbit.size(); j++) {
				if ((volf[i][1] == rabbit[j][1]) && (volf[i][2] == rabbit[j][2])) {
					auto iter = rabbit.cbegin();
					rabbit.erase(iter + j);
					RabbitDeadCount++;
				}
			}
		}
		for (int i = 0; i < rabbit.size() - 1; i++) {
			for (int j = i + 1; j < rabbit.size(); j++) {
				if ((rabbit[i][1] == rabbit[j][1]) && (rabbit[i][2] == rabbit[j][2])) {
					auto iter = rabbit.cbegin();
					rabbit.erase(iter + j);
					RabbitDeadCount++;
				}
			}
		}
		for (int i = 0; i < rabbit.size(); i++) {
			if (cataclisme[rabbit[i][2]][rabbit[i][1]] == 'X') {
				auto iter = rabbit.cbegin();
				rabbit.erase(iter + i);
				RabbitDeadCount++;
			}
		}
	}
	if (!volf.empty()) {
		for (int i = 0; i < volf.size() - 1; i++) {
			for (int j = i + 1; j < volf.size(); j++) {
				if ((volf[i][1] == volf[j][1]) && (volf[i][2] == volf[j][2])) {
					auto iter = volf.cbegin();
					volf.erase(iter + j);
					VolfDeadCount++;
				}
			}
		}
		for (int i = 0; i < volf.size(); i++) {
			if (cataclisme[volf[i][2]][volf[i][1]] == 'X') {
				auto iter = volf.cbegin();
				volf.erase(iter + i);
				VolfDeadCount++;
			}
		}
	}
	
}

void Input(int& a, int& b) {
	system("cls");
	cout << enter10 << tab2 << space20 << "Введите начальное количество хищников: ";
	int countV; cin >> countV;
	system("cls");
	cout << enter10 << tab2 << space20 << "Введите начальное количество травоядных: ";
	int countR; cin >> countR;
	if ((countV + countR) > 1600) {
		system("cls");
		cout << enter10 << space20 << "Я слабая программа и неоптимизированна.... Попробуйте ввести числа поменьше." << enter;
		cout << tab2 << space20 << "Для продолжения нажмите любую кнопку." << enter;
		system("pause");
		Input(a, b);
	}
	else{ a = countV; b = countR; }
}

bool Cataclisme(vector<vector<char>>& cataclisme) {
	int variability = rand() % 365;
	//int variability = 0;
	if (variability == 0) {
		int move = rand() % 4 + 1;
		//int move = 3;
		//1 - слева 2 - справа 3 - снизу 4 - сверху
		int great = rand() % 100 + 1;
		//1 - 50% 2 - 30% 3 - 10% 4 - 5% 5 - 3% 10 - 2%	}
		int CataclismeCount(0);
		if (great <= 50) {
			CataclismeCount = 1;
		}
		else {
			if ((great > 50) && (great <= 80)) {
				CataclismeCount = 2;
			}
			else {
				if ((great > 80) && (great <= 90)) {
					CataclismeCount = 3;
				}
				else {
					if ((great > 90) && (great <= 95)) {
						CataclismeCount = 4;
					}
					else {
						if ((great > 95) && (great <= 98)) {
							CataclismeCount = 5;
						}
						else {
							if ((great > 98) && (great <= 100)) {
								CataclismeCount = 10;
							}
						}
					}
				}
			}
		}
		//CataclismeCount = 10;
		switch (move)
		{
		case 1:
			for (int i = 1; i < CataclismeCount + 1; i++) {
				for (int j = 1; j < height+1; j++) {
					cataclisme[j][i] = 'X';
				}
			}
			break;
		case 2:
			for (int i = width + 2 - CataclismeCount; i < width + 2; i++) {
				for (int j = 0; j < height+1; j++) {
					cataclisme[j][i] = 'X';
				}
			}
			break;
		case 3:
			for (int i = cataclisme.size() - CataclismeCount - 1; i < cataclisme.size() - 1; i++) {
				for (int j = 0; j < width+2; j++) {
					cataclisme[i][j] = 'X';
				}
			}
			break;
		case 4:
			for (int i = 1; i < CataclismeCount + 1; i++) {
				for (int j = 0; j < width+2; j++) {
					cataclisme[i][j] = 'X';
				}
			}
			break;
		}
		return true;
	}
	return false;
}
int SymbolCount(int a) {
	int i;
	for ( i = 0; a > 0; i++, a /= 10);
	return i;
}
void Picter(vector<vector<pair<bool, int>>>& grass,vector<vector<char>>& cataclisme,vector<vector<int>>& volf, vector<vector<int>>& rabbit) {
	
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd;
	cd.X = 0;
	cd.Y = 0;
	SetConsoleCursorPosition(hd, cd);

	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 3; j++) { 
			if ((i == 0) || (i == height + 1)) { cout << "-"; continue; }
			if ((j == 0) || (j == width + 2)) { cout << "|"; continue; }
			bool spawn = false;
			for (int g = 0; g < volf.size(); g++) {
				if ((volf[g][1] == j) && (volf[g][2] == i)) {
					if (grass[volf[g][2]][volf[g][1]].first) {
						SetConsoleTextAttribute(hd, (((15 << 4) | 2)));
						cout << "#";
						SetConsoleTextAttribute(hd, (((15 << 4) | 0)));
						spawn = true;
						break;
					}
					else { cout << "#"; spawn = true; break;}
				}
			}
			for (int g = 0; g < rabbit.size(); g++) {
				if ((rabbit[g][1] == j) && (rabbit[g][2] == i)) {
					if (grass[rabbit[g][2]][rabbit[g][1]].first) {
						SetConsoleTextAttribute(hd, (((15 << 4) | 2)));
						cout << "o";
						SetConsoleTextAttribute(hd, (((15 << 4) | 0)));
						spawn = true;
						break;
					}
					else { cout << "o"; spawn = true; break;}
				}
			}
			if (!spawn) {
				if (cataclisme[i][j] == 'X') {
					SetConsoleTextAttribute(hd, (((15 << 4) | 4)));
					cout << "X";
					SetConsoleTextAttribute(hd, (((15 << 4) | 0)));
					continue;
				}
			}
			if (!spawn) {
				if (grass[i][j].first) {
					SetConsoleTextAttribute(hd, (((15 << 4) | 2)));
					cout << ".";
					SetConsoleTextAttribute(hd, (((15 << 4) | 0)));
				}
				else { cout << "."; }
			}
		}
		cout << enter;
	}
	if ((Timer == 1) && ((RabbitDeadCount != 0) || (VolfDeadCount != 0))) {
		cout << "К сожалению некоторые животные погибли в борьбе за территорию...";
	}
	cout << enter << "Таймер: " << Timer << enter;
	string size;
	for (int i = 0; i < abs(4 - SymbolCount(volf.size())); i++) { size += "0"; }
	if (!volf.empty()) { size += to_string(volf.size()); }
	cout << "Количество волков: " << size;
	size.clear();
	for (int i = 0; i < abs(4 - SymbolCount(rabbit.size())); i++) { size += "0"; }
	if (!rabbit.empty()) { size += to_string(rabbit.size()); }
	cout << enter << "Количество зайцев: " << size << enter;
	cout << "Для выхода из программы нажмите Esc.\nЧтобы поставить игру на паузу и перейти в режим просмотра нажмите любую кнопку (кроме Esc)." << enter;
	if (Timer % 365 == 0) {
		system("pause");
	}
	if (Timer == 1) {
		system("pause");
		system("cls");
	}
}

void Logic(const int& RabbitMinReproductAge, const int& RabbitMaxReproductAge, const int& VolfMinReproductAge, const int& VolfMaxReproductAge, bool& CTCL, vector<vector<char>>& cataclisme, vector<vector<pair<bool, int>>>& grass, vector<vector<int>>& volf, vector<vector<int>>& rabbit, const int& VolfEatCount, const int& VolfTimeWEat, const int& RabbitTimeWEat, const int& RabbitEatCount, const int& VolfMaxAge, const int& RabbitMaxAge, const int& RabbitTimeReproduct, const int& VolfTimeReproduct, const int& GrassTimeRegen) {
	//Проверка на нахождения рядом кроликов
	for (int i = 0; i < volf.size(); i++) {
		for (int j = 0; j < rabbit.size(); j++) {
			if ((volf[i][1] == rabbit[j][1]) && ((volf[i][2] + 1 == rabbit[j][2]) || (volf[i][2] - 1 == rabbit[j][2]))) {
				volf[i][3] = VolfEatCount;
				auto iter = rabbit.cbegin();
				rabbit.erase(iter + j);
				RabbitDeadCount++;
			}
			else {
				if ((volf[i][2] == rabbit[j][2]) && ((volf[i][1] + 1 == rabbit[j][1]) || (volf[i][1] - 1 == rabbit[j][1]))) {
					volf[i][3] = VolfEatCount;
					auto iter = rabbit.cbegin();
					rabbit.erase(iter + j);
					RabbitDeadCount++;
				}
			}
		}
	}
	//Трава
	for (int i = 0; i < rabbit.size(); i++) {
		if ((rabbit[i][2] >= 0) && (rabbit[i][2] < height + 2) && (rabbit[i][1] < width + 3) && (rabbit[i][1] >= 0)) {
			if (grass[rabbit[i][2]][rabbit[i][1]].first) {
				grass[rabbit[i][2]][rabbit[i][1]].first = false;
				grass[rabbit[i][2]][rabbit[i][1]].second = GrassTimeRegen;
				GrassWasEaten++;
				rabbit[i][3] = RabbitEatCount;
				continue;
			}
		}
		if ((rabbit[i][2] >= 0) && (rabbit[i][2] < height + 2) && (rabbit[i][1] - 1 < width + 3) && (rabbit[i][1] - 1 >= 0)) {
			if (grass[rabbit[i][2]][rabbit[i][1] - 1].first) {
				grass[rabbit[i][2]][rabbit[i][1] - 1].first = false;
				grass[rabbit[i][2]][rabbit[i][1] - 1].second = GrassTimeRegen;
				GrassWasEaten++;
				rabbit[i][3] = RabbitEatCount;
				continue;
			}
		}
		if ((rabbit[i][2] >= 0) && (rabbit[i][2] < height + 2) && (rabbit[i][1] + 1 < width + 3) && (rabbit[i][1] + 1 >= 0)) {
			if (grass[rabbit[i][2]][rabbit[i][1] + 1].first) {
				grass[rabbit[i][2]][rabbit[i][1] + 1].first = false;
				grass[rabbit[i][2]][rabbit[i][1] + 1].second = GrassTimeRegen;
				GrassWasEaten++;
				rabbit[i][3] = RabbitEatCount;
				continue;
			}
		}
		if ((rabbit[i][2] - 1 >= 0) && (rabbit[i][2] - 1 < height + 2) && (rabbit[i][1] < width + 3) && (rabbit[i][1] >= 0)) {
			if (grass[rabbit[i][2] - 1][rabbit[i][1]].first) {
				grass[rabbit[i][2] - 1][rabbit[i][1]].first = false;
				grass[rabbit[i][2] - 1][rabbit[i][1]].second = GrassTimeRegen;
				GrassWasEaten++;
				rabbit[i][3] = RabbitEatCount;
				continue;
			}
		}
		if ((rabbit[i][2] + 1 >= 0) && (rabbit[i][2] + 1 < height + 2) && (rabbit[i][1] < width + 3) && (rabbit[i][1] >= 0)) {
			if (grass[rabbit[i][2] + 1][rabbit[i][1]].first) {
				grass[rabbit[i][2] + 1][rabbit[i][1]].first = false;
				grass[rabbit[i][2] + 1][rabbit[i][1]].second = GrassTimeRegen;
				GrassWasEaten++;
				rabbit[i][3] = RabbitEatCount;
				continue;
			}
		}
	}
	//Восстановление травы
	for (int i = 0; i < grass.size(); i++) {
		for (int j = 0; j < grass[i].size(); j++) {
			if (grass[i][j].second == 0) {
				grass[i][j].first = true;
			}
			else {
				grass[i][j].second--;
			}
		}
	}
	//Голод и передвижение волков
	for (int i = 0; i < volf.size(); i++) {
		if (volf[i][3] <= -VolfTimeWEat) {
			int variability = rand() % 100 + 1 + volf[i][0];
			if (variability > 40) {
				auto iter = volf.cbegin();
				volf.erase(iter + i);
				VolfDeadCount++;
			}
		}
		else {
			volf[i][3]--;
			int move = rand() % 3;
			if (move == 2) { move = -1; }
			if ((volf[i][1] + move < width + 2) && (volf[i][1] + move > 0)) { volf[i][1] += move; }
			move = rand() % 3;
			if (move == 2) { move = -1; }
			if ((volf[i][2] + move < height + 1) && (volf[i][2] + move > 0)) { volf[i][2] += move; }
		}
	}
	//Голод и передвижение зайцев
	for (int i = 0; i < rabbit.size(); i++) {
		if (rabbit[i][3] <= -RabbitTimeWEat) {
			int variability = rand() % 100 + rabbit[i][0] + 1;
			if (variability > 40) {
				auto iter = rabbit.cbegin();
				rabbit.erase(iter + i);
				RabbitDeadCount++;
			}
		}
		else {
			rabbit[i][3]--;
			int move = rand() % 3;
			if (move == 2) { move = -1; }
			if ((rabbit[i][1] + move < width + 2) && (rabbit[i][1] + move > 0)) { rabbit[i][1] += move; }
			move = rand() % 3;
			if (move == 2) { move = -1; }
			if ((rabbit[i][2] + move < height + 1) && (rabbit[i][2] + move > 0)) { rabbit[i][2] += move; }
		}
	}
	//Смерть от старости
	for (int i = 0; i < volf.size(); i++) {
		if (Timer % 365 == 0) {
			volf[i][0]++;
		}
		if (volf[i][0] > VolfMaxAge) {
			auto iter = volf.cbegin();
			volf.erase(iter + i);
			VolfDeadCount++;
		}
	}
	for (int i = 0; i < rabbit.size(); i++) {
		if (Timer % 365 == 0) {
			rabbit[i][0]++;
		}
		if (rabbit[i][0] > RabbitMaxAge) {
			auto iter = rabbit.cbegin();
			rabbit.erase(iter + i);
			RabbitDeadCount++;
		}
	}
	//Рождаемость
	if (!volf.empty() && (volf.size() != 1)) {
		if (Timer % VolfTimeReproduct == 0) {
			int count_volf(0);
			for (int i = 0; i < volf.size(); i++) {
				if ((volf[i][0] >= VolfMinReproductAge) && (volf[i][0] <= VolfMaxReproductAge)) {
					count_volf++;
				}
			}
			if (count_volf != 0) {
				int children = (count_volf / 2) + rand() % (count_volf / 2);
				for (int i = 0; i < children; i++) {
					vector<int> charactiristics = { 0,rand() % width ,rand() % height ,0 };
					volf.push_back(charactiristics);
				}
			}
		}
	}
	if (!rabbit.empty() && (rabbit.size() != 1)) {
		if (Timer % RabbitTimeReproduct == 0) {
			int count_rabbit(0);
			for (int i = 0; i < rabbit.size(); i++) {
				if ((rabbit[i][0] >= RabbitMinReproductAge) && (rabbit[i][0] <= RabbitMaxReproductAge)) {
					count_rabbit++;
				}
			}
			if (count_rabbit != 0) {
				int children = (count_rabbit / 2) * 3 + rand() % (count_rabbit / 2 * 5);
				for (int i = 0; i < children; i++) {
					vector<int> charactiristics = { 0,rand() % width ,rand() % height ,0 };
					rabbit.push_back(charactiristics);
				}
			}
		}
	}
	//Катаклизм
	if (CTCL) {
		CataclismeTimer++;
		if (CataclismeTimer == 40) {
			CTCL = false;
			for (int i = 0; i < cataclisme.size(); i++) {
				for (int j = 0; j < width + 3; j++) {
					cataclisme[i][j] = ' ';
				}
			}
			CataclismeTimer = 0;
		}
	}
	else {
		if (Cataclisme(cataclisme)) {
			CTCL = true;
		}
	}
	if (Timer % 365 == 0) {
		for (int i = 0; i < volf.size(); i++) {
			volf[i][0]++;
		}
		for (int i = 0; i < rabbit.size(); i++) {
			rabbit[i][0]++;
		}
	}
}
//0 - возраст, 1 - x, 2 - y, 3 - голод
void Game() {
	// волков 10 зайцев 100;

	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	srand(time(NULL));
	int VolfCount, RabbitCount;
	Input(VolfCount, RabbitCount);
	
	const int VolfMaxAge = 15;
	const int RabbitMaxAge = 6;

	const int VolfMinReproductAge = 2;
	const int VolfMaxReproductAge = 12;

	const int RabbitMinReproductAge = 0;
	const int RabbitMaxReproductAge = 4;

	const int RabbitTimeReproduct = 30;
	const int VolfTimeReproduct = 80;

	const int VolfTimeWEat = 50;
	const int VolfEatCount = 2;

	const int RabbitTimeWEat = 20;
	const int RabbitEatCount = 1;

	const int GrassTimeRegen = 20;
	
	bool CTCL = false;

	vector<vector<int>> volf;
	vector<vector<int>> rabbit;
	vector<vector<pair<bool, int>>> grass(height+2, vector<pair<bool, int>>(width + 3, { true,0 }));
	vector<vector<char>> cataclisme(height+2, vector<char>(width + 3, ' '));

	for (int i = 0; i < VolfCount; i++) {
		vector<int> charactiristics = { 5,rand() % width + 1 ,rand() % height + 1 ,0 };
		volf.push_back(charactiristics);
	}
	for (int i = 0; i < RabbitCount; i++) {
		vector<int> charactiristics = { 2,rand() % width + 1 ,rand() % height + 1,0 };
		rabbit.push_back(charactiristics);
	}
	while (!GameOver) {
		void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(handle, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(handle, &structCursorInfo);

		RabbitMaxCount = max(RabbitMaxCount, rabbit.size());
		VolfMaxCount = max(VolfMaxCount, volf.size());
		for (int i = 0; i < volf.size(); i++) {
			MaxVolfAge = max(MaxVolfAge, volf[i][0]);
		}
		for (int i = 0; i < rabbit.size(); i++) {
			MaxRabbitAge = max(MaxRabbitAge, rabbit[i][0]);
		}
		CheckPozition(cataclisme,volf, rabbit);
		Picter(grass,cataclisme,volf, rabbit);
		Logic(RabbitMinReproductAge, RabbitMaxReproductAge, VolfMinReproductAge, VolfMaxReproductAge, CTCL, cataclisme, grass, volf, rabbit, VolfEatCount, VolfTimeWEat, RabbitTimeWEat, RabbitEatCount, VolfMaxAge, RabbitMaxAge, RabbitTimeReproduct, VolfTimeReproduct, GrassTimeRegen);
		Timer += 1;
		if (volf.empty() && rabbit.empty()) { GameOver = true; }
		if (_kbhit()) { 
			if (_getch() == 27) {
				system("cls");
				cout << enter10 << tab2 << tab2 << "Вы уверены, что хотите ВЫЙТИ ?" << enter << tab2 << tab << "Чтобы подтвердить нажмите Esc, иначе нажмите Enter.";
				int press = _getch();
				if (press == 27) {
					exit(0);
				}
				else {
					if (press == 13) {
						Picter(grass, cataclisme, volf, rabbit);
						Statistic();
						system("pause");
						system("cls");
					}
				}
			}
			else { Statistic(); system("pause"); system("cls"); }
		}
	}
	End();
}