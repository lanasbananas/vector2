#include <iostream>
#include <stdio.h>
#include <complex>

using namespace std;

template <class T> 
class vector
{
	size_t _size;
	T* _data;

public:

	vector() : _data(nullptr), _size(0) {};

	vector(size_t size, T data)
	{
		_size = size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = data;
		};
	};

	vector(const vector<T>& v)
	{
		_size = v._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = v._data[i];
		};
	};

	~vector()
	{
		delete[] _data;
	};

	T& operator[](size_t ind)
	{
		if (ind >= _size)
			throw std::logic_error("Invalid index");
		return _data[ind];
	};

	vector& operator= (const vector& v)
	{
		if (this == &v)
			return (*this);
		delete[]_data;
		_size = v._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = v._data[i];
		};
		return (*this);
	};

	vector operator+ (const vector<T>& v1) const
	{
		if (_size != v1._size)
			throw("Can not sum2 vector!");
		vector sum;
		sum._size = _size;
		sum._data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			sum._data[i] = _data[i] + v1._data[i];
		};
		return sum;
	};

	vector operator- (const vector& v1) const
	{
		if (_size != v1._size)
			throw "Can not dif2 vector!";
		vector dif;
		dif._size = _size;
		dif._data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			dif._data[i] = _data[i] - v1._data[i];
		};
		return dif;
	};

	T operator*(const vector& v1) const
	{
		if (_size != v1._size)
			throw "Can not mul2 vector!";
		T mul = 0;
		for (size_t i = 0; i < _size; i++)
		{
			mul += _data[i] * v1._data[i];
		};
		return mul;
	};

	vector operator*(const T a) const
	{
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res._data[i] = _data[i] * a;
		};
		return res;
	};

	vector operator/(const T data) const
	{
		if (data == 0)
			throw("Error!");
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res._data[i] = _data[i] / data;
		};
		return res;
	};

	friend istream& operator>> (istream& is, vector<T>& v)
	{
		cout << "Size: ";
		is >> v._size;
		v._data = new T[v._size];
		for (size_t i = 0; i < v._size; i++)
			is >> v._data[i];
		return is;
	};

	friend ostream& operator<< (ostream& os, const vector<T>& v)
	{
		os << "[ ";
		for (size_t i = 0; i < v._size; i++)
			os << v._data[i] << " ";
		os << "]" << endl;
		return os;
	};
};
 
int main()
{
	vector<int> a(5, 1);
	vector<int> b(5, 6);
	
	cout << "a = " << a;
	cout << "b = " << b;
	
	cout << "a + b = " << a + b;
	cout << "a - b = " << a - b;
	cout << "a * b = " << a * b;

	return 0;
}
