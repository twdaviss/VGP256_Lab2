#include <iostream>
#include "TMath.h"
#include <string>
using namespace TMath;

static void PrintPolynomial(std::vector<int> polynomial, int degree)
{
    std::cout << "f(x) = ";
    for (int i = degree; i >= 0; i--)
    {
        int value = polynomial[i];

        if (i == degree)
        {
            std::cout << value << "x^" << i;
            continue;
        }
        else if (i == 0 && value < 0)
        {
            value = polynomial[i] * -1;
            std::cout << " - " << value;
            continue;
        }
        else if (i == 0) {
            std::cout << " + " << value;
            continue;
        }
        else if (value < 0)
        {
            value = polynomial[i] * -1;
            std::cout << " - " << value << "x^" << i;
            continue;
        }

        std::cout << " + " << value << "x^" << i;
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    int degree;
    std::vector<int> polynomial(10);
    std::cout << "What is the highest degree of the polynomial?" << std::endl;
    std::cin >> degree;
    for (int i = degree; i >= 0; i--)
    {
        std::cout << "Please enter the coefficient(+/-) for the term with degree: " << i << " (Enter 0 if there are none)." << std::endl;
        std::cin >> polynomial[i];
    }
    PrintPolynomial(polynomial, degree);

    std::cout << "What time would you like to check for velocity and acceleration?" << std::endl;

    int time;
    std::cin >> time;
    std::cout << "Velocity at time t = " << time << ": " << GetInstantaneousVelocity(polynomial, time) << "\nAcceleration at time t = " << time << ": " << GetInstantaneousAcceleration(polynomial, time) << std::endl;

    system("pause");
}