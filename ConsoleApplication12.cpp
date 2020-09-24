#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int chooseFillArr();
void setColor(int, int);
int chooseMenu();

class workWithArray {
	int** mas;
	int n, m, id;
	static int count;
public:
	void fillArray();
	void swapMaxAndMin();
	void swapStrArray();
	void printArray() const;
	int getId();
	workWithArray(int ValueN, int ValueM);
	~workWithArray();
};

workWithArray::workWithArray(int ValueN, int ValueM) {
	n = ValueN; m = ValueM;
	mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
	count++;
	id = count;
}

workWithArray::~workWithArray() {
	for (int i = 0; i < n; i++)
		delete[]mas[i];
	delete[]mas;
}

void workWithArray::printArray() const {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	system("pause");
	system("cls");
}

int workWithArray::getId()
{
	return id;
}

void workWithArray::fillArray() {
	int choose = chooseFillArr();
	if (choose == 0) {
		system("cls");
		cout << "Введите левый диапозон рандома: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Введите правый диапозон рандома: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Введите элементы массива: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " - строка из " << m << " символов: ";
			for (int j = 0; j < m; j++)
				cin >> mas[i][j];
		}
	}
}

void workWithArray::swapMaxAndMin() {
	int min = mas[0][0], max = mas[0][0];
	int mini = 0, minj = 0, maxi = 0, maxj = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
				maxi = i;
				maxj = j;
			}
			if (mas[i][j] < min) {
				min = mas[i][j];
				mini = i;
				minj = j;
			}
		}
	int swap = 0;
	swap = mas[maxi][maxj];
	mas[maxi][maxj] = mas[mini][minj];
	mas[mini][minj] = swap;
}

void workWithArray::swapStrArray() {
	int swap = 0;
	for (int i = 0; i < n - 1; i = i + 2)
		for (int j = 0; j < m; j++) {
			swap = mas[i][j];
			mas[i][j] = mas[i + 1][j];
			mas[i + 1][j] = swap;
		}
}

int workWithArray::count = 0;

int main()
{
	setlocale(0, "rus");
	int n = 0, m = 0;
	cout << "Введите размеры массива для создания: " << endl;
	cout << "N - ";
	cin >> n;
	cout << "M - ";
	cin >> m;
	system("cls");
	workWithArray Array(n, m);
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			Array.fillArray();
			system("cls");
		}else
			if (choose == 1) {
				Array.swapMaxAndMin();
				cout << "Максимальный и минимальный элементы матрицы поменяны." << endl;
				system("pause");
				system("cls");
			}else
				if (choose == 2) {
					Array.swapStrArray();
					cout << "Строки попарно поменяны." << endl;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						Array.printArray();
					}
					else
						if (choose == 4) {
							cout << "ID объекта Array = " << Array.getId() << endl;
							system("pause");
							system("cls");
						}else
							break;
	}
	return 0;
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Заполнить матрицу" << endl; setColor(15, 0); }
		else { cout << " Заполнить матрицу" << endl; }

		if (choose_menu == 1) { setColor(2, 0); cout << " -> Поменять местами максимальный и минимальный элементы" << endl; setColor(15, 0); }
		else { cout << " Поменять местами максимальный и минимальный элементы" << endl; }

		if (choose_menu == 2) { setColor(2, 0); cout << " -> Поменять строки попарно местами" << endl; setColor(15, 0); }
		else { cout << " Поменять строки попарно местами" << endl; }

		if (choose_menu == 3) { setColor(2, 0); cout << " -> Вывести матрицу" << endl; setColor(15, 0); }
		else { cout << " Вывести матрицу" << endl; }

		if (choose_menu == 4) { setColor(2, 0); cout << " -> Вывести ID объекта" << endl; setColor(15, 0); }
		else { cout << " Вывести ID объекта" << endl; }

		if (choose_menu == 5) { setColor(2, 0); cout << " -> Завершить программу" << endl; setColor(15, 0); }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseFillArr() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите как заполнить матрицу: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { setColor(2, 0); cout << " -> Через рандом" << endl; setColor(15, 0); }
		else { cout << " Через рандом" << endl; }

		if (choose_menu == 1) { setColor(2, 0); cout << " -> С клавиатуры" << endl; setColor(15, 0); }
		else { cout << " С клавиатуры" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

void setColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}