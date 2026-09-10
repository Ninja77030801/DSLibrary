#pragma once


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
                return this->array[size - 1];
            }
            int Size()
            {
                return this->size;
            }
            int Capacity()
            {
                return this->size;
            }
            void Add(T item)
            {
                if(this->size != this->capacity)
                {
                    this->array[this->size] = item;
                    size++;
                }
                else
                {
                    throw(std::overflow_error("You've reached stack capacity."));
                }
            }
            void RemoveLastItem()
            {
                if(this->size > 0)
                {
                    this->array[this->size].~T();
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
            ~FixedStack()
            {
                while (this->size > 0)
                {
                    this->RemoveLastItem();
                }
                std::free(this->array);
            }
    };
}