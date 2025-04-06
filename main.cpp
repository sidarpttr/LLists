#include <cstddef>
#include <iostream>
using namespace std;

class Node
{
public:
    int element;
    Node *next;
    Node(const int e = int(), Node *n = nullptr) : element(e), next(n)
    {
    }
};

class LinkedList
{
private:
    Node *dummyHead;

public:
    LinkedList()
    {
        dummyHead = new Node(int(), nullptr);
    }

    Node *zeroth()
    {
        return dummyHead;
    }

    Node *first()
    {
        return dummyHead->next;
    }

    bool isEmpty()
    {
        return first() == nullptr;
    }

    Node *find(int data)
    {
        Node *p = first();
        while (p)
        {
            if (p->element == data)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    Node *findPrev(int data)
    {
        Node *p = zeroth();
        while (p->next)
        {
            if (p->next->element == data)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    void insert(int data, Node *p)
    {
        Node *newNode = new Node(data, p->next);
        p->next = newNode;
    }

    void remove(int data)
    {
        Node *prev = findPrev(data);
        if (prev->next != nullptr)
        {
            Node *temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }
    }

    int TraversingCount()
    {
        Node *p = zeroth();
        int count = 0;

        while (p->next)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void ekranaYaz()
    {
        Node *p = first();
        while (p)
        {
            cout << p->element << " -> ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList liste = LinkedList();
    liste.insert(31, liste.zeroth());
    Node *p = liste.first();
    for (int i = 0; i < 20; i++)
    {
        liste.insert(i + 10, p);
        p = p->next;
    }


    liste.remove(12);
    liste.ekranaYaz();

    int elemanSayisi = liste.TraversingCount();
    cout << "eleman sayısı: " << elemanSayisi << endl;
}