#include <iostream>
#define PI 3.14
#define SPHERE_COEF (4.0/3)

inline float volume(float radius, float height) {return PI*radius*radius*height;} // cylinder
inline float volume(float length, float breadth, float height) {return length*breadth*height;}; // cuboid
inline float volume(float radius) {return SPHERE_COEF*PI*radius*radius*radius;}; // sphere

int main() {
    float radius, height, length, breadth;

    std::cout << "Enter radius and height of cylinder: ";
    std::cin >> radius >> height;
    std::cout << "Cylinder Volume: " << volume(radius, height) << "\n";

    std::cout << "Enter length, breadth and height of cuboid: ";
    std::cin >> length >> breadth >> height;
    std::cout << "Cuboid Volume: " << volume(length, breadth, height) << "\n";

    std::cout << "Enter radius of sphere: ";
    std::cin >> radius;
    std::cout << "Sphere Volume: " << volume(radius) << "\n";
}