#include "unique_pointer.h"

#include <cstring>
#include <iostream>

namespace Maciek{

	template <class T>
	UniquePointer<T>::UniquePointer() :
			_ptr(0)
	{}

	template <class T>
	UniquePointer<T>::UniquePointer(T *p) :
			_ptr(p)
	{}

	template <class T>
	UniquePointer<T>::~UniquePointer()
	{
		reset();
	}

	template <class T>
	UniquePointer<T> &UniquePointer<T>::operator=(UniquePointer<T> u)
	{
		reset(u.release());
		return *this;
	}

	template <class T>
	T UniquePointer<T>::operator*() const
	{
		return *_ptr;
	}

	template <class T>
	T *UniquePointer<T>::operator->() const
	{
		return _ptr;
	}

	template <class T>
	T *UniquePointer<T>::get() const
	{
		return *_ptr;
	}

	template <class T>
	T *UniquePointer<T>::release()
	{
		T *tmp = _ptr;
		_ptr = 0;
		return tmp;
	}

	template <class T>
	void UniquePointer<T>::reset(T *p)
	{
		if (_ptr != p) {
			if (_ptr) {
				_ptr->release();
				_ptr = p;
			}
		}
	}

	template <class T>
	void UniquePointer<T>::swap(UniquePointer<T> &u)
	{
		std::swap(_ptr, u);
	}

	template <class T>
	inline void swap(UniquePointer<T> &x, UniquePointer<T> &y)
	{
		x.swap(y);
	}

	template <class T1, class T2>
	bool operator==(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() == y.get();
	}

	template <class T1, class T2>
	bool operator!=(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() != y.get();
	}

	template <class T1, class T2>
	bool operator<(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() < y.get();
	}

	template <class T1, class T2>
	bool operator<=(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() <= y.get();
	}

	template <class T1, class T2>
	bool operator>(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() > y.get();
	}

	template <class T1, class T2>
	bool operator>=(const UniquePointer<T1> &x, const UniquePointer<T2> &y)
	{
		return x.get() >= y.get();
	}

}