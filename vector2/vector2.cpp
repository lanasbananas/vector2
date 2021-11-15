#include <iostream>
#include <stdio.h>

using namespace std;

class vector
{
private:

	size_t _size;
	double* _data;

public:

	vector()
	{
		_size = 2;
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = 0;
		};
	};

	vector(size_t size, double data)
	{
		_size = size;
		if (_size < 0)
			throw("Can not negative size");
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = data;
		};
	};

	~vector()
	{
		delete[] _data;
	};

	double& operator[](size_t ind)
	{
		if (ind >= _size || ind < 0)
			throw std::logic_error("Invalid index");
		return _data[ind];
	};

	vector(vector&& move) noexcept
	{
		_data = move._data;
		_size = move._size;
		move._data = nullptr;
		move._size = 0;
	};

	vector& operator= (const vector& v)
	{
		if (this == &v)
			return (*this);
		delete[]_data;
		_size = v._size;
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = v._data[i];
		};
		return (*this);
	};

	vector operator+(const vector& v1)
	{
		if (_size != v1._size)
			throw("Can not sum2 vector!");
		vector sum;
		sum._size = _size;
		sum._data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			sum._data[i] = _data[i] + v1._data[i];
		};
		return sum;
	};

	vector operator-(const vector& v1)
	{
		if (_size != v1._size)
			throw "Can not dif2 vector!";
		vector dif;
		dif._size = _size;
		dif._data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			dif._data[i] = _data[i] - v1._data[i];
		};
		return dif;
	};

	double operator*(const vector& v1)
	{
		if (_size != v1._size)
			throw "Can not mul2 vector!";
		double mul = 0;
		for (size_t i = 0; i < _size; i++)
		{
			mul += _data[i] * v1._data[i];
		};
		return mul;
	};

	vector operator*(const double a)
	{
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res._data[i] = _data[i] * a;
		};
		return res;
	};

	vector operator/(const double data)
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

	friend istream& operator>> (istream& is, vector& v)
	{

		cout << "Size: ";
		is >> v._size;
		v._data = new double[v._size];
		for (size_t i = 0; i < v._size; i++)
			is >> v._data[i];
		return is;
	};

	friend ostream& operator<< (ostream& os, const vector& v)
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


}
