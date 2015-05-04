#include <iostream>
#include <memory>
template <class T>
class raii
{
	public:
		raii();
		raii(const raii<T>&);
		raii(raii<T>&&);
		~raii();
		raii<T>& operator=(const raii<T>&);
		raii<T>& operator=(raii<T>&&);
		T& operator[](int i);
		const T& operator[](int i) const;
		template <typename ch, typename chcr, class R>
		friend std::basic_ostream<ch, chcr>& operator<<(std::basic_ostream<ch, chcr>& os, const raii<R>& a);
		template <typename ch, typename chcr, class R>
		friend std::basic_istream<ch, chcr>& operator>>(std::basic_istream<ch, chcr>& is, raii<R>& a);
	private:
		T* array_;
		unsigned int length_;
};

template <class T>
raii<T>::raii() : array_{new T[20]}, length_{20}
{
	std::cout << std::endl << "default" << std::endl;
}
template <class T>
raii<T>::~raii()
{
	delete[] array_;
}

template <class T>
raii<T>::raii(const raii<T>& a) 
	try : 
	array_{new T[a.length_]}, length_{a.length_}
	{
		std::copy(a.array_, a.array_ + a.length_, array_);
	}
	catch (...)
	{
		delete[] array_;
	}




template <class T>
raii<T>::raii(raii<T>&& a) : array_(a.array_), length_(a.length_)
{
	std::cout << std::endl << "move" << std::endl;
	a.length_ = 0;
	a.array_ = nullptr;
}
template <class T>
raii<T>& raii<T>::operator=(const raii<T>& a)
{
	raii copy{a};
	std::cout << "\ncopy assignment\n";

	std::swap(array_, copy.array_);
	std::swap(length_, copy.length_);
	return *this;
}
template <class T>
raii<T>& raii<T>::operator=(raii<T>&& a)
{
	raii empty;
	std::cout << "\nmove assignment\n";
	std::swap(empty.array_, a.array_);
	std::swap(empty.length_, a.length_);

	std::swap(empty.array_, array_);
	std::swap(empty.length_, length_);

	return *this;
}

template <class T>
T& raii<T>::operator[](int i)
{
	return array_[i];
}

template <class T>
const T& raii<T>::operator[](int i) const
{
	return array_[i];
}


template <class ch, class chcr, class T>
std::basic_ostream<ch, chcr>& operator<<(std::basic_ostream<ch, chcr>& os, const raii<T>& a)
{
	os << "\n";
	for (int i = 0; i < a.length_; ++i)
	{
		os << a[i] << " ";
	}
	os << "\n";
	return os;
}
template <class ch, class chcr, class T>
std::basic_istream<ch, chcr>& operator>>(std::basic_istream<ch, chcr>& is, raii<T>& a)
{
	for (int i = 0; i < a.length_; ++i)
	{
		is >> a[i];
	}
	return is;
}
