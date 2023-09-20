#ifndef POINT3D_H
#define POINT3D_H
#include <memory>
#include <ostream>
#include <istream>

namespace curves_library
{
	namespace tools
	{
		class CADEXDLL_API point3d
		{
		private:
			std::unique_ptr<float> x_, y_, z_;
		public:
			/// \brief Constructor
			explicit point3d(
				float x = .0f,
				float y = .0f,
				float z = .0f
			);
			/// \brief Copy constructor
			point3d(const point3d& point);
			/// \brief Move constructor
			point3d(point3d&& other) noexcept
				: x_(std::move(other.x_)),
				  y_(std::move(other.y_)),
				  z_(std::move(other.z_))
			{
			}
			/// \brief Copy assignent operator
			point3d& operator=(point3d&& other) noexcept;
			/// \brief Desctructor
			~point3d() = default;

			// Getters
			/// \brief Gets x value of a point
			float& get_x() const;
			/// \brief Gets y value of a point
			float& get_y() const;
			/// \brief Gets z value of a point
			float& get_z() const;
			// Setters
			/// \brief Sets x value for a point
			void set_x(float value);
			/// \brief Sets y value for a point
			void set_y(float value);
			/// \brief Sets z value for a point
			void set_z(float value);

			// Friend operators
			/// \brief Stream << operator overload, outputs data about point in to the stream
			/// \param out Parameter for passing stream data
			/// \param point An object to set data in
			/// \return Stream value filled with data about point
			friend std::ostream& operator<< (std::ostream& out, const point3d& point)
			{
				out << "( " << point.get_x() << "; " << point.get_y() << "; " << point.get_z() << ")";
				return out;
			}
			/// \brief Stream >> operator overload.\n
			///	\b Order of passed values should be: \b x, \b y, \b z
			/// \param in Parameter for passing stream data
			/// \param point An object to set data in
			/// \return Stream value
			friend std::istream& operator>> (std::istream& in, point3d& point)
			{
				point.set_x(in.get());
				point.set_y(in.get());
				point.set_z(in.get());
				return in;
			}
		};
	}
}

#endif