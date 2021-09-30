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
///// ??? allocate(???);		//������� ��������� ������������ ������		DONE
//? ? ? clear(? ? ? );			//������� ��������� ������������ ������		DONE
//? ? ? push_row_back(? ? ? );		//��������� ������ � ����� �������		DONE
//? ? ? push_row_front(? ? ? );	//��������� ������ � ������ �������			DONE
//? ? ? insert_row(? ? ? );		//�������� ������ � ������ �� ���������� ������� ???
//? ? ? pop_row_back(? ? ? );		//������� ������ � ����� �������		DONE
//? ? ? pop_row_front(? ? ? );		//������� ������ � ������ �������		???
//? ? ? erase_row(? ? ? );			//������� ������ �� ������� �� ���������� ������� ???
///// </summary>


void main()
{
	setlocale(LC_ALL, "ru");

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

	/*cout;*/
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