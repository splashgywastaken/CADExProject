#include "pch.h"
#include "vector_3d.h"
using namespace curves_library;

tools::vector3d::vector3d(float x, float y, float z)
{
	x_ = std::make_unique<float>(x);
	y_ = std::make_unique<float>(y);
	z_ = std::make_unique<float>(z);
}

tools::vector3d::vector3d(const vector3d& vector)
{
	x_ = std::make_unique<float>(vector.get_x());
	y_ = std::make_unique<float>(vector.get_y());
	z_ = std::make_unique<float>(vector.get_z());
}

tools::vector3d& tools::vector3d::operator=(vector3d&& other) noexcept
{
	if (this == &other)
		return *this;
	x_ = std::move(other.x_);
	y_ = std::move(other.y_);
	z_ = std::move(other.z_);
	return *this;
}

float& tools::vector3d::get_x() const
{
	return *x_;
}

float& tools::vector3d::get_y() const
{
	return *y_;
}

float& tools::vector3d::get_z() const
{
	return *z_;
}

void tools::vector3d::set_x(float value)
{
	x_ = std::make_unique<float>(value);
}

void tools::vector3d::set_y(float value)
{
	y_ = std::make_unique<float>(value);
}

void tools::vector3d::set_z(float value)
{
	z_ = std::make_unique<float>(value);
}