#pragma once


namespace DSLibrary 
{
    template <typename T>
    class FixedStack 
    {
        private:
            T* array;
        public:
            int capacity;
            int size;
            T Peek()
            {
                return this->array[size - 1];
            }
            void Add(T item)
            {
                if(this->size != this->capacity)
                {
                    this->array[this->capacity];
                    size++;
                }
                else
                {
                    std::cout << "Error! Stack is full";
                }
            }
            void RemoveLastItem()
            {
                if(this->size > 0)
                {
                    this->array[this->size] = NULL;
                    size--;
                }
                else
                {
                    std::cout << "Error: Stack is already empty";
                }
            }
            FixedStack(int _size)
            {
                this->size = _size;
                this->array = new int[size];
            }
    };
}