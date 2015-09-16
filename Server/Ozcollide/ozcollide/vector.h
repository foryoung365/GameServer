/*
OZCollide - Collision Detection Library
Copyright (C) 2006-2014 by Igor Kravtchenko

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Contact the author: igor@tsarevitch.org
*/

#ifndef OZCOLLIDE_VECTOR_H
#define OZCOLLIDE_VECTOR_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

/**
 * A Vector is the equivalent of a std::vector but simplier to use.
 * std::vector is painful to use and lack of many functionnalities. OZCollide vector is a short and very fast way to bypass std::vector.
 */
template <class T> class Vector {

public:

    /**
     * Constructs an empty Vector. No memory is allowed and size and capacity are set to 0.
     */
    Vector()
    {
        mem_ = NULL;
        size_ = 0;
        capacity_ = 0;
    }

    /**
     * Destroys the Vector instance. Typically it just calls the clear() method then free the instance.
     */
    ~Vector()
    {
        clear();
    }

    /**
     * Adds an element to the vector. If the size is not enough, the capacity is increased.
     * @param _t The element to add.
     */
    void add(const T &_t)
    {
        if (size_ < capacity_) {
            mem_[size_] = _t;
            size_++;
            return;
          }

        resize(size_ + 1);
        mem_[size_ - 1] = _t;
    }

    /**
     * Insert an element given an index.
     * @param _t The element to insert.
     * @param _i The zero based index to insert element. For instance if you mention 0, the element will be inserted in the beginning of the Vector. This method is pretty costly.
     */
    void insert(const T &_t, int _i)
    {
        if (_i > size())
            return;
		
        if (_i == size()) {
            add(_t);
            return;
        }

        int oldSize = size_;
        resize(size_ + 1);

        for (int j = oldSize; j > _i; j--)
            mem_[j] = mem_[j - 1];
        mem_[_i] = _t;
    }

    /**
     * Removes an element given its index. The method is pretty costly as elemements are linearly linked in memory. This affects size() but not capacity().
     * @param _index of the element to remove. If the element is not in correct range, nothing happens.
     */
    void remove(int _index)
    {
        if (unsigned(_index) >= unsigned(size_))
            return;

        T *t = &mem_[_index];
        T *right = mem_ + size_;
        if (t + 1 < right)
            memcpy(t, t + 1, (right - t - 1) * sizeof(T));
        size_--;
    }

    /**
     * Removes an element given its reference. The method is pretty costly as elemements are linearly linked in memory. This affects size() but not capacity().
     * @param _t the element to remove. If the element is not presents in the vector, nothing happens.
     */
    void removeElement(const T _t)
    {
        while(true) {
            int siz = size();
            int i = 0;
            for ( ; i < siz; i++) {
                if (mem_[i] == _t) {
                    remove(i);
                    break;
                }
            }
            if (i == siz)
                break;
            }
        }


    /**
     * Replaces an element by another.
     * Takes a reference to an element and replace all instances by a new one.
     * @param _t The element to be replaced.
     * @param _by The element that will replaced.
     */
    void replaceElement(const T _t, const T _by)
    {
        for (int i = 0; i < size_; i++) {
            if (mem_[i] == _t)
                mem_[i] = _by;
        }
     }

    /**
     * Recopies this vector.
     * This method doesn't allocate a new vector. Instead it takes a reference to an already created vector and breaks it to reflect the copy of this vector.
     * @param _v The vector that will reflect the copy.
     */
    void copy(Vector &_v) const
    {
        _v.clear();
        _v.size_ = size_;
        _v.capacity_ = capacity_;
        _v.mem_ = (T*) malloc(_v.capacity_ * sizeof(T));
        memcpy(_v.mem_, mem_, _v.capacity_ * sizeof(T));
    }

    /**
     * Resizes this vector.
     * Resizing a vector means to change its potential number of element. If the size exceeds the current memory size of the vector, the method will grows up automaticaly.
     * @param _size The new size of the vector. This can be affect the capicity of the vector.
     */
    void resize(int _size)
    {
        if (_size > capacity_)
            reserve(_size * 2);
        size_ = _size;
     }

    /**
     * Reserves a new capacity for the vector.
     * The capacity of a vector is the maximum number of elements it can contain without the need to reserve a larger amount of memory.
     * @param _capacity
     */
     void reserve(int _capacity)
     {
         T *old = mem_;
         mem_ = (T*) malloc(_capacity * sizeof(T));
         int toCopy = _capacity > capacity_ ? capacity_ : _capacity;
         memcpy(mem_, old, toCopy * sizeof(T));
         if (old)
             free(old);
         capacity_ = _capacity;
      }

     /**
      * Increases or decreases the current size of the vector.
      * This directly influences the size() method.
      * @param _size
      */
      void grow(int _size)
      {
          resize(size_ + _size);
      }

      /**
       * Creates a new element and appends it at the end of the vector.
       * @return The new element.
       */
      T* inc()
      {
          resize(size_ + 1);
          return &mem_[size_ - 1];
      }

      /**
       * Disallows all memory used by this instance, and set all member to 0. The Vector becomes the same as in it was just created.
       * @brief Clears the vector.
       */
      void clear()
      {
          if (mem_)
              free(mem_);
          mem_ = NULL;
          size_ = 0;
          capacity_ = 0;
      }

      /**
       * Returns the size of the vector.
       * The size of a vector is the number of elements it currently contains.
       * @return The size of this vector.
       */
      int size() const
      {
          return size_;
      }

      /**
       * Returns the capacity of the vector.
       * A capacity of a vector is the maximum number it can contains without the need of allocating a larger amount of memory.
       * @return The capacity of the vector.
       */
      int capacity() const
      {
          return capacity_;
      }

      /**
       * Returns a pointer to the memory location used by this vector.
       * This method bypass the blackbox methods and is to use at your own risk.
       * @return The pointer to the memory location used by the vector.
       */
      T* mem() const
      {
          return mem_;
      }

      /**
       * Returns the last elements of the vector.
       * @return The last element of the vector.
       */
      T& last() const
      {
          return mem_[size_ - 1];
      }

      /**
       * Tests if an element is present into this vector.
       * @param _t The element to test
       * @return true if the element is included in this vector, false otherwhise
       */
      bool isIncluded(T _t) const
      {
          for (int i = 0; i < size(); i++) {
              if (mem_[i] == _t)
                  return true;
          }
          return false;
      }

      /**
       * Gets the index buffer of an element in this vector.
       * @param _t The index buffer of the element.
       * @return  The index buffer of the element if present, -1 otherwhise.
       */
      int getIndexBuffer(T _t) const
      {
          for (int i = 0; i < size(); i++) {
              if (mem_[i] == _t)
                  return i;
          }
          return -1;
      }

      /**
       * Returns an element of this vector given its index.
       * @param _index The index of the elements
       * @return
       */
      T& operator [] (int _index) const
      {
          return mem_[_index];
      }

private:
    T   *mem_;
    int size_;
    int capacity_;
};

LEAVE_NAMESPACE

#endif
