#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

//int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int push_index);
int* erase(int arr[], int& n, int pop_index);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols);
///// <summary>
///// ??? allocate(???);		//������� ��������� ������������ ������		DONE
//? ? ? clear(? ? ? );			//������� ��������� ������������ ������		DONE
//? ? ? push_row_back(? ? ? );		//��������� ������ � ����� �������		DONE
//? ? ? push_row_front(? ? ? );	//��������� ������ � ������ �������			DONE
//? ? ? insert_row(? ? ? );		//�������� ������ � ������ �� ���������� ������� ???
//? ? ? pop_row_back(? ? ? );		//������� ������ � ����� �������		DONE
//? ? ? pop_row_front(? ? ? );		//������� ������ � ������ �������		???
//? ? ? erase_row(? ? ? );			//������� ������ �� ������� �� ���������� ������� ???
///// </summary>

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� � ����� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	cout << "������ � ����������� � ����� ���������: " << endl;
	Print(arr, n);

	arr = pop_back(arr, n);
	cout << "������ � ��������� ��������� ��������� �������: " << endl;
	Print(arr, n);

	cout << "������� ����������� � ������ ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	cout << "������ � ����������� � ������ ���������: " << endl;
	Print(arr, n);

	int push_index;
	cout << "\n" << "������� �������� ������� ����� �������� � ������: "; cin >> value;
	cout << "\n" << "������� ������ ������� ������������ �������� (��������� ��������� ���������� � \"0\"): "; cin >> push_index;
	cout << "\n" << "���������� ������ ������:" << endl;
	arr = insert(arr, n, value, push_index);
	Print(arr, n);

	int pop_index;
	cout << "\n" << "������� ������� ���������� �������� (��������� ��������� ���������� � \"0\"): "; cin >> pop_index;
	arr = erase(arr, n, pop_index);
	Print(arr, n);

	delete[]arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "������� ������ �������: " << endl;
	cin >> rows >> cols;
	//1)��������� ��������� �� ���������, � ��������� � ���� ����� ������� ����������:
	int** arr = new int* [rows];
	//https://github.com/okovtun/BV_122/blob/e9af64b53a157a7f3bd315c2c9de4176e4f3752d/DynamicMemory/DynamicMemory/main.cpp#L78
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);
	push_col_back(arr, rows, cols);
	cout << "������ � ����������� � ������ ���������: " << endl;
	Print(arr, rows, cols);
	/*cout;*/
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
#endif // DYNAMIC_MEMORY_2

}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	//���������� ���������� ������������� �������:
		//1) ��������� ��������� �� ��������� � ��������� � ���� ����� ������� ����������

	int** arr = new int* [rows];
	//2) ������� ������ ���:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	//3) �������� ���
	//������� ������
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	//������� ������ ����������
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
	//���������� �������� � ������
	//1)������� �������� ������ ������� �������
	int* buffer = new int[n + 1];
	//2)�������� �������� ������ � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������
	delete[] arr;
	//4)�������� �������� ������ ����� (��������) ��������, �� ���� ������� ������
	arr = buffer;
	//5)������ ����� ���� ���� �������� ����� �������� ������� � ����� �������
	arr[n] = value;
	//6)����� ���������� �������� � ������ ���������� ��� ��������� ������������� �� 1
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

int* insert(int arr[], int& n, int value, int push_index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < push_index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = push_index + 1; i < n + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	arr[push_index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int pop_index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < pop_index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = pop_index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}


void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) ������� �������� ������, �������� �� 1 ������� ������;
		int* buffer = new int[cols + 1]{};
		//2)�������� �������� ������ � ��������;
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3)������� �������� ������
		delete[] arr[i];
		arr[i] = buffer;
	}
	//4) ����� ����, ��� � ������� ������ ���������� �� ��������
	//   ���������� �������� ����������� �� 1
	cols++;
}

void push_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) ������� �������� ������, �������� �� 1 ������� ������;
		int* buffer = new int[cols + 1]{};
		//2)�������� �������� ������ � ��������;
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		//3)������� �������� ������
		delete[] arr[i];
		arr[i] = buffer;
	}
	//4) ����� ����, ��� � ������� ������ ���������� �� ��������
	//   ���������� �������� ����������� �� 1
	cols++;
}