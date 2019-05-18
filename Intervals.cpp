//============================================================================
// Name        : Intervals.cpp
// Author      : Rebecca Su
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

int main();
void interval_calculator();
void print_interval();
void print_error();
void exit();
void enter();
void negate();
void invert();
void ms();
void mr();
void mc();
void m_plus();
void m_minus();
void scalar_add();
void scalar_subtract();
void scalar_multiply();
void scalar_divide();
void scalar_divided_by();
void interval_add();
void interval_subtract();
double min(double a, double b, double c, double d);
double max(double a, double b, double c, double d);
void interval_multiply();
void interval_divide();
void intersect();
double minimum(double a, double b);
double maximum(double a, double b);
void integers();
void cartesian_integers();

bool exit_program(true);
double i_interval1;
double i_interval2;
double m_interval1;
double m_interval2;

int main() {
	interval_calculator();
	return 0;
}

void interval_calculator()
{
	while(exit_program)
	{
		std::string command;

		std::cout << "input :> ";
		std::cin >> command;

		if(command == "exit")
			exit();
		else if(command == "enter")
			enter();
		else if(command == "negate")
			negate();
		else if(command == "invert")
			invert();
		else if(command == "ms")
			ms();
		else if(command == "mr")
			mr();
		else if(command == "mc")
			mc();
		else if(command == "m+")
			m_plus();
		else if(command == "m-")
			m_minus();
		else if(command == "scalar_add")
			scalar_add();
		else if(command == "scalar_subtract")
			scalar_subtract();
		else if(command == "scalar_multiply")
			scalar_multiply();
		else if(command == "scalar_divide")
			scalar_divide();
		else if(command == "scalar_divided_by")
			scalar_divided_by();
		else if(command == "interval_add")
			interval_add();
		else if(command == "interval_subtract")
			interval_subtract();
		else if(command == "interval_multiply")
			interval_multiply();
		else if(command == "interval_divide")
			interval_divide();
		else if(command == "intersect")
			intersect();
		else if(command == "integers")
			integers();
		else if(command == "cartesian_integers")
			cartesian_integers();
		else
			std::cout << "Error: illegal command" << std::endl;
	}
}

void print_interval()
{
	if(i_interval1 == 0 && i_interval2 == 0)
		std::cout << "--" << std::endl;
	else
		std::cout << "[" << i_interval1 << ", " << i_interval2 << "]" << std::endl;
}

void print_error()
{
	std::cout << "Error: division by zero" << std::endl;
	i_interval1 = 0;
	i_interval2 = 0;
}

void exit()
{
	std::cout << "Bye bye: Terminating interval calculator program.";
	exit_program = false;
}

void enter()
{
	double a;
	double b;

	std::cin >> a >> b;

	if(a > b)
	{
	std::cout << "Error: invalid interval as a > b" << std::endl;
	i_interval1 = 0;
	i_interval2 = 0;
	print_interval();
	}
	else if(a == 0 && b == 0)
	std::cout << "--" << std::endl;
	else
	std::cout << "[" << a << ", " << b << "]" << std::endl;

	i_interval1 = a;
	i_interval2 = b;
}

void negate()
{
	std::swap(i_interval1, i_interval2);
	i_interval1 *= -1;
	i_interval2 *= -1;
	print_interval();
}

void invert()
{
	if(i_interval1 == 0 && i_interval2 == 0)
		print_interval();
	else if(i_interval1 <= 0 && i_interval2 >= 0)
	{
		print_error();
		print_interval();
	}
	else
	{
		std::swap(i_interval1, i_interval2);
		i_interval1 = 1 / i_interval1;
		i_interval2 = 1 / i_interval2;
		print_interval();
	}
}

void ms()
{
	if(i_interval1 != 0 && i_interval2 != 0)
	{
		m_interval1 = i_interval1;
		m_interval2 = i_interval2;
	}
	print_interval();
}

void mr()
{
	if(m_interval1 != 0 && m_interval2 != 0)
	{
		i_interval1 = m_interval1;
		i_interval2 = m_interval2;
	}
	print_interval();
}

void mc()
{
	m_interval1 = 0;
	m_interval2 = 0;
	print_interval();
}

void m_plus()
{
	m_interval1 += i_interval1;
	m_interval2 += i_interval2;
	print_interval();
}

void m_minus()
{
	m_interval1 -= i_interval1;
	m_interval2 -= i_interval2;
	print_interval();
}

void scalar_add()
{
	double operand(0);
	std::cin >> operand;

	if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 += operand;
		i_interval2 += operand;
	}
	print_interval();
}

void scalar_subtract()
{
	double operand(0);
	std::cin >> operand;

	if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 -= operand;
		i_interval2 -= operand;
	}
	print_interval();
}

