#pragma once
#include<iostream>
#include <time.h>
using namespace std;
template<class T>
class _array
{
	//память
	T* ptr;
	//ограниченый размер
	int size;
	//дополнительная память
	int grow;
	//полный размер max_size=size+grow;
	int max_size;
public:
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
	//перегруженный оператор ввода
	template<class T>
	friend ostream& operator<<(ostream& out, _array<T>& arr);
	//ввод с клавиатуры
	void Input();
	//рандомная генерация
	void Input(int begin, int end);
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
};

template<class T>
inline _array<T>::_array(int s):size(s)
{
	max_size = size;
	ptr = new T[max_size];
}

template<class T>
inline _array<T>::_array<T>(const _array<T>& arr)
{
	grow = arr.grow;
	size = arr.size;
	max_size = arr.max_size;
	ptr = new T[max_size];
	for (int i = 0; i < max_size; i++)
		ptr[i] = arr.ptr[i];
}

template<class T>
inline _array<T>::~_array()
{
	delete[]ptr;
}

template<class T>
inline _array<T>& _array<T>::operator=(const _array<T>& arr)
{
	if (this == &arr)
		return *this;
	else
	{
		delete[]ptr;
		grow = arr.grow;
		size = arr.size;
		max_size = arr.max_size;
		ptr = new T[max_size];
		for (int i = 0; i < max_size; i++)
			ptr[i] = arr.ptr[i];
		return *this;
	}
}

template<class T>
inline void _array<T>::Input()
{
	if (ptr == nullptr)
	{
		cout << "Enter size: " << endl;
		cin >> size;
		max_size = size;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
		{
			cin >> ptr[i];
		}
	}
	else 
	{
		for (int i = 0; i < size; i++)
		{
			cin >> ptr[i];
		}
	}
}

template<class T>
inline void _array<T>::Input(int begin, int end)
{
	srand(time(NULL));
	if (ptr == nullptr)
	{
		cout << "Enter size: " << endl;
		cin >> size;
		max_size = size;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = rand() % end + begin;
	}
	else
	{
		for (int i = 0; i < size; i++)
			ptr[i] = rand() % end + begin;
		
	}
}

template<class T>
inline int _array<T>::GetSize()
{
	return size;
}

template<class T>
inline int _array<T>::GetGrow()
{
	return grow;
}

template<class T>
inline void _array<T>::SetSize(int s, int _grow)
{
	grow = _grow;
	if (ptr == nullptr)
	{
		size = s;
		max_size = size + grow;
		ptr = new T[max_size];
	}
	else 
	{
		T* temp = nullptr;
		if (size > s)
		{
			max_size = s + grow;
			temp = new T[max_size];
			/*for (int i = 0; i < s; i++)
			{
				temp[i] = ptr[i];
			}*/
			temp = ptr;
			delete[]ptr;
			size = s;
			ptr = new T[max_size];
			ptr = temp;
			temp = nullptr;
		}
		else if (size < s)
		{
			max_size = s + grow;
			temp = new T[max_size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = ptr[i];
			}
			cout << "Init new elements: " << endl;
			for (int i = size; i < s; i++)
			{
				cin >> temp[i];
			}
			delete[]ptr;
			size = s;
			ptr = new T[max_size];
			ptr = temp;
			temp = nullptr;
		}
		else
		{
			max_size = s + grow;
			temp = new T[max_size];
			for (int i = 0; i < s; i++)
			{
				temp[i] = ptr[i];
			}
			delete[]ptr;
			size = s;
			ptr = new T[max_size];
			ptr = temp;
			temp = nullptr;
		}
	}
}

template<class T>
inline bool _array<T>::IsEmpty()
{
	if (size == 0)
		return true;
	else return false;
}

template<class T>
inline int _array<T>::GetUpperBound()
{
	return size - 1;
}

template<class T>
inline T _array<T>::GetAt(int index)
{
	if (!IsEmpty && index > 0)
		return ptr[index];
	else return ptr[0];
}

template<class T>
inline void _array<T>::SetAt(int index, T value)
{
	ptr[index] = value;
}

template<class T>
inline void _array<T>::SetAt(int index, const T* value)
{
	ptr[index] = value;
}

template<class T>
inline void _array<T>::FreeExtra()
{
	if (grow != 0)
	{
		grow = 0;
		T* temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = ptr[i];
		}
		delete[]ptr;
		ptr = new T[size];
		ptr = temp;
		temp = nullptr;
	}
}

template<class T>
inline void _array<T>::RemoveAll()
{
	size = 0;
	grow = 0;
	max_size = 0;
	delete[]ptr;
}

template<class T>
inline T& _array<T>::operator[](int index)
{
	return ptr[index];
}

template<class T>
inline void _array<T>::Add()
{
	if (size != max_size)
	{
		cin >> ptr[size];
		size++;
	}
	else
	{
		cout << "Extra memory has run out!" << endl;
	}
}

template<class T>
inline T* _array<T>::GetData()
{
	return ptr;
}

template<class T>
inline void _array<T>::Append(const T** arr, int _size)
{
	int temp_size = max_size + _size;
	T* temp = new T[temp_size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = ptr[i];
	}
	for (int i = size, j = 0; j < _size + size, i < _size + size; j++, i++)
	{
		temp[i] = arr[j];
	}
	if (grow != 0)
	{
		for (int i = size+_size,j=size;j<temp_size, i < temp_size;j++, i++)
		{
			temp[i] = ptr[j];
		}
	}
	delete[]ptr;
	ptr = new T[temp_size];
	ptr = temp;
	temp = nullptr;
	size = size + _size;
	max_size = temp_size;
}

template<class T>
inline void _array<T>::Append( T arr[], int _size)
{
	int temp_size = max_size + _size;
	T* temp = new T[temp_size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = ptr[i];
	}
	for (int i = size,j=0;j<_size+size, i < _size + size;j++, i++)
	{
		temp[i] = arr[j];
	}
	if (grow != 0)
	{
		for (int i = size + _size, j = size; j < temp_size, i < temp_size; j++, i++)
		{
			temp[i] = ptr[j];
		}
	}
	delete[]ptr;
	ptr = new T[temp_size];
	ptr = temp;
	temp = nullptr;
	size = size + _size;
	max_size = temp_size;
}

template<class T>
inline void _array<T>::InsertAt(T value, int pos)
{
	size++;
	if (size != max_size)
	{
		cout << "Insert new element in position:" << pos << endl;
	
		T temp=ptr[pos];
		for (int i = size-1; i >= pos; i--)
		{
			temp = ptr[i];
			ptr[i] = ptr[i+1];
			ptr[i+1] = temp;
		}
		ptr[pos] = value;
	}
	else
	{
		size--;
		cout << "Array is full" << endl;
	}
}

template<class T>
inline void _array<T>::RemoveAt(int pos)
{
	if (size != 0)
	{
		for (int i = pos-1; i < size;i++)
		{
			ptr[i] = ptr[i + 1];
		}
		size--;
	}
	else
		cout << "Array is empty!" << endl;
}

template<class T>
inline ostream& operator<<(ostream& out, _array<T>& arr)
{
	if (!arr.IsEmpty())
	{
		out << "Size: " << arr.size << endl;
		out << "Array: " << endl;
		for (int i = 0; i < arr.size; i++)
		{
			out <<arr.ptr[i] << " ";
		}
		return out;
	}
	else
	{
		cout << "Array is empty!";
		return out;
	}
}
