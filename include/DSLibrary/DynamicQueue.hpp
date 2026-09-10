#pragma once
#include <cstdlib>

namespace DSLibrary
{
    template <typename T>
    class DynamicQueue
    {
        private:
            T* array;
            size_t size;
            size_t capacity;

            void grow()
            {
                size_t newCapacity = (this->capacity == 0) ? 2 : this->capacity * 2;

                T* newBlock = (T*) std::malloc(newCapacity * sizeof(T));

                if(!newBlock)
                {
                    throw std::bad_alloc();
                }

                for (size_t i = 0; i < this->size; i++)
                {
                    new (&newBlock[i]) T(std::move(this->data[i]));
                }

                std::free(this->array);
                this->array = newBlock;
                this->capacity = newCapacity;
            }
        
        public:
            void Enqueue(T item)
            {
                if(this->size == this->capacity)
                {
                    this->grow();
                }

                this->array[this->size] = item;
                this->size++;
            }
            void Dequeue()
            {
                this->array[0].~T();
                for (size_t i = 1; i < array_size; ++i;)
                {
                    this->array[i - 1] = std::move(this->array[i]);
                }
            }
            DynamicQueue(): array(nullptr), size(0), capacity(0) {}
            ~DynamicQueue()
            {
                while (this->size > 0)
                {
                    this->Dequeue();
                }
                std::free(this->array);
            }
    };
}