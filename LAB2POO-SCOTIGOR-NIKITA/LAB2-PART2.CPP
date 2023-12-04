#include <iostream>
#include <cstring>

class Matrix
{
private:
    float *data;   // Pointer spre float pentru alocarea dinamică a matricei
    int rows;      // Numărul de rânduri
    int cols;      // Numărul de coloane
    int errorCode; // Codul erorii

public:
    // Constructorul implicit
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    // Constructorul cu un parametru pentru matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0)
    {
        allocateMemory();
        initializeMatrix();
    }

    // Constructorul cu doi parametri pentru matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0)
    {
        allocateMemory();
        initializeMatrix();
    }

    // Destructor
    ~Matrix()
    {
        delete[] data;
    }

    // Funcția de returnare a valorii unui element (i, j)
    float getElement(int i, int j) const
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            return data[i * cols + j];
        }
        else
        {
            setError(1); // Codul erorii pentru accesarea unui element în afara limitelor matricei
            return 0.0;
        }
    }

    // Funcția de setare a valorii unui element (i, j)
    void setElement(int i, int j, float value)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            data[i * cols + j] = value;
        }
        else
        {
            setError(1); // Codul erorii pentru accesarea unui element în afara limitelor matricei
        }
    }

    // Funcția de adunare a două matrice
    Matrix add(const Matrix &other) const
    {
        if (rows == other.rows && cols == other.cols)
        {
            Matrix result(rows, cols);
            for (int i = 0; i < rows * cols; ++i)
            {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }
        else
        {
            setError(2);     // Codul erorii pentru dimensiuni neconforme la adunare
            return Matrix(); // Returnează o matrice goală
        }
    }

    // Funcția de scădere a două matrice
    Matrix subtract(const Matrix &other) const
    {
        if (rows == other.rows && cols == other.cols)
        {
            Matrix result(rows, cols);
            for (int i = 0; i < rows * cols; ++i)
            {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }
        else
        {
            setError(2);     // Codul erorii pentru dimensiuni neconforme la scădere
            return Matrix(); // Returnează o matrice goală
        }
    }

    // Funcția de înmulțire a două matrice
    Matrix multiply(const Matrix &other) const
    {
        if (cols == other.rows)
        {
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < other.cols; ++j)
                {
                    result.data[i * result.cols + j] = 0.0;
                    for (int k = 0; k < cols; ++k)
                    {
                        result.data[i * result.cols + j] += data[i * cols + k] * other.data[k * other.cols + j];
                    }
                }
            }
            return result;
        }
        else
        {
            setError(3);     // Codul erorii pentru dimensiuni neconforme la înmulțire
            return Matrix(); // Returnează o matrice goală
        }
    }

    // Funcția de înmulțire a matricei cu un număr
    Matrix multiply(float scalar) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i)
        {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // Funcția de afișare a matricei
    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Funcție pentru returnarea codului erorii
    int getErrorCode() const
    {
        return errorCode;
    }

private:
    // Funcția de alocare a memoriei pentru matrice
    void allocateMemory()
    {
        data = new float[rows * cols];
    }

    // Funcția de inițializare a matricei cu valori implicite
    void initializeMatrix()
    {
        for (int i = 0; i < rows * cols; ++i)
        {
            data[i] = 0.0;
        }
    }

    // Funcție pentru setarea codului erorii
    void setError(int code)
    {
        errorCode = code;
    }
};

int main()
{
    // Exemplu de utilizare a clasei Matrix
    Matrix squareMatrix(3); // Matrice pătrată 3x3
    squareMatrix.setElement(0, 0, 1.0);
    squareMatrix.setElement(1, 1, 1.0);
    squareMatrix.setElement(2, 2, 1.0);
    std::cout << "Matricea pătrată:\n";
    squareMatrix.display();

    Matrix rectMatrix(3, 2); // Matrice dreptunghiulară 3x2
    rectMatrix.setElement(0, 0, 1.0);
    rectMatrix.setElement(1, 1, 1.0);
    rectMatrix.setElement(2, 0, 2.0);
    std::cout << "\nMatricea dreptunghiulară:\n";
    rectMatrix.display();

    Matrix resultAdd = squareMatrix.add(rectMatrix);
    std::cout << "\nMatricea rezultată în urma adunării:\n";
    resultAdd.display();

    Matrix resultMultiply = squareMatrix.multiply(rectMatrix);
    std::cout << "\nMatricea rezultată în urma înmulțirii:\n";
    resultMultiply.display();

    Matrix scaledMatrix = rectMatrix.multiply(2.0);
    std::cout << "\nMatricea rezultată în urma înmulțirii cu scalarul 2.0:\n";
    scaledMatrix.display();

    return 0;
}
