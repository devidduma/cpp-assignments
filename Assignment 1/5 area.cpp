#include <iostream>
#include <cmath>
using namespace std;

struct Cube {
	int side;
};

struct Sphere {
	int radius;
};

struct Cone {
	int radius;
	int height;
};

double area(Cube cube) {
	return 6*cube.side*cube.side;
}

double area(Sphere sphere) {
	return 4.0/3.0*M_PI*pow(double(sphere.radius), 3.0);
}

double area(Cone cone) {
	double slant_height = sqrt(pow(double(cone.height), 2.0) + pow(double(cone.height), 2.0));
	return (slant_height + cone.radius)*M_PI*cone.radius;
}


int main() {
	Cube cube;
	cout<<"Enter side of cube as int: ";
	cin>>cube.side;
	cout<<"Area is: "<<area(cube)<<endl;

	Sphere sphere;
	cout<<"Enter radius of sphere as int: ";
	cin>>sphere.radius;
	cout<<"Area is: "<<area(sphere)<<endl;

	Cone cone;
	cout<<"Enter radius and height of cone as int: ";
	cin>>cone.radius>>cone.height;
	cout<<"Area is: "<<area(cone)<<endl;
}
