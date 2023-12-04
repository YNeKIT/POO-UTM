#include <iostream>

class Coord3D
{
private:
    double x, y, z;

public:
    // Constructor
    Coord3D(double xVal = 0.0, double yVal = 0.0, double zVal = 0.0) : x(xVal), y(yVal), z(zVal) {}

    // Metode pentru operatorii +, -, =
    Coord3D operator+(const Coord3D &other) const
    {
        return Coord3D(x + other.x, y + other.y, z + other.z);
    }

    Coord3D operator-(const Coord3D &other) const
    {
        return Coord3D(x - other.x, y - other.y, z - other.z);
    }

    Coord3D &operator=(const Coord3D &other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // Funcții prietene pentru operatorii de comparare
    friend bool operator==(const Coord3D &coord1, const Coord3D &coord2)
    {
        return (coord1.x == coord2.x && coord1.y == coord2.y && coord1.z == coord2.z);
    }

    friend bool operator!=(const Coord3D &coord1, const Coord3D &coord2)
    {
        return !(coord1 == coord2);
    }

    // Funcții pentru operații cu numere obișnuite
    Coord3D operator+(double scalar) const
    {
        return Coord3D(x + scalar, y + scalar, z + scalar);
    }

    Coord3D operator-(double scalar) const
    {
        return Coord3D(x - scalar, y - scalar, z - scalar);
    }

    Coord3D operator*(double scalar) const
    {
        return Coord3D(x * scalar, y * scalar, z * scalar);
    }

    // Funcție pentru afișarea coordonatelor
    void display() const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main()
{
    Coord3D coord1(1.0, 2.0, 3.0);
    Coord3D coord2(4.0, 5.0, 6.0);

    Coord3D sum = coord1 + coord2;
    Coord3D diff = coord1 - coord2;
    Coord3D assigned = coord1;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    std::cout << "Assigned: ";
    assigned.display();

    // Testare operatori de comparare
    if (coord1 == coord2)
    {
        std::cout << "Coord1 is equal to Coord2." << std::endl;
    }
    else
    {
        std::cout << "Coord1 is not equal to Coord2." << std::endl;
    }

    // Testare operații cu numere obișnuite
    Coord3D scaled = coord1 * 2.0;
    std::cout << "Scaled by 2.0: ";
    scaled.display();

    return 0;
}
