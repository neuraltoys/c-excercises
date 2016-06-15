#pragma once

#include <memory>

namespace Maciek {

template <typename T>
class UniquePointer
{
	private:
		T *_ptr;

		template <class U> UniquePointer(UniquePointer<U> &);
		template <class U> UniquePointer &operator=(UniquePointer<U> &);

	public:
//		typedef T element_type;
//		typedef D deleter_type;

		UniquePointer();

		explicit UniquePointer(T *p);

		~UniquePointer();

		UniquePointer &operator=(UniquePointer u);

		template <class U>
		UniquePointer &operator=(UniquePointer<U> u);

		T operator*() const;

		T *operator->() const;

		T *get() const;

		T *release();

		void reset(T *p = 0);

		void swap(UniquePointer &u);
	};
}