void scalar_multiply()
{
	double operand(0);
	std::cin >> operand;

	if(i_interval1 == 0 && i_interval2 == 0)
		print_interval();
	else
	{
		i_interval1 *= operand;
		i_interval2 *= operand;

		if(operand > 0)
			print_interval();
		else if(operand < 0)
		{
			std::swap(i_interval1, i_interval2);
			print_interval();
		}else
			std::cout << "[0, 0]" << std::endl;
	}
}

void scalar_divide()
{
	double operand(0);
	std::cin >> operand;

	if(i_interval1 == 0 && i_interval2 == 0)
		print_interval();
	else
	{
		if(operand != 0)
		{
			i_interval1 = i_interval1 / operand;
			i_interval2 = i_interval2 / operand;
		}

		if(operand == 0)
			print_error();
		else if(operand < 0)
			std::swap(i_interval1, i_interval2);
		print_interval();
	}
}

void scalar_divided_by()
{
	double operand(0);
	std::cin >> operand;

	if(i_interval1 == 0 && i_interval2 == 0)
		print_interval();
	else if(i_interval1 <= 0 && i_interval2 >= 0)
	{
		print_error();
		std::cout << "--" << std::endl;
	}else
	{
		i_interval1 = operand / i_interval1;
		i_interval2 = operand / i_interval2;
		if(operand < 0)
			print_interval();
		else if(operand > 0)
		{
			std::swap(i_interval1, i_interval2);
			print_interval();
		}else
			std::cout << "[" << i_interval1 << ", " << i_interval2 << "]" << std::endl;
	}
}

void interval_add()
{
	double c(0);
	double d(0);

	std::cin >> c >> d;

	if(c > d)
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	else if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 += c;
		i_interval2 += d;
	}
	print_interval();
}

void interval_subtract()
{
	double c(0);
	double d(0);

	std::cin >> c >> d;

	if(c > d)
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	else if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 -= d;
		i_interval2 -= c;
	}
	print_interval();
}

double min(double a, double b, double c, double d)
{
	if(a <= b && a <= c && a <= d)
		return a;
	else if(b <= c && b <= d)
		return b;
	else if(c <= d)
		return c;
	else
		return d;
}

double max(double a, double b, double c, double d)
{
	if(a >= b && a >= c && a >= d)
		return a;
	else if(b >= c && b >= d)
		return b;
	else if(c >= d)
		return c;
	else
		return d;
}

void interval_multiply()
{
	double a(i_interval1);
	double b(i_interval2);
	double c(0);
	double d(0);

	std::cin >> c >> d;

	if(c > d)
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	else if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 = min(a * c, a * d, b * c, b * d);
		i_interval2 = max(a * c, a * d, b * c, b * d);
	}
	print_interval();
}

void interval_divide()
{
	double a(i_interval1);
	double b(i_interval2);
	double c(0);
	double d(0);

	std::cin >> c >> d;

	if(c > d)
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	else if(c < 0 && d > 0)
		print_error();
	else if(i_interval1 != 0 && i_interval2 != 0)
	{
		i_interval1 = min(a / c, a / d, b / c, b / d);
		i_interval2 = max(a / c, a / d, b / c, b / d);
	}
	print_interval();
}

void intersect()
{
	double c(0);
	double d(0);

	std::cin >> c >> d;
	if(c > d)
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	else if(i_interval1 != 0 && i_interval2 != 0)
	{
		if(c > i_interval2 || d < i_interval1)
		{
			i_interval1 = 0;
			i_interval2 = 0;
		}else
		{
			i_interval1 = maximum(i_interval1, c);
			i_interval2 = minimum(i_interval2, d);
		}
	}
	print_interval();
}

double maximum(double a, double b)
{
	if(a >= b)
		return a;
	else
		return b;
}

double minimum(double a, double b)
{
	if(a <= b)
		return a;
	else
		return b;
}

void integers()
{
	int i(0);
	int j = (0);

	i = ceil(i_interval1);
	j = floor(i_interval2);

	if(i != 0 && j != 0)
	{
		while(i < j)
		{
			std::cout << i << ", ";
			++i;
		}
		std::cout << j;
		std::cout << std::endl;
	}
	print_interval();
}

void cartesian_integers()
{
	double c(0);
	double d(0);
	int max(0);
	int min(0);
	int max1(0);
	int min1(0);

	std::cin >> c >> d;
	if(c > d)
	{
		std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
	}
	else
	{
		min = ceil(i_interval1);
		max = floor(i_interval2);
		min1 = ceil(c);
		max1 = floor(d);

		if(i_interval1 != 0 && i_interval2 != 0 )
		{
			for(int i = min; i <= max; ++i)
			{
				for(int j = min1; j <= max1; ++j)
				{
					if(i == max && j == max1)
						std::cout << "(" << i << "," << j << ")";
					else
						std::cout << "(" << i << "," << j << "), ";
				}
			}
			std::cout << std::endl;
		}
	}
	print_interval();
}
