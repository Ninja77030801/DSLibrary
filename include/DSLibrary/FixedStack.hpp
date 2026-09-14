#pragma once
#include <stdexcept>
#include <limits>

namespace DSLibrary 
{
    template <typename T>
    class FixedStack 
    {
        private:
            T* array;
            int capacity;
            int size;
        public:
            T Peek()
            {
                if(this->size > 0)
                {
                    return this->array[size - 1];
                }
                else
                {
                    throw std::underflow_error("No items in stack.");
                }
            }
            int Size()
            {
                return this->size;
            }
            int Capacity()
            {
                return this->capacity;
            }
            void Add(T item)
            {
                if(this->size != this->capacity)
                {
                    this->array[this->size] = item;
                    this->size++;
                }
                else
                {
                    throw(std::overflow_error("You've reached stack capacity."));
                }
            }
            void Pop()
            {
                if(this->size > 0)
                {
                    this->array[this->size - 1].~T();
                    this->size--;
                }
                else
                {
                    std::cout << "Error: Stack is already empty";
                }
            }
            FixedStack(int _size)
            {
                this->capacity = _size;
                this->size = 0;
                this->array = new T[this->capacity];
            }
            ~FixedStack()
            {
                while (this->size > 0)
                {
                    this->Pop();
                }
                delete[] this->array;
            }
    };
}