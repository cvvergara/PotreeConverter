
#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include <iostream>


#ifdef BOOSTGEOM
#include <boost/geometry.hpp>

namespace bg = boost::geometry;
#endif

using std::ostream;
#ifndef _MSC_VER
using std::max;
#endif

template<class T>
class Vector3{

#if 0   // memebers are private
 private:
	T m_x, m_y, m_z;  //  implies lots of changes
#endif
public:
#ifdef BOOSTGEOM
        bg::model::point<T, 3, boost::geometry::cs::cartesian> point3D;
#else
	T x, y, z;  //  implies lots of changes
#endif

#if 0  // when memebers are private
        // accessors
        const T& x() const { return m_x; }
        const T& y() const { return m_y; }
        const T& z() const { return m_z; }
         
        T& x() { return x; }
        T& y() { return y; }
        T& z() { return z; }
#endif   
	// static long long count;

        /*!
          default constructor
        */
#if 1
	Vector3() = default;
#else
	Vector3(){
	//	count++;

		x = 0;
		y = 0;
		z = 0;
	}
#endif

        /*!
          In c++11 to memeberwise initialize you can do this:

          Vector3<double> coordinate1 = {2,3,4};

          Vector3<double> coordinate2{2,3,4};
          
          so maybe this constructor can be removed...
          but need to change a lot of code. 
        */
	Vector3(T x, T y, T z){
	//	count++;

		this->x = x;
		this->y = y;
		this->z = z;
	}

        /*!
          user defined constructor
        */
	Vector3(T value){
	//	count++;

		this->x = value;
		this->y = value;
		this->z = value;
	}

        /*!
          copy constructor
        */
#if 1
	Vector3(const Vector3<T> &other) = default;
#else
	Vector3(const Vector3<T> &other)
		:x(other.x), y(other.y), z(other.z)
	{
	//	count++;
	}
#endif

        /*!
          destructor
        */
#if 1
	~Vector3() = default;
#else
	~Vector3(){
	//	count--;
	}
#endif


#ifndef BOOSTGEOM
	T length(){
		return sqrt(x*x + y*y + z*z);
	}

	T squaredLength(){
		return x*x + y*y + z*z;
	}

	T distanceTo(Vector3<T> p){
		return ((*this) - p).length();
	}

	T squaredDistanceTo(const Vector3<T> &p){
		return ((*this) - p).squaredLength();
	}

	T maxValue(){
		return max(x, max(y,z));
	}

	Vector3<T> operator-(const Vector3<T>& right) const {
		return Vector3<T>(x - right.x, y - right.y, z - right.z);
	}

	Vector3<T> operator+(const Vector3<T>& right) const {
		return Vector3<T>(x + right.x, y + right.y, z + right.z);
	}

	Vector3<T> operator/(const T &a) const{
		return Vector3<T>(x / a, y / a, z / a);
	}

	friend ostream &operator<<( ostream &output,  const Vector3<T> &value ){ 
		output << "[" << value.x << ", " << value.y << ", " << value.z << "]" ;
		return output;            
	}
#endif // ndef BOOSTGEOM
};





#endif
