#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Computer
{
    char* firmaProducatoare;
    char* procesor;
    float frecventaTact;

    // Constructor pentru initializare
    Computer(const char* firma, const char* proc, float frecventa)
    {
        firmaProducatoare = new char[strlen(firma) + 1];
        strcpy(firmaProducatoare, firma);

        procesor = new char[strlen(proc) + 1];
        strcpy(procesor, proc);

        frecventaTact = frecventa;
    }

    // Destructor pentru eliberarea memoriei
    ~Computer()
    {
        delete[] firmaProducatoare;
        delete[] procesor;
    }

    // Functie pentru afisarea informatiilor despre computer
    void afisareInformatii()
    {
        cout << "Firma producatoare: " << firmaProducatoare << endl;
        cout << "Procesor: " << procesor << endl;
        cout << "Frecventa de tact: " << frecventaTact << " GHz" << endl;
    }

    // Functie pentru comparare (pentru sortare)
    bool operator<(const Computer& other) const
    {
        return frecventaTact < other.frecventaTact;
    }
};

int main()
{
    const int numarCalculatoare = 4;
    Computer* calculatoare[numarCalculatoare];

    for (int i = 0; i < numarCalculatoare; i++) {
        char firma[50];
        char proc[50];
        float frecventa;

        cout << "Firma producatoare pentru calculatorul " << i + 1 << ": ";
        cin >> firma;

        cout << "Procesor pentru calculatorul " << i + 1 << ": ";
        cin >> proc;

        cout << "Frecventa de tact pentru calculatorul " << i + 1 << " (GHz): ";
        cin >> frecventa;

        calculatoare[i] = new Computer(firma, proc, frecventa);
    }

    // Sorteaza calculatoarele dupa frecventa de tact
    sort(calculatoare, calculatoare + numarCalculatoare, [](Computer* a, Computer* b) {
        return *a < *b;
    });

    // Afiseaza calculatoarele sortate
    for (int i = 0; i < numarCalculatoare; i++) {
        cout << "Calculator " << i + 1 << ":" << endl;
        calculatoare[i]->afisareInformatii();
        cout << endl;
    }

    // Elibereaza memoria alocata
    for (int i = 0; i < numarCalculatoare; i++) {
        delete calculatoare[i];
    }

    return 0;
}