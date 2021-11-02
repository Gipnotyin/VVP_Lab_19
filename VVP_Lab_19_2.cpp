#include <iostream>
#include <vector>

using namespace std;

void FillArray(int* arr,int n) {
	cout << "Заполните массив, состоящий из " << n << " элементов\n";
	for (unsigned int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}
void ShowArray(int* arr,int n) {
	cout << "{ ";
	for (unsigned int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "}\n";
}
void Array(int*& arr, int& size, int a) {
	int* Array = new int[a];
	for (int i = 0; i < a; i++) {
		Array[i] = 0;
	}
	delete[] arr;
	size = a;
	arr = Array;
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector <int>  Dobavka;
	vector <int> Dob;
	vector <int> Negative;
	vector <int> Positive;
	bool end = true;
	int s = 1, max, min;
	int* OneVal = new int[s];
	int* OneVal1 = new int[s];
	int* Delete = new int[s];
	int* Delete1 = new int[s];
	int* Copy = new int[s];
	int y, n, c, size, d;
	while (end == true) {
		cout << "Выберите задание: ";
		cin >> y;
		if (y >= 1 and y <= 5)
		{
			switch (y)
			{
			case 1:
				system("cls");
				cout << "Вы просматриваете " << y <<" задание: \n";
				cout << "Дан целочисленный массив размера N.\nУдалить из массива все соседние одинаковые элементы, оставив их первые вхождения.\n";
				cout << "Введите размер массива: ";
				cin >> size;
				c = 1;
				Array(OneVal, s, size);
				Array(OneVal1, s, size);
				FillArray(OneVal, size);
				OneVal1[0] = OneVal[0];
				ShowArray(OneVal, size);
				for (unsigned int i = 1; i < size; i++) {
					if (OneVal[i] != OneVal[i - 1]) {
						OneVal1[c] = OneVal[i];
						c += 1;
					}
				}
				delete[] OneVal;
				*&OneVal = OneVal1;
				ShowArray(OneVal, c);
				delete[] OneVal1;
				break;
			case 2:
				system("cls");
				cout << "Вы просматриваете " << y << " задание: \n";
				cout << "Дан целочисленный массив размера N.\nУдалить из массива все элементы, встречающиеся ровно два раза, и вывести размер полученного массива и его содержимое.\n";
				cout << "Введите размер массива: ";
				cin >> size;
				d = 0;
				Array(Delete, s, size);
				Array(Delete1, s, size);
				FillArray(Delete, size);
				ShowArray(Delete, size);
				for (unsigned int i = 0; i < size; i++) {
					c = 1;
					for (unsigned int j = 0; j < size; j++) {
						if (Delete[i] == Delete[j] && i != j) {
							c += 1;
						}
					}
					if (c != 2) {
						Delete1[d] = Delete[i];
						d += 1;
					}
				}
				delete[] Delete;
				*&Delete = Delete1;
				ShowArray(Delete, d);
				delete[] Delete1;
				break;
			case 3:
				system("cls");
				cout << "Вы просматриваете " << y << " задание: \n";
				cout << "Дан массив размера N.\nВставить элемент с нулевым значением перед минимальным и после максимального элемента массива.\n";
				cout << "Введите размер массива: ";
				cin >> size;
				Dobavka.reserve(size);
				Dob.reserve(size);
				cout << "Заполните массив: ";
				for (int i = 0; i < size; i++) {
					cin >> d;
					Dobavka.push_back(d);
				}
				max = Dobavka[0];
				min = Dobavka[0];
				for (int i = 1; i < size; i++) {
					if (max <= Dobavka[i]) {
						max = Dobavka[i];
					}
					if (min >= Dobavka[i]) {
						min = Dobavka[i];
					}
				}
				c = 0;
				for (int i = 0; i < size; i++) {
					if (Dobavka[i] == max) {
						Dob.push_back(Dobavka[i]);
						Dob.push_back(Dobavka[0]);
						c += 1;
					}
					else if (Dobavka[i] == min) {
						Dob.push_back(Dobavka[0]);
						Dob.push_back(Dobavka[i]);
						c += 1;
					}
					else {
						Dob.push_back(Dobavka[i]);
					}
				}
				cout << "{ ";
				for (int i = 0; i < size+c; i++) {
					cout << Dob[i] << " ";
				}
				cout << "}\n";
				Dobavka.clear();
				Dobavka.shrink_to_fit();
				Dob.clear();
				Dob.shrink_to_fit();
				break;
			case 4:
				system("cls");
				cout << "Вы просматриваете " << y << " задание: \n";
				cout << "Дан массив размера N.\nПосле каждого отрицательного элемента массива вставить элемент с нулевым значением.\n";
				cout << "Введите размер массива: ";
				cin >> size;
				Negative.reserve(size);
				cout << "Заполните массив: ";
				c = 0;
				for (int i = 0; i < size; i++) {
					cin >> d;
					if (i == 0 and d >=0) {
						Negative.push_back(d);
					} 
					else if (i == 0 and d < 0) {
						Negative.push_back(d);
						Negative.push_back(Negative[0]);
						c += 1;
					}
					else if (i != 0 and d < 0) {
						Negative.push_back(d);
						Negative.push_back(Negative[0]);
						c += 1;
					}
					else if (i != 0 and d >= 0) {
						Negative.push_back(d);
					}
				}
				cout << "{ ";
				for (int i = 0; i < size + c; i ++) {
					cout << Negative[i] << " ";
				}
				cout << "}\n";
				Negative.clear();
				Negative.shrink_to_fit();
				break;
			case 5:
				system("cls");
				cout << "Вы просматриваете " << y << " задание: \n";
				cout << "Дан массив размера N.\nПеред каждым положительным элементом массива вставить элемент с нулевым значением.\n";
				cout << "Введите размер массива: ";
				cin >> size;
				Positive.reserve(size);
				c = 0;
				for (int i = 0; i < size; i++) {
					cin >> d;
					if (i == 0 and d <= 0) {
						Positive.push_back(d);
					}
					else if (i == 0 and d > 0) {
						Positive.push_back(d);
						Positive.push_back(Positive[0]);
						swap(Positive[0], Positive[1]);
						c++;
					}
					else if (i != 0 and d > 0) {
						Positive.push_back(Positive[0]);
						Positive.push_back(d);
						c++;
					}
					else if (i != 0 and d <= 0) {
						Positive.push_back(d);
					}
				}
				cout << "{ ";
				for (int i = 0; i < size + c; i++) {
					cout << Positive[i] << " ";
				}
				cout << "}\n";
				Positive.clear();
				Positive.shrink_to_fit();
				break;
			}
		}
		else {
			system("cls");
			cout << "Спасибо за проверку лаб!!!:))\n";
			end = false;
		}
	}
	delete[] OneVal;
	delete[] OneVal1;
	delete[] Delete;
	delete[] Delete1;
}