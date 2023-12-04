#include <iostream>
#include <cstring>

class Mobila
{
protected:
    double pret;
    char *stil;
    char *domeniuUtilizare;

public:
    // Constructorul implicit
    Mobila() : pret(0), stil(nullptr), domeniuUtilizare(nullptr) {}

    // Constructorul cu parametri
    Mobila(double _pret, const char *_stil, const char *_domeniuUtilizare)
        : pret(_pret)
    {
        stil = new char[strlen(_stil) + 1];
        strcpy(stil, _stil);

        domeniuUtilizare = new char[strlen(_domeniuUtilizare) + 1];
        strcpy(domeniuUtilizare, _domeniuUtilizare);
    }

    // Constructorul de copiere
    Mobila(const Mobila &other)
    {
        pret = other.pret;
        stil = new char[strlen(other.stil) + 1];
        strcpy(stil, other.stil);

        domeniuUtilizare = new char[strlen(other.domeniuUtilizare) + 1];
        strcpy(domeniuUtilizare, other.domeniuUtilizare);
    }

    // Operatorul de atribuire
    Mobila &operator=(const Mobila &other)
    {
        if (this != &other)
        {
            delete[] stil;
            delete[] domeniuUtilizare;

            pret = other.pret;
            stil = new char[strlen(other.stil) + 1];
            strcpy(stil, other.stil);

            domeniuUtilizare = new char[strlen(other.domeniuUtilizare) + 1];
            strcpy(domeniuUtilizare, other.domeniuUtilizare);
        }
        return *this;
    }

    // Destructorul
    ~Mobila()
    {
        delete[] stil;
        delete[] domeniuUtilizare;
    }

    // Alte funcții necesare
    void afisareInformatii() const
    {
        std::cout << "Pret: " << pret << "\nStil: " << stil << "\nDomeniu de utilizare: " << domeniuUtilizare << std::endl;
    }
};

class Masa : public Mobila
{
private:
    int numarPicioare;

public:
    // Constructorul implicit
    Masa() : numarPicioare(0) {}

    // Constructorul cu parametri
    Masa(double _pret, const char *_stil, const char *_domeniuUtilizare, int _numarPicioare)
        : Mobila(_pret, _stil, _domeniuUtilizare), numarPicioare(_numarPicioare) {}

    // Destructorul - nu este necesar să redefinești destructorul, deoarece Masa folosește destructorul Mobila

    // Operatorul de atribuire - nu este necesar să redefinești operatorul de atribuire, deoarece Masa folosește operatorul Mobila

    // Alte funcții necesare pentru clasa Masa
    void afisareInformatiiMasa() const
    {
        afisareInformatii();
        std::cout << "Numar picioare: " << numarPicioare << std::endl;
    }
};

class Scaun : public Mobila
{
private:
    bool cuRoti;

public:
    // Constructorul implicit
    Scaun() : cuRoti(false) {}

    // Constructorul cu parametri
    Scaun(double _pret, const char *_stil, const char *_domeniuUtilizare, bool _cuRoti)
        : Mobila(_pret, _stil, _domeniuUtilizare), cuRoti(_cuRoti) {}

    // Destructorul - nu este necesar să redefinești destructorul, deoarece Scaun folosește destructorul Mobila

    // Operatorul de atribuire - nu este necesar să redefinești operatorul de atribuire, deoarece Scaun folosește operatorul Mobila

    // Alte funcții necesare pentru clasa Scaun
    void afisareInformatiiScaun() const
    {
        afisareInformatii();
        std::cout << "Cu roti: " << (cuRoti ? "Da" : "Nu") << std::endl;
    }
};

int main()
{
    // Exemplu de utilizare a claselor definite
    Masa masa1(150.0, "Modern", "Bucatarie", 4);
    Scaun scaun1(50.0, "Clasic", "Birou", true);

    // Afisarea informatiilor despre masa si scaun
    std::cout << "Informatii despre Masa:\n";
    masa1.afisareInformatiiMasa();

    std::cout << "\nInformatii despre Scaun:\n";
    scaun1.afisareInformatiiScaun();

    return 0;
}
