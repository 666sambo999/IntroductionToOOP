#include <iostream>

using namespace std;
using std::cout;

class Fraction
{
	int integer;		// целое число 
	int numenator;		// числитель 
	int denominator;	// знаменатель 
public:
	int get_integer() const
	{
		return integer;
	}
	int get_nunenator()const
	{
		return numenator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numenator(int numenator)
	{
		this->numenator = numenator;
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
		this->numenator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl; 
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numenator,int denominator)
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numenator, int denominator)
	{
		this->integer = integer;
		this->numenator = numenator;
		this->denominator = denominator;
		cout << "Constructor:\t" << endl; 
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
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
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl; 
		return *this; 
	}
	
			// Meтоды 
	Fraction& to_improper() 
	{
		numenator += integer * denominator;
		integer = 0; 
		return *this; 
	}
	Fraction& to_proper()
	{
		integer += numenator /denominator;
		numenator %= denominator;
		return *this;
	}
	// метод инвертор обращает дробь
	Fraction inverted()const
	{
		Fraction inverted = *this; 
		inverted.to_improper();
		inverted.numenator ^= inverted.denominator; 
		inverted.denominator ^= inverted.numenator;
		inverted.numenator ^= inverted.denominator;
		return inverted;
	}

	void print()
	{
		if (integer)cout << integer;
		if (numenator)
		{
			if (integer)cout << "(";
			cout << numenator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl; 
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
		left.get_nunenator() * right.get_nunenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

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
		left.get_nunenator() * right.get_denominator() + right.get_nunenator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper ();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_nunenator() * right.get_denominator() - right.get_nunenator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

//#define CONSRUCTOR_CHECK
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

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	A.print();
	B.print();

	Fraction E = A + B;
	E.print(); 

	Fraction G = B-A;
	G.print();

}
