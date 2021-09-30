#include<iostream>
using namespace std;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);

int* push_front(int arr[], int& n, int value);
int* pop_front(int arr[], int& n);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
///// <summary>
///// ??? allocate(???);		//Создает двумерный динамический массив		DONE
//? ? ? clear(? ? ? );			//Удаляет двумерный динамический массив		DONE
//? ? ? push_row_back(? ? ? );		//Добавляет строку в конец массива		DONE
//? ? ? push_row_front(? ? ? );	//Добавляет строку в начало массива			DONE
//? ? ? insert_row(? ? ? );		//Добвляет строку в массив по указанному индексу ???
//? ? ? pop_row_back(? ? ? );		//Удаляет строку с конца массива		DONE
//? ? ? pop_row_front(? ? ? );		//Удаляет строку с начала массива		???
//? ? ? erase_row(? ? ? );			//Удаляет строку из массива по указанному индексу ???
///// </summary>


void main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое в конец значение: "; cin >> value;
	arr = push_back(arr, n, value);
	cout << "Массив с добавленным в конце элементом: " << endl;
	Print(arr, n);

	arr = pop_back(arr, n);
	cout << "Массив с удаленным последним элементом массива: " << endl;
	Print(arr, n);

	cout << "Введите добавляемое в начало значение: "; cin >> value;
	arr = push_front(arr, n, value);
	cout << "Массив с добавленным в начало элементом: " << endl;
	Print(arr, n);

	/*cout;*/
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	//Объявление двумерного динамического массива:
		//1) Объявляем указатель на указатель и сохрнаяем в него адрес массива указателей

	int** arr = new int* [rows];
	//2) Создаем строки ДДМ:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	//3) Удаление ДДМ
	//Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	//Удаляем массив указателей
	delete[] arr;
}
void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}

}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";

	}
	cout << endl;
}

void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//добавление элемента в массив
	//1)создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2)копируем исходный массив в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удалить исходный массив
	delete[] arr;
	//4)подменем исходный массив новым (буферным) массивом, за счет подмены адреса
	arr = buffer;
	//5)Только после всех этих действий можно добавить значние в конец массива
	arr[n] = value;
	//6)После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем буферную строку, размером на 1 элемент больше;
		int* buffer = new int[cols + 1]{};
		//2)Копируем исходную строку в буферную;
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3)Удаляем исходную строку
		delete[] arr[i];
		arr[i] = buffer;
	}
	//4) После того, как в каждоый строке добавилось по элементу
	//   Количество столбцов увеличилось на 1
	cols++;
}