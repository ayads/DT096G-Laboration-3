//Author: Ayad Shaif
//Laboration: 3
//Programspråksteori

#include <iostream>
#include <cmath>

template<int exp, typename enable = void>
struct Pow
{
	double operator()(double bas) {
		return (bas * Pow<exp - 1>()(bas));
	}
};

//For negative exponentials:
template<int exp>
struct Pow<exp, typename std::enable_if<(exp < 0)>::type>
{
	double operator()(double bas) {
		return (1 / Pow<-exp>()(bas));
	}
};

//If exponential is zero:
template<>
struct Pow<0>
{
	double operator()(double bas) {
		return 1;
	}
};

//If exponential is one:
template<>
struct Pow<1>
{
	double operator()(double bas) {
		return bas;
	}
};

//Main Function:
int main()
{
	Pow<-1> exp_negative_1;
	Pow<0> exp_positive_0;
	Pow<1> exp_positive_1;
	Pow<2> exp_positive_2;

	std::cout << "3^-1:\t" << exp_negative_1(3) << std::endl;
	std::cout << "3^0:\t" << exp_positive_0(3) << std::endl;
	std::cout << "3^1:\t" << exp_positive_1(3) << std::endl;
	std::cout << "3^2:\t" << exp_positive_2(3) << std::endl;

	std::cin.get();
	return 0;
}