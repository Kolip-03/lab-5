#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class Wear {
protected:
	int price;
	string country;
public:
	Wear(int w, string w1) {
		price = w;
		country = w1;
	}
	virtual void showData() = 0;
};

class Hoodi :public Wear {
private:
	string color;
	int size;
public:
	Hoodi(int w, string w1, string c, int yo) :Wear(w, w1) {
		color = c;
		size = yo;
	}
	void showData();
};

class Jeans :public Wear {
private:
	string color;
	int size;
public:
	Jeans(int w, string w1, string yo, int yo1) :Wear(w, w1) {
		color = yo;
		size = yo1;
	}
	void showData();
};

class Boots :public Wear {
private:
	string color;
	int size;
public:
	Boots(int w, string w1, string p, int yo) :Wear(w, w1) {
		color = p;
		size = yo;
	}
	void showData();
};

void Hoodi::showData() {
	cout << "	Толстовка: " << endl;
	cout << "Цена: " << price << endl;
	cout << "Страна производитель: " << country << endl;
	cout << "Размер: " << size << endl;
	cout << "Цвет: " << color << endl;
}

void Jeans::showData() {
	cout << "	Джинсы: " << endl;
	cout << "Цена: " << price << endl;
	cout << "Страна производитель: " << country << endl;
	cout << "Размер: " << size << endl;
	cout << "Цвет: " << color << endl;
}

void Boots::showData() {
	cout << "	Кроссовки: " << endl;
	cout << "Цена: " << price << endl;
	cout << "Страна производитель: " << country << endl;
	cout << "Размер: " << size << endl;
	cout << "Цвет: " << color << endl;
}

void hood(int&, string&, int&, string&);
void jean(int&, string&, int&, string&);
void boot(int&, string&, int&, string&);
int chooseMenu();
string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	int n = 1;
	Wear** mas = new Wear * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			int y2, y3;
			string country, color;
			hood(y2, country, y3, color);
			mas[n] = new Hoodi(y2, country, color, y3);
			mas[n]->showData();
			n++;
			n++;
			Wear** ptr = new Wear * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				int y2, y3;
				string country, color;
				jean(y2, country, y3, color);
				mas[n] = new Jeans(y2, country, color, y3);
				mas[n]->showData();
				n++;
				n++;
				Wear** ptr = new Wear * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					int y2, y3;
					string country, color;
					boot(y2, country, y3, color);
					mas[n] = new Boots(y2, country, color, y3);
					mas[n]->showData();
					n++;
					n++;
					Wear** ptr = new Wear * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->showData();
						system("pause");
						system("cls");
					}
					else break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Толстовка" << endl; }
		else { cout << " Толстовка" << endl; }

		if (choose_menu == 1) { cout << " -> Джинсы" << endl; }
		else { cout << " Джинсы" << endl; }

		if (choose_menu == 2) { cout << " -> Кроссовки" << endl; }
		else { cout << " Кроссовки" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
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

void hood(int& price, string& country, int& size, string& color) {
	cout << "	Толстовка: " << endl;
	cout << "Цена: ";
	price = writeNumbers();
	cout << endl;
	cout << "Страна производитель: ";
	country = writeWords();
	cout << endl;
	cout << "Размер: ";
	size = writeNumbers();
	cout << endl;
	cout << "Цвет: ";
	color = writeWords();
	system("cls");
}

void jean(int& price, string& country, int& size, string& color) {
	cout << "	Джинсы: " << endl;
	cout << "Цена: ";
	price = writeNumbers();
	cout << endl;
	cout << "Страна производитель: ";
	country = writeWords();
	cout << endl;
	cout << "Размер: ";
	size = writeNumbers();
	cout << endl;
	cout << "Цвет: ";
	color = writeWords();
	system("cls");
}

void boot(int& price, string& country, int& size, string& color) {
	cout << "	Кроссовки: " << endl;
	cout << "Цена: ";
	price = writeNumbers();
	cout << endl;
	cout << "Страна производитель: ";
	country = writeWords();
	cout << endl;
	cout << "Размер: ";
	size = writeNumbers();
	cout << endl;
	cout << "Цвет: ";
	color = writeWords();
	system("cls");
}