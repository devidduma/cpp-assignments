#include <iostream>
#include <cstring>
using namespace std;

struct car
{
    int carId;
    char maker[16];
    int year;
    string motor;
    int mileage;
    double price;
};

void sortByPrice(car c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (c[i].price < c[j].price)
            {
                car temporary = c[i];
                c[i] = c[j];
                c[j] = temporary;
            }
        }
    }
}

void getData(car c[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].carId;
        std::cin.getline(c[i].maker, 16, ';');
        cin >> c[i].year;
        cin >> c[i].motor;
        cin >> c[i].mileage;
        cin >> c[i].price;
    }
}

void showData(car c[], int n, int type)
{
    if (type == 1)
        for (int i = 0; i < n; i++)
        {
            cout << c[i].price << " ";
            cout << c[i].year << endl;
        }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << c[i].price << " ";
            cout << c[i].mileage << " ";
            cout << c[i].year << endl;
        }
    }
}

void type1(car c[], int n, int m, int Year, double Price, string carMaker)
{
    car c1[n];
    int counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (Year < c[i].year || Price < c[i].price || carMaker != c[i].maker)
            continue;
        c1[counter++] = c[i];
    }
    sortByPrice(c1, counter);
    
    for (int i = 0; i < counter; i++)
    {
        for (int j = i; j < counter; j++)
        {
            if (c1[i].price == c1[j].price && c1[i].year < c1[j].year)
            {
                car temporary = c1[i];
                c1[i] = c1[j];
                c1[j] = temporary;
            }
        }
    }
    showData(c1, min(counter, m), 1);
}
void type2(car c[], int n, int m, int Year, double Price, int Mileage)
{
    car c1[n];
    int counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (Year < c[i].year || Price < c[i].price || Mileage < c[i].mileage)
            continue;
        c1[counter++] = c[i];
    }
    sortByPrice(c1, counter);
    
    for (int i = 0; i < counter; i++)
    {
        for (int j = i; j < counter; j++)
        {
            if (c1[i].price == c1[j].price && c1[i].mileage > c1[j].mileage)
            {
                car temporary = c1[i];
                c1[i] = c1[j];
                c1[j] = temporary;
            }
        }
    }
    
    for (int i = 0; i < counter; i++)
    {
        for (int j = i; j < counter; j++)
        {
            if (c1[i].price == c1[j].price && c1[i].mileage == c1[j].mileage && c1[i].year > c1[j].year)
            {
                car temporary = c1[i];
                c1[i] = c1[j];
                c1[j] = temporary;
            }
        }
    }
    showData(c1, min(counter, m), 2);
}

int main()
{
    int n;
    car c[20000];
    getData(c, n);
    int type, m;
    cin >> type >> m;
    char carMaker[16];
    int Year, Mileage;
    double Price;
    
    if (type == 1)
    {
        std::cin.getline(carMaker, 16, ';');
        cin >> Year >> Price;
        type1(c, n, m, Year, Price, carMaker);
    }
    
    if (type == 2)
    {
        cin >> Year >> Mileage >> Price;
        type2(c, n, m, Year, Price, Mileage);
    }
    
    return 0;
}
