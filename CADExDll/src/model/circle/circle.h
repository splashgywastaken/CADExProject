#ifndef CIRCLE_H
#define CIRCLE_H
#include <memory>
#include <ostream>

#include "../../../global.h"
#include "../curve/curve_3d.h"

namespace curves_library
{
	namespace curves
	{
		class circle final : public curve3d
		{
		private:
			std::unique_ptr<float> radius_;

		public:
			/// \brief Constructor
			CADEXDLL_API explicit circle(float radius);
			/// \brief Copy constructor
			CADEXDLL_API circle(const circle& obj);
			/// \brief Move constructor
			CADEXDLL_API circle(circle&& other) noexcept
				: curve3d(std::move(other)),
				radius_(std::move(other.radius_)) {}
			/// \brief Copy assignent operator
			CADEXDLL_API circle& operator=(circle&& other) noexcept;
			/// \brief Desctructor
			CADEXDLL_API ~circle() override = default;

			// Getters
			/// \brief Gets radius of a circle
			CADEXDLL_API float& get_radius() const;
			// Setters
			/// \brief Sets radius of a circle
			CADEXDLL_API void set_radius(float value);

			// Math-related functions
			/// \brief Gets point of a circle
			/// \param t Parametric float value to get point from
			/// \return Float value of a point at t position
			CADEXDLL_API tools::point3d get_point(float t) const override;
			/// \brief Gets derivative of a circle
			/// \param t Parametric float value to get derivative from
			/// \return Float value of a derivative at t position
			CADEXDLL_API tools::vector3d get_derivative(float t) const override;

			// Misc. methods
			/// \brief Represents data about a helix in a string
			/// \return String with data about helix
			CADEXDLL_API std::string to_string() const override;

			// Friend operators
			/// \brief Stream << operator overload, outputs data about circle in to the stream
			/// \param out Parameter for passing stream data
			/// \param circle An object to set data in
			/// \return Stream value filled with data about circle
			CADEXDLL_API friend std::ostream& operator<<(std::ostream& out, const circle& circle)
			{
				out << circle.to_string();
				return out;
			}
		};
	}
}

#endif 
