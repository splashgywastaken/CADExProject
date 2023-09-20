#include "pch.h"
#include "circle.h"
using namespace curves_library;

curves::circle& curves::circle::operator=(circle&& other) noexcept
{
	if (this == &other)
		return *this;
	curve3d::operator =(std::move(other));
	radius_ = std::move(other.radius_);
	return *this;
}

curves::circle::circle(float radius)
{
	radius_ = std::make_unique<float>(radius);
}

curves::circle::circle(const circle& obj)
{
	radius_ = std::make_unique<float>(*obj.radius_);
}

float& curves::circle::get_radius() const
{
	return *radius_;
}

void curves::circle::set_radius(float value)
{
	radius_ = std::make_unique<float>(value);
}

tools::point3d& curves::circle::get_point(float t) const
{
	auto point = tools::point3d(
		*radius_ * cos(t),
		*radius_ * sin(t),
		.0f
	);
	return point;
}

tools::vector3d& curves::circle::get_derivative(float t) const
{
	auto vector = tools::vector3d(
		-*radius_ * sin(t),
		*radius_ * cos(t),
		.0f
	);
	return vector;
}

std::string curves::circle::to_string() const
{
	return "Circle (radius = " + std::to_string(get_radius()) + ")";
}
