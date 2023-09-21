#ifndef POINT_3D_H
#define POINT_3D_H

#include "../../../global.h"
#include <memory>
#include <ostream>

namespace curves_library
{
	namespace tools
	{
		class point3d
		{
		private:
			std::unique_ptr<float> x_, y_, z_;
		public:
			/// \brief Constructor
			CADEXDLL_API explicit point3d(
				float x = .0f,
				float y = .0f,
				float z = .0f
			);
			/// \brief Copy constructor
			CADEXDLL_API point3d(const point3d& point);
			/// \brief Move constructor
			CADEXDLL_API point3d(point3d&& other) noexcept
				: x_(std::move(other.x_)),
				  y_(std::move(other.y_)),
				  z_(std::move(other.z_))
			{
			}
			/// \brief Copy assignent operator
			CADEXDLL_API point3d& operator=(point3d&& other) noexcept;
			/// \brief Desctructor
			CADEXDLL_API ~point3d() = default;

			// Getters
			/// \brief Gets x value of a point
			CADEXDLL_API float& get_x() const;
			/// \brief Gets y value of a point
			CADEXDLL_API float& get_y() const;
			/// \brief Gets z value of a point
			CADEXDLL_API float& get_z() const;
			// Setters
			/// \brief Sets x value for a point
			CADEXDLL_API void set_x(float value);
			/// \brief Sets y value for a point
			CADEXDLL_API void set_y(float value);
			/// \brief Sets z value for a point
			CADEXDLL_API void set_z(float value);

			// Friend operators
			/// \brief Stream << operator overload, outputs data about point in to the stream
			/// \param out Parameter for passing stream data
			/// \param point An object to set data in
			/// \return Stream value filled with data about point
			CADEXDLL_API friend std::ostream& operator<< (std::ostream& out, const point3d& point)
			{
				out << "( " << point.get_x() << "; " << point.get_y() << "; " << point.get_z() << ")";
				return out;
			}
		};
	}
}

#endif