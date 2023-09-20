#ifndef CIRCLE_H
#define CIRCLE_H

#include <memory>
#include <ostream>

#include "../curve/curve_3d.h"

namespace curves_library
{
	namespace curves
	{
		class CADEXDLL_API circle final : public curve3d
		{
		private:
			std::unique_ptr<float> radius_;

		public:
			/// \brief Constructor
			explicit circle(float radius);
			/// \brief Copy constructor
			circle(const circle& obj);
			/// \brief Move constructor
			circle(circle&& other) noexcept
				: curve3d(std::move(other)),
				radius_(std::move(other.radius_)) {}
			/// \brief Copy assignent operator
			circle& operator=(circle&& other) noexcept;
			/// \brief Desctructor
			~circle() override = default;

			// Getters
			/// \brief Gets radius of a circle
			float& get_radius() const;
			// Setters
			/// \brief Sets radius of a circle
			void set_radius(float value); 

			// Math-related functions
			/// \brief Gets point of a circle
			/// \param t Parametric float value to get point from
			/// \return Float value of a point at t position
			tools::point3d& get_point(float t) const override;
			/// \brief Gets derivative of a circle
			/// \param t Parametric float value to get derivative from
			/// \return Float value of a derivative at t position
			tools::vector3d& get_derivative(float t) const override;

			// Misc. methods
			/// \brief Represents data about a helix in a string
			/// \return String with data about helix
			std::string to_string() const override;

			// Friend operators
			/// \brief Stream << operator overload, outputs data about circle in to the stream
			/// \param out Parameter for passing stream data
			/// \param circle An object to set data in
			/// \return Stream value filled with data about circle
			friend std::ostream& operator<<(std::ostream& out, const circle& circle)
			{
				out << circle.to_string();
				return out;
			}
			/// \brief Stream >> operator overload
			/// \param in Parameter for passing stream data
			/// \param circle An object to set data in
			/// \return Stream value
			friend std::istream& operator>>(std::istream& in, circle& circle)
			{
				circle.set_radius(in.get());
				return in;
			}
		};
	}
}

#endif 
