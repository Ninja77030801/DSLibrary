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
                    new (&newBlock[i]) T(std::move(this->data[i]))
                }

                std::free(this->array);
                this->array = newBlock;
            }
        
        public:
            DynamicQueue(): this->array(nullptr), this->size(0), this->capacity(0) {}
            ~DynamicQueue()
            {
                std::clear(this->array);
            }
    };
}