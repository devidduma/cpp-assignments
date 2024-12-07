#include <iostream>
#include <fstream>
using namespace std;

int max_size = 20;

ifstream fin("films.txt");

enum Genres
{
    ACTION = 1,
    COMEDY = 2,
    HORROR = 3,
    SCFI = 4,
    THRILLING = 5
};

struct Film
{
    char name[30];
    Genres Genre;
    char Year[5];
    int stars;
    float cost;
};

int findNum(Film film[], Genres g)
{
    int cnt = 0;
    for (int i = 0; i < 20; i++)
    {
        if (film[i].Genre == g)
            cnt++;
    }
    return cnt;
}

void print(Film film[], Genres g)
{
    for (int i = 0; i < 20; i++)
    {
        if (film[i].Genre == g)
            cout << film[i].name << endl;
    }
}

int main()
{
    Film film[20];
    max_size = 19;

    for (int i = 0; i < 10; i++)
    {
        fin.getline(film[i].name, 30, ';');
        int num;
        fin >> num;
        film[i].Genre = Genres(num);
        fin >> film[i].Year;
        fin >> film[i].stars;
        fin >> film[i].cost;
    }
    
    cout << findNum(film, COMEDY);
    print(film, ACTION);
    return 0;
}
