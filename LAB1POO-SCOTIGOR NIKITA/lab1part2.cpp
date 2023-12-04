#include <iostream>

struct Vector {
    double* elements;
    int size;
    
    // Constructor pentru inițializarea vectorului
    Vector(int n) {
        size = n;
        elements = new double[size];
    }

    // Funcție pentru eliberarea vectorului
    void deleteVector() {
        delete[] elements;
    }

    // Funcție pentru modificarea dimensiunii vectorului
    void resize(int newSize) {
        delete[] elements;
        size = newSize;
        elements = new double[size];
    }

    // Funcție pentru accesarea elementelor vectorului
    double& operator[](int index) {
        return elements[index];
    }

    // Funcție pentru calcularea sumei elementelor pozitive
    double sumOfPositives() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            if (elements[i] > 0) {
                sum += elements[i];
            }
        }
        return sum;
    }
};

int main() {
    int n = 5;
    Vector myVector(n);

    // Inițializați vectorul
    for (int i = 0; i < n; i++) {
        myVector[i] = i + 1;
    }

    // Afișarea suma elementelor pozitive din vector
    double sum = myVector.sumOfPositives();
    std::cout << "Suma elementelor pozitive din vector: " << sum << std::endl;

 
    myVector.resize(7);

   
    std::cout << "Dimensiunea noului vector: " << myVector.size << std::endl;


    myVector.deleteVector();

    return 0;
}