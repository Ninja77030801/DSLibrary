#pragma once


namespace DSLibrary
{
    template <typename T>
    class FixedQueue
    {
        private:
            T* array;
            int capacity;
            int size;

        public:
            FixedQueue(int _capacity)
            {
                this->capacity;
                this->array = new int[this->capacity];
            }
            ~FixedQueue()
            {
                clear();
                std::free(this->array);
            }

            void Enqueue(T item)
            {
                if(this->size < this->capacity)
                {
                    this->array[this->capacity - 1] = item;
                    this->size++;
                }
                else
                {
                    throw std::overflow_error("Error! Queue is too big!");
                }
            }

            void Dequeue()
            {
                if(this->size < this->capacity)
                {
                    throw std::underflow_error("Error! Cannot dequeue and empty queue!");
                }
                else
                {
                    this->array[this->size].~T();
                    this->size--;
                }
            }
    }
}