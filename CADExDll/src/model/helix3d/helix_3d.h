#ifndef HELIX_3D_H
#define HELIX_3D_H

#include "../../../global.h"
#include "../curve/curve_3d.h"

namespace curves_library
{
	namespace curves
	{
		class helix3d final : public curve3d
		{
		private:
			std::unique_ptr<float> radius_, step_;
		public:
			/// \brief Constructor
			CADEXDLL_API helix3d(float radius, float step);
			/// \brief Copy constructor
			CADEXDLL_API helix3d(const helix3d& other);
			/// \brief Move constructor
			CADEXDLL_API helix3d(helix3d&& other) noexcept
				: curve3d(std::move(other)),
				  radius_(std::move(other.radius_)),
				  step_(std::move(other.step_)) {}
			/// \brief Copy assignent operator
			CADEXDLL_API helix3d& operator=(helix3d&& other) noexcept;
			/// \brief Desctructor
			CADEXDLL_API ~helix3d() override = default;

			// Getters
			/// \brief Gets radius of a helix
			CADEXDLL_API float get_radius() const;
			/// \brief Gets step of a helix
			CADEXDLL_API float get_step() const;
			// Setters
			/// \brief Sets radius of a helix
			CADEXDLL_API void set_radius(float radius);
			/// \brief Sets step of a helix
			CADEXDLL_API void set_step(float step);

			// Math-related functions
			/// \brief Gets point of a helix
			/// \param t Parametric float value to get point from
			/// \return Float value of a point at t position
			CADEXDLL_API tools::point3d get_point(float t) const override;
			/// \brief Gets derivative of a helix
			/// \param t Parametric float value to get derivative from
			/// \return Float value of a derivative at t position
			CADEXDLL_API tools::vector3d get_derivative(float t) const override;

			// Misc. methods
			/// \brief Represents data about a helix in a string
			/// \return String with data about helix
			CADEXDLL_API std::string to_string() const override;

			// Friend operators
			/// \brief Stream << operator overload, outputs data about helix in to the stream
			/// \param out Parameter for passing stream data
			/// \param helix An object to set data in
			/// \return Stream value filled with data about helix
			CADEXDLL_API friend std::ostream& operator<<(std::ostream& out, const helix3d& helix)
			{
				out << helix.to_string();
				return out;
			}
		};
	}
}


#endif // !HELIX_3D_H


