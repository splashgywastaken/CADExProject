// SplinesProject.cpp : Defines the entry point for the application.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <mutex>
#include <random>
#include <vector>
#include <omp.h>

#include "curves_library.h"

// Usings
using namespace curves_library::curves;

// typedefs
typedef std::shared_ptr<curve3d> shared_curve_ptr;
typedef std::shared_ptr<circle> shared_circle_ptr;
typedef std::vector<shared_curve_ptr> shared_curves_vector;
typedef std::vector<shared_circle_ptr> shared_circles_vector;

// Predefenitions for functions 
std::mutex rand_mutex;
/**
 * \brief A thread-safe function that returns a random integer in [min, max]
 * \param min Min int value
 * \param max Max int value
 * \return Int value that generated through normal distribution
 */
int rand_int_safe(int min, int max);
/**
 * \brief A thread-safe function that returns a random float in [min, max]
 * \param min Min float value
 * \param max Max float value
 * \return Float value that generated through normal distribution
 */
float rand_float_safe(float min, float max);
/**
 * \brief A function that randomly populates vector with curves
 * \param vector /An initialized vector that will be populated with curves
 * \param amount Number of curves that vector will be populated with
 */
void populate_vector(const std::unique_ptr<shared_curves_vector>& vector, const int& amount);
/**
 * \brief Function used to output data about elements in vector:
 * \n1. Fields data
 * \n2. Points in t time
 * \n3. Derivatives in t time
 * \param vector_name String used as a "header" for output
 * \param vector const std::unique_ptr<shared_curves_vector>& vector populated with curves
 * \param t Float value to get points and derivatives
 */
void output_curves_data(
	const std::string& vector_name,
	const std::unique_ptr<shared_curves_vector>& vector,
	const float& t
);
/**
 * \brief Function used to output data about circles in vector - Fields data
 * \param vector_name String used as a "header" for output
 * \param vector const std::unique_ptr<shared_circles_vector>& vector populated with curves
 */
void output_circles_data(
	const std::string& vector_name,
	const std::unique_ptr<shared_circles_vector>& vector
);
/**
 * \brief Moves circles from vector curve_vector to circle_vector if they are initialized as circle class
 * \param curve_vector Vector populated with curves
 * \param circle_vector An empty vector that will be populated with circles
 */
void move_circles_to_second_vector(
	const std::unique_ptr<shared_curves_vector>& curve_vector,
	const std::unique_ptr<shared_circles_vector>& circle_vector
);
/**
 * \brief Function that calculates sum of radii of circles that are in vector, uses OpenMP to paralellize for loop
 * \param circles const std::unique_ptr<shared_circles_vector>& vector contatinig pointers to circles instances
 * \return Float value of sum
 */
float get_radii_sum(const std::unique_ptr<shared_circles_vector>& circles);

int main()
{
	int curves_amount = 0;
	std::cout << "How much curves do you want to generate?" << std::endl;
	std::cin >> curves_amount;

	const auto curves = std::make_unique<shared_curves_vector>(shared_curves_vector());
	// Randomly adding [curves_amount] of elements to curves vector
	populate_vector(curves, curves_amount);
	// Otputing data about curves's derivatives and points at t=pi/4 value
	output_curves_data("First vector", curves, 0.25f * static_cast<float>(M_PI));

	const auto circles = std::make_unique<shared_circles_vector>(shared_circles_vector());
	// Moving circles from curves vector to circles only vector
	move_circles_to_second_vector(curves, circles);
	output_circles_data("Circles before sort", circles);
	// Sorting elements in circles vector using predicates
	std::sort(
		circles->begin(),
		circles->end(),
		[](const shared_circle_ptr& a, const shared_circle_ptr& b)
		{
			return a->get_radius() < b->get_radius();
		}
	);
	output_circles_data("Circles after sort", circles);
	//// Getting a sum of radii
	const float radii_sum = get_radii_sum(circles);
	std::cout << "Sum of circles radii: " << radii_sum;

	return EXIT_SUCCESS;
}

void populate_vector(const std::unique_ptr<shared_curves_vector>& vector, const int& amount)
{
	for (int i = 0; i < amount; i++)
	{
		// Gets a value
		// which then is used to decide which curve to add into a vector
		const int choice = rand_int_safe(1, 3);
		// A ptr to curve
		shared_curve_ptr curve;
		switch (choice)
		{
		case 1:
			// Adds circle
			curve = std::make_shared<circle>(circle(
				static_cast<float>(rand_float_safe(1, 10))
			));
			break;
		case 2:
			// Adds ellipse
			curve = std::make_shared<ellipse>(ellipse(
				static_cast<float>(rand_float_safe(1, 10)),
				static_cast<float>(rand_float_safe(1, 10))
			));
			break;
		case 3:
			// Adds helix3d
			curve = std::make_shared<helix3d>(helix3d(
				static_cast<float>(rand_float_safe(1, 10)),
				static_cast<float>(rand_float_safe(1, 10))
			));
			break;
		default:
			// Do nothing 
			;
		}
		// pushes curves into a vector
		vector->push_back(std::move(curve));
	}
}

void move_circles_to_second_vector(
	const std::unique_ptr<shared_curves_vector>& curve_vector,
	const std::unique_ptr<shared_circles_vector>& circle_vector
)
{
	for (const auto& curve : *curve_vector)
	{
		if (std::dynamic_pointer_cast<circle>(curve))
		{
			circle_vector->push_back(std::dynamic_pointer_cast<circle>(curve));
		}
	}
}

float get_radii_sum(const std::unique_ptr<shared_circles_vector>& circles)
{
	const int n = circles->size();
	float sum = .0f;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < n; i++)
	{
		sum += circles->at(i)->get_radius();
	}
	return sum;
}

void output_curves_data(
	const std::string& vector_name,
	const std::unique_ptr<shared_curves_vector>& vector,
	const float& t
)
{
	using namespace std;
	cout << "Printing out curves from " << vector_name << endl;
	int counter = 0;
	for (const auto& el : *vector)
	{
		cout << "[" << ++counter << "] ";
		cout << el->to_string() << " Point:\t";
		cout << el->get_point(t);
		cout << ";\tDerivative:\t";
		cout << el->get_derivative(t) << "\n";
	}
}

void output_circles_data(
	const std::string& vector_name,
	const std::unique_ptr<shared_circles_vector>& vector
)
{
	using namespace std;
	cout << "Printing out curves from " << vector_name << endl;
	int counter = 0;
	for (const auto& el : *vector)
	{
		cout << "[" << ++counter << "] ";
		cout << el->to_string() << "\n";
	}
}

int rand_int_safe(const int min, const int max) {
	// Lock the mutex
	std::lock_guard<std::mutex> lock(rand_mutex);
	// Create a static random engine
	static std::default_random_engine engine(std::random_device{}());
	// Create a uniform distribution in [min, max]
	std::uniform_int_distribution<int> dist(min, max);
	// Return a random number from the distribution
	return dist(engine);
}

float rand_float_safe(const float min, const float max) {
	// Lock the mutex
	std::lock_guard<std::mutex> lock(rand_mutex);
	// Create a static random engine
	static std::default_random_engine engine(std::random_device{}());
	// Create a uniform distribution in [min, max]
	std::uniform_real_distribution<float> dist(min, max);
	// Return a random number from the distribution
	return dist(engine);
}