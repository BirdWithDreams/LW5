#include "DynamicArray.h"

bool DynamicArray::push_back(Dekanat el)
{
    if (size() == max_size - 1)
        if (!resize(max_size * 2))
            return false;

    array[tail++] = el;
    tail %= max_size + 1;
    cur_size++;
    return true;
}

Dekanat DynamicArray::pop_back()
{
    if (cur_size == 0)
        throw EmptyArrayException();

    auto el = array[--tail];
    tail %= max_size + 1; 
    cur_size--;
    return el;
}

bool DynamicArray::push_front(Dekanat el)
{
    if (size() == max_size)
        if (!resize(max_size * 2))
            return false;

    head--;
    head = head % (max_size + 1);
    if (head < 0)
        head += max_size + 1;

    array[head] = el;
    cur_size++;
    return true;
}

Dekanat DynamicArray::pop_front()
{
    if (cur_size == 0)
        throw EmptyArrayException();

    auto el = array[head++];
    head %= max_size + 1;
    cur_size--;
    return el;
}

Dekanat DynamicArray::get(int index)
{
    index = (index + head) % max_size;
    return array[index];
}

int DynamicArray::size()
{
    return cur_size;
}

void DynamicArray::print()
{
    std::cout << "\nThis array has: ";
    for (int i = head; i != tail; ++i, i %= (max_size + 1))
        std::cout << array[i];
    std::cout << std::endl;
}

bool DynamicArray::resize(int new_size)
{
    auto new_array = new Dekanat[new_size + 1];
    if (head < tail)
        for (int i = head; i < tail; i++)
            new_array[i] = array[i];
    else
    {
        for (int i = 0; i < tail; i++)
            new_array[i] = array[i];

        int new_head = new_size + tail - max_size + 1;
        for (int i = 0; i < max_size - tail; i++)
            new_array[new_head + i] = array[head + i];
        head = new_head;
    }
    delete[] array;
    array = new_array;
    max_size = new_size;
    return true;
}

