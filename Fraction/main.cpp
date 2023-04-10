#include <iostream>

using namespace std;
using std::cout;

class Fraction; // объявление функции 
Fraction operator*(Fraction left, Fraction right); 
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);


class Fraction
{
	int integer;		// целое число 
	int numerator;		// числитель 
	int denominator;	// знаменатель 
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
			// конструктор 
	Fraction()		
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl; 
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numenator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << endl; 
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
			// Operator
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl; 
		return *this; 
	}
	
	// Increment/Decrement 
	Fraction& operator++ ()		// инкремент добавляет только к целым частям, к дробной нет, увеличивает на 1
	{
		integer++; 
		return *this; // возвращаем измененный объект 
	}
	Fraction& operator++ (int) // Посфиксный инкпумент 
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator-- (int) // Декремент  
	{
		Fraction old = *this;
		integer--;
		return old;
	}

			// Meтоды 
	Fraction& to_improper() 
	{
		numerator += integer * denominator;
		integer = 0; 
		return *this; 
	}
	Fraction& to_proper()
	{
		integer += numerator /denominator;
		numerator %= denominator;
		/*if (numerator > 0) numerator;
		else if (numerator < 0)numerator = -numerator;*/
		return *this;
	}
	// метод инвертор обращает дробь
	Fraction inverted()const
	{
		Fraction inverted = *this; 
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce() // неконстантный метод, тк изменяет значения 
	{
		to_proper(); 
		int more, less, rest; 
		if (numerator > denominator) more = numerator,less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest); 
		int GCD = more; // GCD - Greatest Common Divisor; 
		numerator /= GCD;
		denominator /= GCD; 
		return *this; 
	}
	void print()
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl; 
	}
	Fraction& operator *=(const Fraction& other) // перегруженный оператор - функция: и прежде чем использовать ее нужно объявить 
	{
		return *this = *this * other; 
	}
	Fraction& operator /=(const Fraction& other)  
	{
		return *this = *this / other;
	}
	Fraction& operator +=(const Fraction& other)  
	{
		return *this = *this + other;
	}
	Fraction& operator -=(const Fraction& other)
	{
		return *this = *this - other;
	}

};
Fraction operator*(Fraction left, Fraction right) // по const ссылке потому что не должен изменять значения, и не создавались новые объекты в классе
{												//  константный метод только для константного объекта, передать по значению,
	left.to_improper();
	right.to_improper();
	/*product.set_numenator(left.get_nunenator() * right.get_nunenator());
	product.set_denominator(left.get_denominator () * right.get_denominator());*/
	/*Fraction product
	(
		left.get_nunenator() * right.get_nunenator(),
		left.get_denominator() * right.get_denominator()
	);
	product.to_proper();
	return product;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper(). reduce();

}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_nunenator() * right.get_denominator(),
		left.get_denominator() * right.get_nunenator()
	);*/
	return left * right.inverted();

}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper (). reduce ();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
	/*if (left.get_nunenator() * right.get_denominator() == right.get_nunenator() * left.get_denominator())
		return true;
	else
		return false;*/

}
bool operator != (Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator >= (Fraction left, Fraction right) // 
{
	return !(left < right);
	//return left > right || left == right; 
}
bool operator <= (Fraction left, Fraction right)
{
	return !(left > right);
	//return left < right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os; 
}

//#define CONSRUCTOR_CHECK
//# define ARIFMETIKA
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSRUCTOR_CHECK
	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	A = E;
	A.print();
#endif // CONSRUCTOR_CHECK

#ifdef ARIFMETIKA
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	A.print();
	B.print();

	Fraction E = A + B;
	E.print();

	Fraction G = A-B;
	G.print();*/

	/*A *= B;
	A.print();

	A /= B;
	A.print();

	A += B;
	A.print();

	A -= B;
	A.print();*/

	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}

	for (Fraction i(9, 3, 4); i.get_integer() > 0; i--)
	{
		i.print();
	}
#endif // ARIFMETIKA

	/*cout << (Fraction(1, 2) == Fraction(5, 11)) << endl; 
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl; 
	cout << (Fraction(1, 2) > Fraction(5, 10)) << endl; 
	cout << (Fraction(1, 2) < Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;*/

	Fraction A(2,4,5); 
	cout << A << endl; 




}
