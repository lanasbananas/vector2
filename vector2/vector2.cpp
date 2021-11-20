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
			res[i] = _data[i] * a;
		};
		return res;
	};

	friend vector<T> operator*(const T a, const vector<T>& v) 
	{
		vector<T> res(v._size, 0);
		for (size_t i = 0; i < v._size; i++)
			res[i] = v._data[i] * a;
		return res;
	};

	vector operator/(const T a) const
	{
		T h = 0;
		if (a == h)
			throw("Error!");
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res[i] = _data[i] / a;
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

	template <typename T> T scalar_product(const vector <T>& v1)
	{
		T res = 0;
		if (_size != v1._size)
			throw "Error!";
		for (size_t i = 0; i < v1._size; i++)
		{
			res += _data[i] * v1._data[i];
		};
		return res;
	};

	template <> complex<double> scalar_product(const vector <complex<double>>& v1)
	{
		complex <double> res = 0;
		if (_size != v1._size)
			throw "Error!";
		for (size_t i = 0; i < v1._size; i++)
		{
			res += _data[i] * conj(v1._data[i]);
		}
		return res;
	};

	template <> complex<float> scalar_product(const vector <complex<float>>& v1)
	{
		complex <float> res = 0;
		if (_size != v1._size)
			throw "Error!";
		for (size_t i = 0; i < v1._size; i++)
		{
			res += _data[i] * conj(v1._data[i]);
		}
		return res;
	};
};
 
int main()
{
	vector<double> a(2, 1);
	vector<double> b(2, 5);
	
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "a + b = " << a + b;
	cout << "a - b = " << a - b;
	cout << "a * b = " << a * b << endl;
	cout << "a * 5 = " << a * 5;
	cout << "5 * a = " << 5 * a;
	cout << "b / 5 = " << b / 5 << endl;

	vector<complex<double>> c(2, 3);
	vector<complex<double>> d(2, -7);

	cout << "c = " << c;
	cout << "d = " << d;
	cout << "c + d = " << c + d;
	cout << "c - d = " << c - d;
	cout << "c * d = " << c.scalar_product(d) << endl;
	cout << "c * 5 = " << c * complex<double>(5, 0);
	cout << "5 * c = " << complex<double>(5, 0) * c;
	cout << "d / 5 = " << d / complex<double>(5, 0) << endl;
	
	vector <complex<float>> e(2, 0), f(2, 0);

	e[0] = complex<float>(46, 1);
	e[1] = complex<float>(2, 28);
	f[0] = complex<float>(13, 37);
	f[1] = complex<float>(6, 9);

	cout << "e = " << e;
	cout << "f = " << f;
	cout << "e + f = " << e + f;
	cout << "e - f = " << e - f;
	cout << "e * f = " << e.scalar_product(f) << endl;
	cout << "e * 5 = " << e * complex<float>(5, 0);
	cout << "5 * e = " << complex<float>(5, 0) * e;
	cout << "f / 5 = " << f / complex<float>(5, 0) << endl;

	vector<double> g(2, 1);
	vector<double> h(2, -5.4);

	cout << "g = " << g;
	cout << "h = " << h;
	cout << "g + h = " << g + h;
	cout << "g - h = " << g - h;
	cout << "g * h = " << g * h << endl;
	cout << "g * 5 = " << g * 5;
	cout << "5 * g = " << 5 * g;
	cout << "h / 5 = " << h / 5 << endl;

	return 0;
}
