#include <iostream>
#include "TMath.h"
int main()
{
	bool stop = false;
	float input = 0;
	float mass;
	TMath::Vector2 force;
	std::vector<TMath::Vector2> forces;
	std::cout << "Welcome to Taylor's Forces to Acceleration Calculator!\n";

	while (input <= 0)
	{
		std::cout << "Please input the mass of the object in Kg\n";
		std::cin >> input;
		if (input <= 0) {
			system("cls");
			std::cout << "Mass cannot be negative. Please enter a valid input\n";
		}
		mass = input;
	}

	system("cls");
	input = 2;
	
	while (input != 0 && input != 1)
	{
		std::cout << "Do you want to use components or magnitude and direction?\nEnter 0 for components, Enter 1 for mangnitude/direction\n";
		std::cin >> input;
		if (input != 0 && input != 1) {
			system("cls");
			std::cout << "Please enter a valid input\n";
		}
	}

	system("cls");

	if (input == 0)
	{
		while (!stop)
		{
			std::cout << "Please input the horizontal (x) component of the force\n";
			std::cin >> force.x;
			std::cout << "Please input the vertical (y) component of the force\n";
			std::cin >> force.y;

			forces.push_back(force);

			system("cls");
			std::cout << "Would you like to add another force?\nEnter 0 for yes, Enter 1 for no\n";
			std::cin >> input;
			if (input == 1)
			{
				stop = true;
			}
		}
	}
	else if (input == 1)
	{
		while (!stop)
		{
			float magnitude;
			float degrees;
			std::cout << "Please input the magnitude of the force\n";
			std::cin >> magnitude;
			std::cout << "Please input the direction of the force in degrees\n";
			std::cin >> degrees;
			TMath::Vector2 newVector(magnitude, degrees);
			force = newVector;
			forces.push_back(force);

			system("cls");
			std::cout << "Would you like to add another force?\nEnter 0 for yes, Enter 1 for no\n";
			std::cin >> input;
			if (input == 1)
			{
				stop = true;
			}
		}
	}

	system("cls");

	TMath::Vector2 netForce = TMath::SumVectors(forces);
	TMath::Vector2 acceleration = netForce / mass;
	float angle = netForce.direction();
	std::cout << "The net force acting on the object is " << netForce.magnitude() << " N at " << angle << " degrees" << "(" << (int)netForce.x << ", " << (int)netForce.y << ")" << std::endl;
	std::cout << "Since its mass is " << mass << " Kg, the acceleration due to the acting forces is " << acceleration.magnitude() << " m/s^2 at " << acceleration.direction() << " degrees" << "(" << (int)acceleration.x << ", " << (int)acceleration.y << ")" << std::endl;
	system("pause");
}
