#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "../curve/curve_3d.h"

namespace curves_library
{
	namespace curves
	{
		class CADEXDLL_API ellipse final : public curve3d
		{
		private:
			std::unique_ptr<float> radiix_, radiiy_;
		public:
			// Constructors
			ellipse(float radiix, float radiiy);
			// Copy constructor
			ellipse(ellipse& other);
			// Copy and move operations
			ellipse(ellipse&& other) noexcept
				: curve3d(std::move(other)),
				radiix_(std::move(other.radiix_)),
				radiiy_(std::move(other.radiiy_)) {}
			ellipse& operator=(ellipse&& other) noexcept;
			~ellipse() override = default;

			// Getters
			/// \brief Gets radiix of an ellipse
			float get_radiix() const;
			/// \brief Gets radiiy of an ellipse
			float get_radiiy() const;
			// Setters
			/// \brief Sets radiix of an ellipse
			void set_radiix(float value);
			/// \brief Sets radiiy of an ellipse
			void set_radiiy(float value);

			// Math-related functions
			/// \brief Gets point of an ellipse
			/// \param t Parametric float value to get point from
			/// \return Float value of a point at t position
			tools::point3d& get_point(float t) const override;
			/// \brief Gets derivative of an ellipse
			/// \param t Parametric float value to get derivative from
			/// \return Float value of a derivative at t position
			tools::vector3d& get_derivative(float t) const override;

			// Misc. methods
			/// \brief Represents data about an ellipse in a string
			/// \return String with data about ellipse
			std::string to_string() const override;

			// Friend operators
			/// \brief Stream << operator overload, outputs data about ellipse in to the stream
			/// \param out Parameter for passing stream data
			/// \param ellipse An object to set data in
			/// \return Stream value filled with data about ellipse
			friend std::ostream& operator<<(std::ostream& out, const ellipse& ellipse)
			{
				out << ellipse.to_string();
				return out;
			}

			// Friend operators
			/// \brief Stream << operator overload, outputs data about ellipse in to the stream
			/// \param in Parameter for passing stream data
			/// \param ellipse An object to set data in
			/// \return Stream value filled with data about ellipse
			friend std::istream& operator>>(std::istream& in, ellipse& ellipse)
			{
				ellipse.set_radiix(in.get());
				ellipse.set_radiiy(in.get());
				return in;
			}
		};
	}
}


#endif // !ELLIPSE_H
