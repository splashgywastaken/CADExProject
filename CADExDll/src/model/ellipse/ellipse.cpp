#include "pch.h"
#include "ellipse.h"

using namespace curves_library;

curves::ellipse::ellipse(float radiix, float radiiy)
{
	radiix_ = std::make_unique<float>(radiix);
	radiiy_ = std::make_unique<float>(radiiy);
}

curves::ellipse::ellipse(const ellipse& other)
{
	radiix_ = std::make_unique<float>(other.get_radiix());
	radiiy_ = std::make_unique<float>(other.get_radiiy());
}

curves::ellipse& curves::ellipse::operator=(ellipse&& other) noexcept
{
	if (this == &other)
		return *this;
	curve3d::operator =(std::move(other));
	radiix_ = std::move(other.radiix_);
	radiiy_ = std::move(other.radiiy_);
	return *this;
}

float curves::ellipse::get_radiix() const
{
	return *radiix_;
}

float curves::ellipse::get_radiiy() const
{
	return *radiiy_;
}

void curves::ellipse::set_radiix(float value)
{
	radiix_ = std::make_unique<float>(value);
}

void curves::ellipse::set_radiiy(float value)
{
	radiiy_ = std::make_unique<float>(value);
}

tools::point3d curves::ellipse::get_point(const float t) const
{
	return tools::point3d(
		*radiix_ * cos(t),
		*radiiy_ * sin(t),
		0
	);
}

tools::vector3d curves::ellipse::get_derivative(const float t) const
{
	return tools::vector3d(
		-*radiix_ * sin(t),
		*radiiy_ * cos(t),
		0
	);
}

std::string curves::ellipse::to_string() const
{
	return "Ellipse (radiix = " + std::to_string(get_radiix()) + ", radiiy = " + std::to_string(get_radiiy()) + ")";
}
