#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <class T>
class RingBuffer
{
    public:
        RingBuffer(int numElements);
        ~RingBuffer();
        void add(T element);
        T get(int idx) const;
        int size() const { return _currNumElements; } 

        class Iterator;

        Iterator begin() { return Iterator(0, *this); }
        Iterator end()   { return Iterator(_currNumElements, *this); }

    private:
        int _headPtr;
        int _currNumElements;
        int _maxNumElements;
        bool _isFull;
        T* _internalArray;
};


// Iterator Class ####################################

template <class T>
class RingBuffer<T>::Iterator
{
    public:
        Iterator(int pos, RingBuffer &ring) : _iterRing(ring), _iterPos(pos)
        {}

        Iterator& operator++(int) // pre-fix type does not take in any arguments
        {
            _iterPos++;
            return *this;
        }

        Iterator& operator++()
        {
            _iterPos++;
            return *this;
        }

        T operator*()
        { 
            return _iterRing.get(_iterPos); 
        }

        bool operator!=(const Iterator &other) const 
        {
            return _iterPos != other._iterPos;
        }

    private:
        int _iterPos;
        RingBuffer &_iterRing; // cannot be a pointer since it's a reference to a class
};

// Ring Buffer Methods ####################################

template <class T>
RingBuffer<T>::RingBuffer(int numElements) :
    _headPtr(0), _currNumElements(0), _maxNumElements(numElements), _isFull(false)
{
    _internalArray = new T[numElements];
}

template <class T>
RingBuffer<T>::~RingBuffer()
{
    delete[] _internalArray; 
}

template <class T>
void RingBuffer<T>::add(T element)
{
    _internalArray[_headPtr] = element;
    _headPtr++;

    if (!_isFull) _currNumElements++;

    if (_currNumElements == _maxNumElements)
    {
        _headPtr = 0;
        _isFull = true;
    }
}

template <class T>
T RingBuffer<T>::get(int idx) const
{
    if (idx >= _maxNumElements)
    {
        throw invalid_argument("Index is out of bounds.");
    }

    return _internalArray[idx];
}


#endif

