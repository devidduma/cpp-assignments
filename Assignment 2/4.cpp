#include <iostream>
#include <cstring>
using namespace std;

struct Books
{ //declaration of structure
	char title[50];
	char author[50];
	int ISBN;
	double price;
	char location[20];
};

Books expensive(Books books[], int n)
{ //function type book that return the most expensive book
	Books maxBooks = books[0];

	for (int i = 1; i < n; i++)
	{
		if (books[i].price > maxBooks.price)
		{ //check for highest price
			maxBooks.price = books[i].price;
			strcpy(maxBooks.author, books[i].author);
			maxBooks.ISBN = books[i].ISBN;
			maxBooks.price = books[i].price;
			strcpy(maxBooks.location, books[i].location);
		}
	}
	return maxBooks;
}

void getData(Books books[], int &n)
{
	cin >> n;					 //read size of array
	for (int i = 0; i < 50; i++) //reading info for 50 elements of Books type
		cin >> books[i].title >> books[i].author >> books[i].ISBN >> books[i].price >> books[i].location;
}

int main()
{
	//Books books[50];
	return 0;
}
