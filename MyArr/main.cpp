#include <iostream>
#include"_array.h"
using namespace std;


int main()
{
	/*
	//конструктор по умолчанию
	_array() = default;
	//конструктор выделяющий память в куче размер необходимого кол-ва передаётся в параметры
	_array(int);
	//конструктор копирования
	_array(const _array<T>& arr);
	//деструктор
	~_array();
	//оператор "=" с копированием
	_array& operator=(const _array<T>& arr);
	//перегруженный оператор вывода
	template<class T>
	friend ostream& operator<<(ostream& out, _array<T>& arr);
	//ввод с клавиатуры
	void Input();
	//св-во размера
	int GetSize();
	//св-во доп памяти
	int GetGrow();
	//изменение размера+ веделение доп места(будет скрыто от пользователя)
	void SetSize(int s, int _grow = 0);
	//пуст ли массив
	bool IsEmpty();
	//последний допустимый индекс массива
	int GetUpperBound();
	//получение элемента из массива
	T GetAt(int index);
	//изменить значение элемента массива
	void SetAt(int index, T value);
	void SetAt(int index, const T* value);
	//очистить дополнительную память
	void FreeExtra();
	//очистка всех элементов
	void RemoveAll();
	//оператор индексации
	T& operator[](int index);
	//добавление нового элемента
	void Add();
	//получить все элементы
	T* GetData();
	//конкатеницая массивов
	void Append(const T** arr, int _size);
	void Append( T arr[], int _size);
	//вставка нового элемента массив не пересоздается
	void InsertAt(T value, int pos);
	//удаление элемента из массива без пересоздания
	void RemoveAt(int pos);
	*/
	cout << "1. Ввод с клавиатуры\n2. Получение кол-во элементов\n3. Получение кол-ва доп. памяти\n4. Изменение размера массива+ веделение доп памяти\n5. Пуст";
	setlocale(0, "ru");
	_array<int> arr;
	arr.Input(1,10);
	cout << arr << endl;
	arr.SetSize(15, 5);
	cout << arr << endl;
	arr.RemoveAt(3);
	cout << arr << endl;
}