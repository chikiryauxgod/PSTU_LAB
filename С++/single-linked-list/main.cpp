#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();
    void push_back(T data);
    int GetSize() { return Size; }
    T& operator[](const int index);
    void pop_front();
    void clear();
    void insert(T value, int index);
    void push_front(T data);
    void removeAt(int index);

private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data; 
        Node(T data = T(), Node* pNext = nullptr) 
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
            current = current->pNext;
            counter++;
    }
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
        cout << "The element was deleted." << endl;
    }
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}  

    

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node <T>(data, head);
    Size++;
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front(data);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = toDelete->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }

    
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.pop_front();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    lst.clear();
    return 0;
}
