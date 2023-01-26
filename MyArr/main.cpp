#include <iostream>
#include"_array.h"
using namespace std;


int main()
{
	/*
	//����������� �� ���������
	_array() = default;
	//����������� ���������� ������ � ���� ������ ������������ ���-�� ��������� � ���������
	_array(int);
	//����������� �����������
	_array(const _array<T>& arr);
	//����������
	~_array();
	//�������� "=" � ������������
	_array& operator=(const _array<T>& arr);
	//������������� �������� ������
	template<class T>
	friend ostream& operator<<(ostream& out, _array<T>& arr);
	//���� � ����������
	void Input();
	//��-�� �������
	int GetSize();
	//��-�� ��� ������
	int GetGrow();
	//��������� �������+ ��������� ��� �����(����� ������ �� ������������)
	void SetSize(int s, int _grow = 0);
	//���� �� ������
	bool IsEmpty();
	//��������� ���������� ������ �������
	int GetUpperBound();
	//��������� �������� �� �������
	T GetAt(int index);
	//�������� �������� �������� �������
	void SetAt(int index, T value);
	void SetAt(int index, const T* value);
	//�������� �������������� ������
	void FreeExtra();
	//������� ���� ���������
	void RemoveAll();
	//�������� ����������
	T& operator[](int index);
	//���������� ������ ��������
	void Add();
	//�������� ��� ��������
	T* GetData();
	//������������ ��������
	void Append(const T** arr, int _size);
	void Append( T arr[], int _size);
	//������� ������ �������� ������ �� �������������
	void InsertAt(T value, int pos);
	//�������� �������� �� ������� ��� ������������
	void RemoveAt(int pos);
	*/
	cout << "1. ���� � ����������\n2. ��������� ���-�� ���������\n3. ��������� ���-�� ���. ������\n4. ��������� ������� �������+ ��������� ��� ������\n5. ����";
	setlocale(0, "ru");
	_array<int> arr;
	arr.Input(1,10);
	cout << arr << endl;
	arr.SetSize(15, 5);
	cout << arr << endl;
	arr.RemoveAt(3);
	cout << arr << endl;
}