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
			/// \brief Base constructor
			curve3d() = default;
			/// \brief Base destructor
			virtual ~curve3d() = default;
			/// \brief Abstract method used to get point of a certain curve
			/// \param t Parametric float value used to point
			/// \return Value of a point
			virtual tools::point3d get_point(float t) const = 0;
			/// \brief Abstract method used to get vector that represents derivative of a certain curve
			/// \param t Parametric float value used to derivative
			/// \return Value of a derivative
			virtual tools::vector3d get_derivative(float t) const = 0;
			/// \brief Method used to get data of a curve
			/// \return String that contains data about curve
			virtual std::string to_string() const = 0;
		};
	}
}
#endif