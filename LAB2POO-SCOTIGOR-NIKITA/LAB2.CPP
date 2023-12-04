#include <iostream>

class Stack
{
private:
    int size;      // numărul general de elemente
    int count;     // numărul utilizat de elemente
    int *elements; // pointer pentru alocarea dinamică a memoriei

public:
    // Constructori
    Stack();                   // Constructor implicit
    Stack(const Stack &other); // Constructor de copiere
    Stack(int requiredSize);   // Constructor cu parametru

    // Destructor
    ~Stack();

    // Funcții pentru manipularea stivei
    void Push(int element);
    void Pop();

    // Funcții pentru verificarea stării stivei
    bool IsEmpty() const;
    bool IsFull() const;

    // Funcție pentru afișare
    void Display() const;
};

// Implementare constructor implicit
Stack::Stack() : size(10), count(0), elements(new int[10]) {}

// Implementare constructor de copiere
Stack::Stack(const Stack &other) : size(other.size), count(other.count), elements(new int[other.size])
{
    for (int i = 0; i < count; ++i)
    {
        elements[i] = other.elements[i];
    }
}

// Implementare constructor cu parametru
Stack::Stack(int requiredSize) : size(requiredSize), count(0), elements(new int[requiredSize]) {}

// Implementare destructor
Stack::~Stack()
{
    delete[] elements;
}

// Implementare funcție Push
void Stack::Push(int element)
{
    if (!IsFull())
    {
        elements[count++] = element;
        std::cout << "Elementul " << element << " a fost adaugat pe stiva.\n";
    }
    else
    {
        std::cout << "Stiva este plina. Elementul " << element << " nu poate fi adaugat.\n";
    }
}

// Implementare funcție Pop
void Stack::Pop()
{
    if (!IsEmpty())
    {
        std::cout << "Elementul " << elements[--count] << " a fost scos de pe stiva.\n";
    }
    else
    {
        std::cout << "Stiva este vida. Nu exista elemente pentru a fi scoase.\n";
    }
}

// Implementare funcție IsEmpty
bool Stack::IsEmpty() const
{
    return count == 0;
}

// Implementare funcție IsFull
bool Stack::IsFull() const
{
    return count == size;
}

// Implementare funcție de afișare
void Stack::Display() const
{
    std::cout << "Stiva contine " << count << " elemente: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    // Exemplu de utilizare
    Stack myStack(5);

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Display();

    myStack.Pop();
    myStack.Display();

    myStack.Pop();
    myStack.Pop();

    return 0;
}
