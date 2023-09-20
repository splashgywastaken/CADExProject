
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <memory>
#include <ostream>
#include <istream>

namespace curves_library
{
	namespace tools
	{
		class CADEXDLL_API vector3d
		{
		private:
			std::unique_ptr<float> x_, y_, z_;
		public:
			/// \brief Constructor
			explicit vector3d(
				float x = .0f,
				float y = .0f,
				float z = .0f
			);
			/// \brief Copy constructor
			vector3d(const vector3d& vector);
			/// \brief Move constructor
			vector3d(vector3d&& other) noexcept
				: x_(std::move(other.x_)),
				y_(std::move(other.y_)),
				z_(std::move(other.z_))
			{}
			/// \brief Copy assignent operator
			vector3d& operator=(vector3d&& other) noexcept;

			// Getters
			/// \brief Gets x value of a vector
			float& get_x() const;
			/// \brief Gets y value of a vector
			float& get_y() const;
			/// \brief Gets z value of a vector
			float& get_z() const;
			// Setters
			/// \brief Sets x value for a vector
			void set_x(float value);
			/// \brief Sets y value for a vector
			void set_y(float value);
			/// \brief Sets z value for a vector
			void set_z(float value);

			// Friend operators
			/// \brief Stream << operator overload, outputs data about vector in to the stream
			/// \param out Parameter for passing stream data
			/// \param vector An object to set data in
			/// \return Stream value filled with data about vector
			friend std::ostream& operator << (std::ostream& out, const vector3d& vector)
			{
				out << "(" << *vector.x_ << ";" << *vector.y_ << ";" << *vector.z_ << ")";
				return out;
			}
			/// \brief Stream >> operator overload.\n
			///	\b Order of passed values should be: \b x, \b y, \b z
			/// \param in Parameter for passing stream data
			/// \param vector An object to set data in
			/// \return Stream value
			friend std::istream& operator >> (std::istream& in, vector3d& vector)
			{
				vector.set_x(in.get());
				vector.set_y(in.get());
				vector.set_z(in.get());
				return in;
			}
		};
	}

}

#endif 