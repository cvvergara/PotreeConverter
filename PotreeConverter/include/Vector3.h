
#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include <iostream>


/*!
   lets try boost geometry
*/
#include <boost/geometry.hpp>

namespace bg = boost::geometry;

using std::ostream;
#ifndef _MSC_VER
using std::max;
#endif

template<class T>
class Vector3{
public:
        typedef bg::model::point<T, 3, bg::cs::cartesian> point3D;
        point3D m_p;

public:
        // TODO once all foo.x like code are changed to foo.X() then this line can go away
	T x, y, z;

        T X() const {return bg::get<0>(m_p);}
        T Y() const {return bg::get<0>(m_p);}
        T Z() const {return bg::get<0>(m_p);}

private:
        void set_values(const T &p_x, const T &p_y, const T &p_z) {
        	bg::assign_values(m_p, p_x, p_y, p_z);
        	set_values();  // TODO remove when all code changed to use foo.X()
	}  
        // TODO once all foo.x like code are changed to foo.X() then this function can go away
        void set_values() {
		x = bg::get<0>(m_p);
		y = bg::get<1>(m_p);
		z = bg::get<2>(m_p);
	}

public:

        /*!
          default constructor
        */
	Vector3() {
        	set_values(0, 0, 0);
        }

        void set_values(const point3D &p) {
          m_p = p;
          set_values();  // TODO remove when all cade changed to use foo.X()
        }
          
        /*!
          user defined constructors
        */
	Vector3(const T &p_x,const T &p_y,const T &p_z) {
		set_values(p_x, p_y, p_z);
	}

	Vector3(T value) {
		set_values(value, value, value);
	}

        /*!
          copy constructor
        */
	Vector3(const Vector3<T> &other) = default;

        /*!
          destructor
        */
	~Vector3() = default;


	T length() const {
		point3D origin;
		bg::assign_values(origin, 0, 0, 0);
                return bg::distance(m_p, origin);
		// return sqrt(x*x + y*y + z*z);
	}

	T squaredLength() const {
		point3D origin;
		bg::assign_values(origin, 0, 0, 0);
                return bg::comparable_distance(m_p, origin);
		// return x*x + y*y + z*z;
	}

	T distanceTo(const Vector3<T> &p) const {
                return bg::distance(m_p, p.m_p);
		// return ((*this) - p).length();
	}

	T squaredDistanceTo(const Vector3<T> &p) const{
                return bg::comparable_distance(m_p, p.m_p);
		// return ((*this) - p).squaredLength();
	}

	T maxValue() const{
		return max(X(), max(Y(), Z()));
	}

	Vector3<T> operator-(const Vector3<T>& right) const {
		return Vector3<T>(X() - right.X(), Y() - right.Y(), Z() - right.Z());
		// return Vector3<T>(x - right.x, y - right.y, z - right.z);
	}

	Vector3<T> operator+(const Vector3<T>& right) const {
		return Vector3<T>(X() + right.X(), Y() + right.Y(), Z() + right.Z());
		// return Vector3<T>(x + right.x, y + right.y, z + right.z);
	}

	Vector3<T> operator/(const T &a) const{
		if (a == 0) throw;  // cant divide by 0
		return Vector3<T>(X() / a, Y() / a, Z() / a);
		// return Vector3<T>(x / a, y / a, z / a);
	}

	friend ostream &operator<<( ostream &output,  const Vector3<T> &value ){ 
		return output << "[" << value.X() << ", " << value.Y() << ", " << value.Z() << "]" ;
		// output << "[" << value.x << ", " << value.y << ", " << value.z << "]" ;
		// return output;            
	}
};

#endif
