#include "pch.h"
#include "point_3d.h"

using namespace curves_library;

tools::point3d::point3d(float x, float y, float z)
{
	x_ = std::make_unique<float>(x);
	y_ = std::make_unique<float>(y);
	z_ = std::make_unique<float>(z);
}

tools::point3d::point3d(const point3d& point)
{
	x_ = std::make_unique<float>(point.get_x());
	y_ = std::make_unique<float>(point.get_y());
	z_ = std::make_unique<float>(point.get_z());
}

tools::point3d& tools::point3d::operator=(point3d&& other) noexcept
{
	if (this == &other)
		return *this;
	x_ = std::move(other.x_);
	y_ = std::move(other.y_);
	z_ = std::move(other.z_);
	return *this;
}

float& tools::point3d::get_x() const
{
	return *x_;
}

float& tools::point3d::get_y() const
{
	return *y_;
}

float& tools::point3d::get_z() const
{
	return *z_;
}

void tools::point3d::set_x(float value)
{
	x_ = std::make_unique<float>(value);
}

void tools::point3d::set_y(float value)
{
	y_ = std::make_unique<float>(value);
}

void tools::point3d::set_z(float value)
{
	z_ = std::make_unique<float>(value);
}
