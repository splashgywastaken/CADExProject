#ifndef CURVE_3D_H
#define CURVE_3D_H
#include <string>

#include "../../../global.h"
#include "../point3d/point_3d.h"
#include "../vector3d/vector_3d.h"

namespace curves_library
{
	namespace curves
	{
		class CADEXDLL_API curve3d
		{
		public:
			curve3d() = default;
			virtual ~curve3d() = default;

			virtual tools::point3d get_point(float t) const = 0;

			virtual tools::vector3d get_derivative(float t) const = 0;

			virtual std::string to_string() const = 0;
		};
	}
}
#endif