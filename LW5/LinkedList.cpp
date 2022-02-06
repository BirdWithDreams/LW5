#include "LinkedList.h"

bool LinkedList::push_back(Dekanat el)
{
    auto node = new Node;
    node->el = el;
    if (cur_size == 0)
        head = tail = node;

    else 
    {
        tail->next = node;
        tail = node;
    }
    cur_size++;
    return true;
}

Dekanat LinkedList::pop_back()
{
    if (!head)
        throw EmptyListException();

    auto dek = tail->el;

    auto node = head;
    if (!node->next)
    {
        tail = head = nullptr;
        cur_size--;
        return dek;
    }

    for (; node->next != tail; node = node->next);
    tail = node;
    tail->next = nullptr;
    cur_size--;

    return dek;
}

bool LinkedList::push_front(Dekanat el)
{
    auto node = new Node;
    node->el = el;

    if (!head)
        head = tail = node;

    else
    {
        node->next = head;
        head = node;
    }
    return true;
}

Dekanat LinkedList::pop_front()
{
    if (!head)
        throw EmptyListException();

    auto el = head->el;
    if (!head->next)
        head = tail = nullptr;
    else
        head = head->next;
    return el;
}

Dekanat LinkedList::get(int index)
{
    auto node = head;
    int count = 0;
    for (; count != index; node = node->next, count++);

    return node->el;
}

int LinkedList::size()
{
    return cur_size;
}

void LinkedList::print()
{
    std::cout << "\nThis list has: ";
    for (auto i = head; i != nullptr; i = i->next)
        std::cout << i->el;
    std::cout << std::endl;
}
