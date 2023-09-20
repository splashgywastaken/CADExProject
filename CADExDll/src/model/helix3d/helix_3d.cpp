#include "pch.h"
#include "helix_3d.h"
using namespace curves_library;

curves::helix3d::helix3d(float radius, float step)
{
	radius_ = std::make_unique<float>(radius);
	step_ = std::make_unique<float>(step);
}

curves::helix3d::helix3d(const helix3d& other)
{
}

curves::helix3d& curves::helix3d::operator=(helix3d&& other) noexcept
{
	if (this == &other)
		return *this;
	curve3d::operator =(std::move(other));
	radius_ = std::move(other.radius_);
	step_ = std::move(other.step_);
	return *this;
}

float curves::helix3d::get_radius() const
{
	return *radius_;
}

float curves::helix3d::get_step() const
{
	return *step_;
}

void curves::helix3d::set_radius(float radius)
{
	if (radius_ != nullptr)
	{
		*radius_ = radius;
		return;
	}
	radius_ = std::make_unique<float>(radius);
}

void curves::helix3d::set_step(float step)
{
	if (step_ != nullptr)
	{
		*step_ = step;
		return;
	}
	step_ = std::make_unique<float>(step);
}

tools::point3d& curves::helix3d::get_point(float t) const
{
	auto point = tools::point3d(
		*radius_ * cos(t),
		*radius_ * sin(t),
		*step_ * t
	);
	return point;
}

tools::vector3d& curves::helix3d::get_derivative(float t) const
{
	auto vector = tools::vector3d(
		-*radius_ * sin(t),
		*radius_ * cos(t),
		*step_
	);
	return vector;
}

std::string curves::helix3d::to_string() const
{
	return "Helix (radius = " + std::to_string(get_radius()) + ", step = " + std::to_string(get_step()) + ")";
}
