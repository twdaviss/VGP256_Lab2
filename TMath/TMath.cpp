#include "TMath.h"

TMath::Vector2 TMath::SumVectors(std::vector<Vector2> vectors)
{
	TMath::Vector2 sumVector;
	for (int i = 0; i < vectors.size(); i++) {
		sumVector += vectors.at(i);
	}
	return sumVector;
}
std::vector<int> TMath::GetDerivative(std::vector<int> polynomial)
{
	std::vector<int> derivativePolynomial(10);
	for (int i = polynomial.size()-1; i >= 1; i--)
	{
		int value = polynomial[i];
		if (value == 0)
		{
			continue;
		}
		if (i == 1)
		{
			derivativePolynomial[i - 1] = value;
			continue;
		}
		if (value < 0)
		{
			value *= -1;
			derivativePolynomial[i-1] = -i * value;
			continue;
		}
		derivativePolynomial[i - 1] = i * value;
	}
	return derivativePolynomial;
}

float TMath::GetInstantaneousVelocity(std::vector<int> polynomial, int time)
{
	std::vector<int> derivativePolynomial = GetDerivative(polynomial);

	float velocity = 0;
	for (int i = derivativePolynomial.size()-1; i >= 0; i--)
	{
		int value = derivativePolynomial[i];
		if (value == 0)
		{
			continue;
		}
		if (value < 0)
		{
			value *= -1;
			velocity += - value * Pow(time, i);
			continue;
		}
		velocity += value * Pow(time, i);
	}
	return velocity;
}

float TMath::GetInstantaneousAcceleration(std::vector<int> polynomial, int time)
{
	std::vector<int> derivativePolynomial = GetDerivative(GetDerivative(polynomial));

	float acceleration = 0;
	for (int i = derivativePolynomial.size() - 1; i >= 0; i--)
	{
		int value = derivativePolynomial[i];
		if (value == 0)
		{
			continue;
		}
		if (value < 0)
		{
			value *= -1;
			acceleration += -value * Pow(time, i);
			continue;
		}
		acceleration += value * Pow(time, i);
	}
	return acceleration;
}

float TMath::Pow(float value, int power)
{
	if (power == 1) {
		return value;
	}
	if (power == 0)
	{
		return 1;
	}
	for (int i = power; i > 1; i--)
	{
		value *= value;
	}
	return value;
}

float TMath::GetInitialVelocityWithAcceleration(float finalVelocity, float acceleration, float time)
{
	return (acceleration * time) - finalVelocity;
}

float TMath::GetInitialVelocityWithDisplacement(float finalVelocity, float displacement, float time)
{
	return (2.0f * displacement / time) - finalVelocity;
}

float TMath::GetInitialVelocityWithAverage(float finalVelocity, float averageVelocity)
{
	return (2.0f * averageVelocity) - finalVelocity;
}

float TMath::GetFinalVelocityWithAcceleration(float initialVelocity, float acceleration, float time)
{
	return initialVelocity + (acceleration * time);
}

float TMath::GetFinalVelocityWithDisplacement(float initialVelocity, float displacement, float time)
{
	return (2.0f * displacement / time) - initialVelocity;
}

float TMath::GetFinalVelocityWithAverage(float initialVelocity, float averageVelocity)
{
	return (2.0f * averageVelocity) - initialVelocity;
}

float TMath::GetAccelerationWithFinal(float initialVelocity, float finalVelocity, float time)
{
	return (finalVelocity - initialVelocity)/time;
}

float TMath::GetAccelerationWithDisplacement(float initialVelocity, float displacement, float time)
{
	return (displacement - (initialVelocity * time)) / 2.0f * (Pow(time, 2));
}
float TMath::GetAccelerationWithDisplacementAndFinal(float initialVelocity, float finalVelocity, float displacement)
{
	return (Pow(finalVelocity, 2) - Pow(initialVelocity, 2)) / (2.0f * displacement);
}

float TMath::GetDisplacementWithTime(float initialVelocity, float finalVelocity, float time)
{
	return (time * (initialVelocity + finalVelocity)) / 2.0f;
}

float TMath::GetDisplacementWithAcceleration(float initialVelocity, float finalVelocity, float acceleration)
{
	return (Pow(finalVelocity, 2) - Pow(initialVelocity, 2)) / (2.0f * acceleration);
}

float TMath::GetTimeWithAcceleration(float initalVelocity, float finalVelocity, float acceleration)
{
	return (finalVelocity - initalVelocity / acceleration);
}

float TMath::GetTimeWithDisplacement(float initalVelocity, float finalVelocity, float displacement)
{
	return (2.0f * displacement) / (initalVelocity + finalVelocity);
}