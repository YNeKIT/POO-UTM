#include <iostream>

class Garaj
{
private:
    double suprafata;

public:
    // Constructorul implicit
    Garaj() : suprafata(0) {}

    // Constructorul cu parametri
    Garaj(double _suprafata) : suprafata(_suprafata) {}

    // Metode de acces
    double getSuprafata() const
    {
        return suprafata;
    }
};

class Casa
{
private:
    int numarOdai;
    double suprafataBucatarie;
    Garaj garaj;

public:
    // Constructorul implicit
    Casa() : numarOdai(0), suprafataBucatarie(0) {}

    // Constructorul cu parametri
    Casa(int _numarOdai, double _suprafataBucatarie, const Garaj &_garaj)
        : numarOdai(_numarOdai), suprafataBucatarie(_suprafataBucatarie), garaj(_garaj) {}

    // Metode de acces
    int getNumarOdai() const
    {
        return numarOdai;
    }

    double getSuprafataBucatarie() const
    {
        return suprafataBucatarie;
    }

    const Garaj &getGaraj() const
    {
        return garaj;
    }
};

class Vila : public Casa
{
private:
    double marimeLot;

public:
    // Constructorul cu parametri
    Vila(int _numarOdai, double _suprafataBucatarie, const Garaj &_garaj, double _marimeLot)
        : Casa(_numarOdai, _suprafataBucatarie, _garaj), marimeLot(_marimeLot) {}

    // Destructorul - nu este necesar să redefinești destructorul, deoarece Vila folosește destructorul Casei

    // Fluxul de ieșire
    friend std::ostream &operator<<(std::ostream &os, const Vila &vila)
    {
        os << "Numar odai: " << vila.getNumarOdai()
           << "\nSuprafata bucatarie: " << vila.getSuprafataBucatarie()
           << "\nSuprafata garaj: " << vila.getGaraj().getSuprafata()
           << "\nMarime lot: " << vila.marimeLot << std::endl;
        return os;
    }
};

int main()
{
    // Exemplu de utilizare a claselor definite
    Garaj garaj1(25.0);
    Casa casa1(4, 40.0, garaj1);
    Vila vila1(6, 60.0, garaj1, 500.0);

    // Afișarea informațiilor despre vila
    std::cout << "Informatii despre Vila:\n";
    std::cout << vila1;

    return 0;
}
