// The following libraries include various funcations and definitions needed
#include <cstddef>
#include <limits>
#include <cstring>
#include <iostream>

template <std::size_t N>
class bool_array
{
	public:
		// Couple of helpful redefinitions
		using size_type = std::size_t;
		using value_type = bool;

		// Default constructor
		bool_array();
		// Copy constructor
		bool_array(bool_array const& a);
		// Default defined Destructor
		~bool_array() = default;

		// Copy assignment operator
		bool_array& operator =(bool_array const& a);

		// Maximum size of bools able to be stored, precomputed at compile time.
		constexpr size_type size() const;
	private:
		// private internal class bit_proxy
		class bit_proxy
		{
			public:
				// Constructor deleted.
				bit_proxy() = delete;
				// Move constructor default defined.
				bit_proxy(bit_proxy&&) = default;
				// Copy constructor default defined.
				bit_proxy(bit_proxy const&) = default;
				// Two parameter constructor
				bit_proxy(unsigned char& datum, size_type offset);

				// Destructor default defined.
				~bit_proxy() = default;

				// Copy assignment operator.
				bit_proxy& operator =(bit_proxy const&) = default;
				// Move assignment operator
				bit_proxy& operator =(bit_proxy&&) = default;

				// bool assignment operator.
				bit_proxy& operator =(bool);

				// bool cast function
				operator bool() const;
			private:
				// stores the char
				unsigned char& datum_;
				// stores the position of the bit of interest. 
				size_type offset_;
		};
		// finds the minimum amount of chars needed to store the amount of bits requested.
		static constexpr auto MAX = N / std::numeric_limits<unsigned char>::digits + (N % std::numeric_limits<unsigned char>::digits != 0);
		// bits_ is used to store the bits for the bools.
		unsigned char bits_[MAX];
	public:
		// The array index operator.
		bit_proxy operator [](size_type i);
};

// default bool_array constructor sets all relevant bits to 0.
template <std::size_t N>
bool_array<N>::bool_array()
{
	std::memset(bits_, 0, MAX);
}

// Copy bool_array constructor  copies all relevant bits into memory.
template <std::size_t N>
bool_array<N>::bool_array(bool_array const& a)
{
	std::memcpy(bits_, a.bits_, MAX);
}

// Copy assignment operator copies all relevant bits into this object's memory.
template <std::size_t N>
bool_array<N>& bool_array<N>::operator =(bool_array const& a)
{
	std::memcpy(bits_, a.bits_, MAX);
	return *this;
}

// Returns a bit_proxy object that allows users to use the array indexing to read, write, and assign.
template <std::size_t N>
typename bool_array<N>::bit_proxy bool_array<N>::operator[](size_type i)
{
	return bit_proxy{ bits_[i / std::numeric_limits<unsigned char>::digits], i % std::numeric_limits<unsigned char>::digits };
}

// Computed at compile time and returns the max amount of bools bool_array stores.
template <std::size_t N>
constexpr std::size_t bool_array<N>::size() const
{
	return N;
}

// Two parameter constructor that sets relevant information passed into it.
template <std::size_t N>
bool_array<N>::bit_proxy::bit_proxy(unsigned char& datum, size_type offset) : datum_(datum), offset_(offset)
{
}

// bool assignment operator that sets the relevant bool bit to the correct value.
template <std::size_t N>
typename bool_array<N>::bit_proxy& bool_array<N>::bit_proxy::operator =(bool b)
{
	unsigned char value = 1;
	if (b)
	{
		datum_ |= (value << offset_);
	}
	else
	{
		datum_ &= ~(value << offset_);
	}
	return *this;
}

// bool cast operator thats returns true or false if the bit at the relevant location is 1 or 0 respectively.
template <std::size_t N>
bool_array<N>::bit_proxy::operator bool() const
{
	unsigned char value = 1;
	return (datum_ & (value << offset_)) != 0;
}

// Relevent main that tests a 13 bool_array in various methods and operations. the output explains what each test should do.
int main()
{
	using namespace std;

	bool_array<13> test;

	std::cout << "The following is the default constructor and should be all zeros." << std::endl;
	for (unsigned int i=0; i != 13; ++i)
		std::cout << i << ": " << test[i] << '\n';

	std::cout << "The following outputs the loop number then the current value then sets it to true, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned int i=0; i != 13; ++i)
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
	if (test[4] == true)
	{
		std::cout << "The 4th bool is true, as it should be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, and it shouldn't be" << std::endl;
	}

	std::cout << "The following outputs the loop number then the current value then sets it to false, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned int i=0; i != 13; ++i)
	{
		std::cout << i << ": " << test[i] << "; ";
		test[i] = false;
		std::cout << test[i] << '\n';
		for (unsigned int k=0; k != 13; std::cout << test[k] << " ", ++k);
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
	if (test[4] != false)
	{
		std::cout << "The 4th bool is true, and it shouldn't be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, as it should be" << std::endl;
	}


	std::cout << "\n\n";
}
