#include"Header.h"
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	Point& operator=(int a)
	{
		x = a;
		y = a;
		return *this;
	}
	Point& operator+(int a)
	{
		Point rez(*this);
		rez.x += a;
		rez.y += a;
		return rez;
	}
};
int main()
{
	/*MyArray<int> arrInt(5);
	arrInt.Random();
	arrInt.Print();*/

	MyArray<Point> Myobj(3);
	Myobj.Random();
	//Myobj.Print(); //  <<

	MyArray<Point> rez = Myobj + 5;//  метод 
	MyArray<Point> rez2 = 5 + Myobj; // функция

	if (rez > rez2)
	{
		cout << "rez>rez2\n";
	}

}