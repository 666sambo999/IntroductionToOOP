#include"String.h"
/////////////////////////////////////////////////////////////////
/////////// class definition ( определение класса) //////////////


// :: - оператор разрешения видимости 
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
// данную операцию можно делать в конструкторах
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "Default1ArgConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1) // делегируем выделение памяти  констр по умолчанию
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t\t" << this << endl;
}

// Operators
// это ф-я, состоит  type	name
String& String::operator=(const String& other) // Deep copy 
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
String& String::operator =(String&& other)
{
	if (this == &other)return *this;
	delete[]this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
}
String& String::operator +=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator [](char i)const
{
	return str[i];
}
char& String::operator [](char i)
{
	return str[i];
}
// Metods 
void String::print()const
{
	cout << "Size\t" << size << endl;
	cout << "Str\t" << str << endl;
}
String operator +(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)// первая строка
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++) // вторая строка
		cat[i + left.get_size() - 1] = right[i];
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

/////////// class definition end( конец определение класса) //////////////
//////////////////////////////////////////////////////////////////
