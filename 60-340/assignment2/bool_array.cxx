#include <cstddef>
#include <limits>
#include <cstring>
#include <iostream>

template <std::size_t N>
class bool_array
{
	public:
		using size_type = std::size_t;
		using value_type = bool;

		bool_array();
		bool_array(bool_array const& a);
		~bool_array();

		bool_array& operator =(bool_array const& a);

		constexpr size_type size() const;
	private:
		class bit_proxy
		{
			public:
				bit_proxy() = delete;
				bit_proxy(bit_proxy&&) = default;
				bit_proxy(bit_proxy const&) = default;
				bit_proxy(unsigned char& datum, size_type offset);

				~bit_proxy() = default;

				bit_proxy& operator =(bit_proxy const&) = default;
				bit_proxy& operator =(bit_proxy&&) = default;

				bit_proxy& operator =(bool);

				operator bool() const;
			private:
				unsigned char& _datum;
				size_type _offset;
		};
		static constexpr auto MAX = N / std::numeric_limits<unsigned char>::digits + (N % std::numeric_limits<unsigned char>::digits != 0);
		unsigned char _bits[MAX];
	public:
		bit_proxy operator [](size_type i);
};

template <std::size_t N>
bool_array<N>::bool_array()
{
	std::memset(_bits, 0, MAX);
}

template <std::size_t N>
bool_array<N>::bool_array(bool_array const& a)
{
	std::memcpy(_bits, a._bits, MAX);
}

template <std::size_t N>
bool_array<N>::~bool_array() = default;

template <std::size_t N>
bool_array<N>& bool_array<N>::operator =(bool_array const& a)
{
	std::memcpy(_bits, a._bits, MAX);
	return *this;
}

template <std::size_t N>
typename bool_array<N>::bit_proxy bool_array<N>::operator[](size_type i)
{
	return bit_proxy{ _bits[i / std::numeric_limits<unsigned char>::digits], i % std::numeric_limits<unsigned char>::digits };
}

template <std::size_t N>
constexpr std::size_t bool_array<N>::size() const
{
	return N;
}

template <std::size_t N>
bool_array<N>::bit_proxy::bit_proxy(unsigned char& datum, size_type offset) : _datum(datum), _offset(offset)
{
}

template <std::size_t N>
typename bool_array<N>::bit_proxy& bool_array<N>::bit_proxy::operator =(bool b)
{
	unsigned char value = 1;
	if (b)
	{
		_datum |= (value << _offset);
	}
	else
	{
		_datum &= ~(value << _offset);
	}
	return *this;
}

template <std::size_t N>
bool_array<N>::bit_proxy::operator bool() const
{
	unsigned char value = 1;
	if ((_datum & (value << _offset)) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	using namespace std;

	bool_array<13> test;

	std::cout << "The following is the default constructor and should be all zeros." << std::endl;
	for (unsigned i=0; i != 13; ++i)
		std::cout << i << ": " << test[i] << '\n';

	std::cout << "The following outputs the current value then sets to true, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned i=0; i != 13; ++i)
	{
		std::cout << i << ": " << test[i] << "; ";
		test[i] = true;
		std::cout << test[i] << '\n';
		for (unsigned k=0; k != 13; std::cout << test[k] << " ", ++k);
		std::cout << std::endl;
	}
	if (test[4])
	{
		std::cout << "The 4th bool is true, as it should be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, and it shouldn't be" << std::endl;
	}

	std::cout << "The following outputs the current value then sets to false, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned i=0; i != 13; ++i)
	{
		std::cout << i << ": " << test[i] << "; ";
		test[i] = false;
		std::cout << test[i] << '\n';
		for (unsigned k=0; k != 13; std::cout << test[k] << " ", ++k);
		std::cout << std::endl;

	}
	if (test[4])
	{
		std::cout << "The 4th bool is true, and it shouldn't be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, as it should be" << std::endl;
	}

	std::cout << "\n\n";
}
