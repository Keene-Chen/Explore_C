#include <iostream>

using namespace std;

class Book
{
public:
	int title;
	char name[20];
	float price;
};

int main(void)
{
	Book a;
	a.title = 1;
	a.price = 1.0;

	std::cout << "asdasd:" << a.title << std::endl;
}