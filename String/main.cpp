#include <iostream>

using namespace std;

class String
{
	int size;		// размер строки в байтах 	
	char* str;		// јдрес строки в динамической пам€ти 
public: 
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	 char* get_str()
	{
		return str;
	}
	explicit String(int size=256)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default1ArgConstructor:\t" << this << endl; 
	}
	String(const char* str)
	{
		this->size = strlen(str)+1; // определ€ем размер строки 
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl; 
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t" << endl; 
	}
	/*std::ostream& operator<<(std::ostream& os, const String& obj)
	{
		return os;
	}*/

	// Operators
	String& operator=(const String& other)
	{
		// ѕровер€ем,не €вл€етс€ ли прин€тый параметр нашим объектом 
		if (this == &other)return *this; 
		//1)удал€ем старую строку 
		delete[]this->str; 
		//2) ¬ыполн€ем побитовую операцию копировани€ 
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << endl;
		return *this; 
	}

	// Metods 
	void print()const
	{
		cout << "Size\t" << size << endl; 
		cout << "Str\t" << str << endl; 
	}


};
String operator +(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
	return cat; 
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTOR_CHECK
#define HOME_WORK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str1;		// Default constructor
	str1.print();

	//String str2 = 16; //  онструктор с одним параметром Single-argumen 
	String str2(16);
	str2.print(); // explicit конструктор невозможно вызвать оператором присвоить
	// его можно выхвать только так

	String str3 = "Hello";
	str3 = str3; 
	str3.print();

	//String str4 = str3; //Copy constructor
	String str4; //Copy constructor
	str4 = str3; // оператор присваивани€ 
	
	str4.print();// ошибка Debug когда удал€етьс€ два раза одна и таже пам€ть

#endif // CONSTRUCTOR_CHECK
	
#ifdef HOME_WORK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str1 << "+" << str2 << "=" << str3 << endl;
#endif // HOME_WORK




}