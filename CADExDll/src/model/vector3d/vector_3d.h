
#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "../../../global.h"
#include <memory>
#include <ostream>

namespace curves_library
{
	namespace tools
	{
		class vector3d
		{
		private:
			std::unique_ptr<float> x_, y_, z_;
		public:
			/// \brief Constructor
			CADEXDLL_API explicit vector3d(
				float x = .0f,
				float y = .0f,
				float z = .0f
			);
			/// \brief Copy constructor
			CADEXDLL_API vector3d(const vector3d& vector);
			/// \brief Move constructor
			CADEXDLL_API vector3d(vector3d&& other) noexcept
				: x_(std::move(other.x_)),
				y_(std::move(other.y_)),
				z_(std::move(other.z_))
			{}
			/// \brief Copy assignent operator
			CADEXDLL_API vector3d& operator=(vector3d&& other) noexcept;

			// Getters
			/// \brief Gets x value of a vector
			CADEXDLL_API float& get_x() const;
			/// \brief Gets y value of a vector
			CADEXDLL_API float& get_y() const;
			/// \brief Gets z value of a vector
			CADEXDLL_API float& get_z() const;
			// Setters
			/// \brief Sets x value for a vector
			CADEXDLL_API void set_x(float value);
			/// \brief Sets y value for a vector
			CADEXDLL_API void set_y(float value);
			/// \brief Sets z value for a vector
			CADEXDLL_API void set_z(float value);

			// Friend operators
			/// \brief Stream << operator overload, outputs data about vector in to the stream
			/// \param out Parameter for passing stream data
			/// \param vector An object to set data in
			/// \return Stream value filled with data about vector
			CADEXDLL_API friend std::ostream& operator << (std::ostream& out, const vector3d& vector)
			{
				out << "(" << *vector.x_ << ";" << *vector.y_ << ";" << *vector.z_ << ")";
				return out;
			}
		};
	}

}

#endif 