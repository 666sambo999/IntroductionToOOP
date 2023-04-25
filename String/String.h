#pragma once
#include <iostream>

using namespace std;
#define delimeter "\n--------------------------------------------"

////////////////////////////////////////////////////////////
////////////// class declaration (объ€вление класса)//////


class String;
String operator +(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator >>(std::istream& is, String& obj);
class String
{
	int size;		// размер строки в байтах 	
	char* str;		// јдрес строки в динамической пам€ти 
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// данную операцию можно делать в конструкторах
	explicit String(int size = 256);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	// Operators
	String& operator=(const String& other);
	String& operator =(String&& other);
	String& operator +=(const String& other);
	const char& operator [](char i)const;
	char& operator [](char i);
	// Metods 
	void print()const;
};
////////// class declaration end (конец объ€вление класса) /////////
/////////////////////////////////////////////////////////////////
