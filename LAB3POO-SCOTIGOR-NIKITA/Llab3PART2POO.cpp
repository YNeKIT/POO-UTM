#include <iostream>
#include <queue>

class Queue
{
private:
    std::queue<int> elements;

public:
    // Metoda pentru adaugarea unui element la coada
    void enqueue(int val)
    {
        elements.push(val);
    }

    // Metoda pentru eliminarea unui element din coada
    void dequeue()
    {
        if (!elements.empty())
        {
            elements.pop();
        }
        else
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        }
    }

    // Supraincarcarea operatorului +
    Queue operator+(const Queue &other) const
    {
        Queue result = *this;

        std::queue<int> otherElements = other.elements;
        while (!otherElements.empty())
        {
            result.enqueue(otherElements.front());
            otherElements.pop();
        }

        return result;
    }

    // Supraincarcarea operatorului =
    Queue &operator=(const Queue &other)
    {
        if (this != &other)
        {
            elements = other.elements;
        }
        return *this;
    }

    // Functii prietene pentru operatorii de comparare
    friend bool operator==(const Queue &queue1, const Queue &queue2);
    friend bool operator!=(const Queue &queue1, const Queue &queue2);
    friend bool operator<(const Queue &queue1, const Queue &queue2);
    friend bool operator>(const Queue &queue1, const Queue &queue2);

    // Functie pentru calculul normei elementelor cozii
    friend int calculateNorm(const Queue &queue);

    // Supraincarcarea operatorului << pentru afisarea cozii
    friend std::ostream &operator<<(std::ostream &os, const Queue &queue);

    // Supraincarcarea operatorului >> pentru citirea in coada
    friend std::istream &operator>>(std::istream &is, Queue &queue);
};

// Implementarea functiilor prietene
bool operator==(const Queue &queue1, const Queue &queue2)
{
    return queue1.elements == queue2.elements;
}

bool operator!=(const Queue &queue1, const Queue &queue2)
{
    return !(queue1 == queue2);
}

bool operator<(const Queue &queue1, const Queue &queue2)
{
    return calculateNorm(queue1) < calculateNorm(queue2);
}

bool operator>(const Queue &queue1, const Queue &queue2)
{
    return calculateNorm(queue1) > calculateNorm(queue2);
}

int calculateNorm(const Queue &queue)
{
    int norm = 0;

    std::queue<int> tempQueue = queue.elements;
    while (!tempQueue.empty())
    {
        norm += tempQueue.front() * tempQueue.front();
        tempQueue.pop();
    }

    return norm;
}

std::ostream &operator<<(std::ostream &os, const Queue &queue)
{
    std::queue<int> tempQueue = queue.elements;

    while (!tempQueue.empty())
    {
        os << tempQueue.front() << " ";
        tempQueue.pop();
    }

    return os;
}

std::istream &operator>>(std::istream &is, Queue &queue)
{
    int value;
    is >> value;
    queue.enqueue(value);
    return is;
}

int main()
{
    Queue queue1, queue2;

    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    queue2.enqueue(4);
    queue2.enqueue(5);

    Queue sumQueue = queue1 + queue2;

    std::cout << "Queue 1: " << queue1 << std::endl;
    std::cout << "Queue 2: " << queue2 << std::endl;
    std::cout << "Sum of Queues: " << sumQueue << std::endl;

    if (queue1 == queue2)
    {
        std::cout << "Queues are equal." << std::endl;
    }
    else
    {
        std::cout << "Queues are not equal." << std::endl;
    }

    if (queue1 < queue2)
    {
        std::cout << "Queue 1 is less than Queue 2." << std::endl;
    }
    else
    {
        std::cout << "Queue 1 is not less than Queue 2." << std::endl;
    }

    std::cout << "Norm of Queue 1: " << calculateNorm(queue1) << std::endl;

    return 0;
}
