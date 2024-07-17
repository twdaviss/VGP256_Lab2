#pragma once
#include "vector"
namespace TMath
{
	struct Vector2 
	{
	private:
		float _magnitude;
		float _angle;
	public:
		float x;
		float y;

		Vector2() { x = 0; y = 0; _magnitude = 0; _angle = 0;}
		Vector2(float magnitude, float degrees) {
			float radians = abs(degrees) * 3.14159 / 180;
			x = cos(radians) * abs(magnitude);
			y = sin(radians) * abs(magnitude);
			_magnitude = abs(magnitude);
			_angle = abs(degrees);
		};

		Vector2& operator*(float& s)
		{
			Vector2 vector;
			vector.x = x * s;
			vector.y = y * s;

			return vector;
		}
		Vector2& operator+(Vector2& v)
		{
			Vector2 vector;
			vector.x = x + v.x;
			vector.y = y + v.y;

			return vector;
		}
		Vector2& operator=(Vector2& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}
		Vector2& operator+=(Vector2& v)
		{
			x = x + v.x;
			y = y + v.y;
			return *this;
		}
		Vector2& operator-(Vector2& v)
		{
			Vector2 vector;
			vector.x = x - v.x;
			vector.y = y - v.y;

			return vector;
		}
		Vector2& operator/(float s)
		{
			Vector2 vector;
			vector.x = x / s;
			vector.y = y / s;

			return vector;
		}
		float magnitude()
		{
			_magnitude = sqrt(pow(x, 2) + pow(y, 2));
			if (_magnitude < 0.00001) {
				return 0;
			}
			return _magnitude;
		}
		float direction()
		{
			_angle = atan2(y, x) * 180 / 3.14159;
			if (_angle < 0.00001) {
				return 0;
			}
			return _angle;
		}
	};

	float Pow(float value, int power);
	Vector2 SumVectors(std::vector<Vector2> vectors);
	std::vector<int> GetDerivative(std::vector<int> polynomial);
	float GetInstantaneousVelocity(std::vector<int> polynomial, int time);
	float GetInstantaneousAcceleration(std::vector<int> polynomial, int time);

	float GetInitialVelocityWithAcceleration(float finalVelocity, float acceleration, float time);
	float GetInitialVelocityWithDisplacement(float finalVelocity, float displacement, float time);
	float GetInitialVelocityWithAverage(float finalVelocity, float averageVelocity);

	float GetFinalVelocityWithAcceleration(float initialVelocity, float acceleration, float time);
	float GetFinalVelocityWithDisplacement(float initialVelocity, float displacement, float time);
	float GetFinalVelocityWithAverage(float initialVelocity, float averageVelocity);

	float GetAccelerationWithFinal(float initialVelocity, float finalVelocity, float time);
	float GetAccelerationWithDisplacement(float initialVelocity, float displacement, float time);
	float GetAccelerationWithDisplacementAndFinal(float initialVelocity, float finalVelocity, float displacement);

	float GetDisplacementWithTime(float initialVelocity, float finalVelocity, float time);
	float GetDisplacementWithAcceleration(float initialVelocity, float finalVelocity, float acceleration);
	
	float GetTimeWithAcceleration(float initalVelocity, float finalVelocity, float acceleration);
	float GetTimeWithDisplacement(float initalVelocity, float finalVelocity, float displacement);
}