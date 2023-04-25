#include <iostream>

using namespace std;
#define delimeter "\n--------------------------------------------"
class String;
String operator +(const String& left, const String& right);


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
	 // данную операцию можно делать в конструкторах
	explicit String(int size=256):size(size),str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Default1ArgConstructor:\t" << this << endl; 
	}
	String(const char* str):String(strlen(str)+1) // делегируем выделение памяти  констр по умолчанию
	{
		//this->size = strlen(str)+1; // определяем размер строки 
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl; 
	}
	String(const String& other):String(other.str)
	{
		// Deep copy (побитовое копирование)
		/*this->size = other.size;
		this->str = new char [size] {};*/
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other) :size(other.size), str(other.str)
	{
		// Shallow copy (поверхностное копирование)
		/*this->size = other.size;
		this->str = other.str;*/
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
	String& operator +=(const String& other)
	{
		return *this = *this + other;
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
	// os = Output stream
	return os << obj.get_str();
}
std::istream& operator >>(std::istream& is, String& obj)// не может быть константным так как изменяет значения 
{
	const int SIZE = 102400; 
	char buffer[SIZE]{};
	is >> buffer; 
	obj = buffer; 
	return is;	
	//return is >> obj.get_str();
}

//#define CONSTRUCTOR_CHECK
#define HOME_WORK
//#define IOSTREAM
//#define CLASS_RABOTA
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
	cout << delimeter << endl; 
	cout << str1 << endl; 
	cout << delimeter << endl; 

	String str3 = str1;
	str3.print();
	//String str3 = str1 + " "+ str2; // Move contructor
	//String str3;
	//str3 = str1 + str2; // move assignment 
	//cout << str1 << "+" << str2 << "=" << str3 << endl;
#endif // HOME_WORK

#ifdef IOSTREAM
			/*String str;
str.print();
cout << "Введите строку: "; cin >> str;
cout << str << endl;*/
	String last_name;
	String first_name;
	cout << "Введите Ваше имя: "; cin >> last_name >> first_name;
	cout << last_name << " " << first_name << endl;
#endif // IOSTREAM

#ifdef CLASS_RABOTA
	String str1; //Default construtor
	str1.print();
	String str2(8); //Single-argument construtor of type int
	str2.print();
	String str3 = "Hello"; //Single-argument construtor of type const char
	str3.print();
	String str4(); //Здесь не вызывается конструктор по умолчанию, в этой строке
	// объявляется ф-я str4, которая ничего не принимает, и возвращает 
	// значение типа String
	//str4 This is not an object 
	String str5{};
	str5.print();

	String str6{ 1234 };
	str6.print();

	String str7{ "Hello World" };
	str7.print();
#endif // CLASS_RABOTA


}