#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "../../../global.h"
#include "../curve/curve_3d.h"

namespace curves_library
{
	namespace curves
	{
		class ellipse final : public curve3d
		{
		private:
			std::unique_ptr<float> radiix_, radiiy_;
		public:
			// Constructors
			CADEXDLL_API ellipse(float radiix, float radiiy);
			// Copy constructor
			CADEXDLL_API ellipse(const ellipse& other);
			// Copy and move operations
			CADEXDLL_API ellipse(ellipse&& other) noexcept
				: curve3d(std::move(other)),
				radiix_(std::move(other.radiix_)),
				radiiy_(std::move(other.radiiy_)) {}
			CADEXDLL_API ellipse& operator=(ellipse&& other) noexcept;
			CADEXDLL_API ~ellipse() override = default;

			// Getters
			/// \brief Gets radiix of an ellipse
			CADEXDLL_API float get_radiix() const;
			/// \brief Gets radiiy of an ellipse
			CADEXDLL_API float get_radiiy() const;
			// Setters
			/// \brief Sets radiix of an ellipse
			CADEXDLL_API void set_radiix(float value);
			/// \brief Sets radiiy of an ellipse
			CADEXDLL_API void set_radiiy(float value);

			// Math-related functions
			/// \brief Gets point of an ellipse
			/// \param t Parametric float value to get point from
			/// \return Float value of a point at t position
			CADEXDLL_API tools::point3d get_point(float t) const override;
			/// \brief Gets derivative of an ellipse
			/// \param t Parametric float value to get derivative from
			/// \return Float value of a derivative at t position
			CADEXDLL_API tools::vector3d get_derivative(float t) const override;

			// Misc. methods
			/// \brief Represents data about an ellipse in a string
			/// \return String with data about ellipse
			CADEXDLL_API std::string to_string() const override;

			// Friend operators
			/// \brief Stream << operator overload, outputs data about ellipse in to the stream
			/// \param out Parameter for passing stream data
			/// \param ellipse An object to set data in
			/// \return Stream value filled with data about ellipse
			CADEXDLL_API friend std::ostream& operator<<(std::ostream& out, const ellipse& ellipse)
			{
				out << ellipse.to_string();
				return out;
			}
		};
	}
}


#endif // !ELLIPSE_H
