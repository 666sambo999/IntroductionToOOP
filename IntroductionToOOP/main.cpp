#include <iostream>

using namespace std;
using std::cout; 
 

//#define DISTANCE_CHECK

class Point // создаем структуру или класс новый 
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this ->x = x;
	}
	void set_y(double y)
	{
		this ->y = y;
	}
	//   Constructor 
	//Point()			 // может быть вызван без параметоров 
	//{
	//	x = y = 0;
	//	cout << "Constructor:\t" << this << endl; 
	//}
	//Point(double x)			// есть параметр, не может быть вызван 
	//{
	//	this -> x = x; 
	//	y = 0; 
	//	cout << "1ArgConstructor:\t" << this << endl; 
	//}
	Point(double x = 0, double y = 0) //  также может быть вызван без параметров  
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl; 
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl; 
	}

	// Метод (Methods)
	double distance(Point other)
	{
		// this - это точка от которой мы считаем расстояние
		// other - это вторая точка, (указанная точка)
		double x_distance = this->x - other.x; 
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance; // возвращаем значение 
	}
	void print()
	{
	cout << "X = " << x << "\tY = " << y << endl; 
	}
};


double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance; 
}

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	// Members - члены 
	int a; // объявление переменной "а" типа int 
	Point A; // объявление переменной "А" типа Point 
	// объявление объекта А типа Point 
	// создание экземпляра А структуры 
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y () << endl;
	A.print();

	Point B;
	B.set_x(7);
	B.set_y(8);
	//cout << B.get_x() << "\t" << B.get_y() << endl; 
	B.print();


	cout << "Расстояние от точки А до точки Б:" << A.distance(B) << endl; // вызываем от точки А до точки Б, или наоборот 
	cout << "Расстояние от точки Б до точки А:" << B.distance(A) << endl; // вызываем от точки А до точки Б, или наоборот 
	cout << "Расстояние от точки А до точки Б:" << distance(A, B) << endl; // вызываем от точки А до точки Б, или наоборот 
	cout << "Расстояние от точки Б до точки А:" << distance(B, A) << endl; // вызываем от точки А до точки Б, или наоборот   
#endif // DISTANCE_CHECK

	Point A;		// Default conctructor, чтобы создать объект нужен конструктор  
	A.print();

	Point B = 5;
	B.print();

	Point C(2,3);
	C.print(); 
}
