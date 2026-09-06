#pragma once
#include <cstdlib>

namespace DSLibrary
{
    template <typename T>
    class DynamicStack 
    {
        private:
            T* array;
            size_t size;

            size_t capacity;

            void grow()
            {
                size_t newCapacity = (this->capacity ==0) ? 2 : this->capacity * 2;

                T* newBlock = (T*) std::malloc(newCapacity * sizeof(T))
                if(!newBlock)
                {
                    throw std::bad_alloc();
                }

                for (size_t i = 0; i < this->size; ++i)
                {
                    new (&newBlock[i]) T(std::move(this->data[i]));
                    this->array[i].~T();
                }

                std::free(this->array);
                this->array = newBlock;
            }
        public:
            DynamicStack(): this->array(nullptr), this->size(0), this->capacity(0) {}

            ~DynamicStack()
            {
                clear();
                std::free(this->array);
            }
            void Add(T item)
            {
                if(this->size == this->capacity)
                {
                    this->grow();
                }

                new ( &this->array[this->size] ) T(value);
                this->size++;
            }

            void Pop()
            {
                if(this->size == 0)
                {
                    throw std::underflow_error("Stack underflow: Cannot remove from empty stack")
                }

                this->size--;
                this->array[this->size].~T();
            }

            T& Top()
            {
                if(this->size == 0)
                {
                    throw std::underflow_error("Stack is empty");
                }
                else
                {
                    return this->array[this->size - 1];
                }
            }

            bool isEmpty() const
            {
                return this->size == 0;
            }

            size_t Size() const
            {
                return this->size;
            }

            size_t Capacity() const
            {
                return this->capacity;
            }

            void Clear()
            {
                while(this->size > 0)
                {
                    this->Pop();
                }
            }
    };
}