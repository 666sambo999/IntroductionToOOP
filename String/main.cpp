#include <iostream>

using namespace std;

class String
{
	int size;		// размер строки в байтах 	
	char* str;		// Адрес строки в динамической памяти 
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
		this->size = strlen(str)+1; // определяем размер строки 
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl; 
	}
	String(const String& other)
	{
		// Deep copy (побитоое копирование)
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		// Shallow copy (поверхностное копирование)
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl; 
	}
	
	// Operators
	String& operator=(const String& other) // Deep copy 
	{
		// Проверяем,не является ли принятый параметр нашим объектом 
		if (this == &other)return *this; 
		//1)удаляем старую строку 
		delete[]this->str; 
		//2) Выполняем побитовую операцию копирования 
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this; 
	}
	String& operator =(String&& other)
	{
		if (this == &other)return *this; 
		delete[]this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl; 
	}
	const char& operator [](char i)const
	{
		return str[i];
	}
	char& operator [](char i)
	{
		return str[i];
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
	for (int i = 0; i < left.get_size(); i++)// первая строка
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++) // вторая строка
		cat[i+left.get_size()-1] = right[i];
		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
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

	//String str2 = 16; // Конструктор с одним параметром Single-argumen 
	String str2(16);
	str2.print(); // explicit конструктор невозможно вызвать оператором присвоить
	// его можно выхвать только так

	String str3 = "Hello";
	str3 = str3; 
	str3.print();

	//String str4 = str3; //Copy constructor
	String str4; //Copy constructor
	str4 = str3; // оператор присваивания 
	
	str4.print();// ошибка Debug когда удаляеться два раза одна и таже память

#endif // CONSTRUCTOR_CHECK
	
#ifdef HOME_WORK
	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << str1 << endl; 
	//String str3 = str1 + " "+ str2; // Move contructor
	//String str3;
	//str3 = str1 + str2; // move assignment 
	//cout << str1 << "+" << str2 << "=" << str3 << endl;
#endif // HOME_WORK




}