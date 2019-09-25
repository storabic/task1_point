////////////////////////////////////////////////////////////////////////////////
// Module Name:  xipoint.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.1
// Date:         08.09.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "xipoint.h"

#include <algorithm>        // min
#include <cmath>

namespace xi {

	/// Constructor initialize a point object with two coordinates  
	Point::Point(int x, int y)
	{
		_x = x;
		_y = y;
	}

	/// Shifts coordinates by adding given value shf to both coordinates
	void Point::shift(int shf)
	{
		_x += shf;
		_y += shf;
	}

	/// Shifts coordinates by adding given values of corresponding coordinates
	void Point::shift(int xSh, int ySh)
	{
		_x += xSh;
		_y += ySh;
	}

	/// Shifts coordinates by adding given values of corresponding coordinates
	/// of the give point pt
	void Point::shift(const Point& pt)
	{
		_x += pt.getX();
		_y += pt.getY();
	}

	/// Distance to another point.  Pythagorean theorem.
	double Point::dist(const Point& other) const
	{
		return sqrt(pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2));
	}

	//-----<Setters/getters section>-----

	int Point::getX() const      ///< Gets x-coordinate
	{
		return _x;
	}
	int Point::getY() const      ///< Gets y-coordinate
	{
		return _y;
	}
	void Point::setX(int x)      ///< Sets x-coordinate
	{
		_x = x;
	}
	void Point::setY(int y)      ///< Sets y-coordinate
	{
		_y = y;
	}

	//Declare new type standing for unsigned int
	typedef unsigned int Uint;
	/** \brief Default constructor (a constructor with no arguments)
	 *
	 *  It should properly initialize all pointers and is not intended for
	 *  creating any types of "zero-arrays".
	 */
	PointArray::PointArray()
	{
		_arr = nullptr;
		_size = 0;
	}

	// Point array called points and an int called size 
	// as its arguments. It should initialize a PointArray with the 
	// specified size, copying the values from points. You will need 
	// to dynamically allocate the PointArray’s internal array to the 
	// specified size. 

	/** \brief Initialiaze an object with c-style array
	 *
	 *  The costructor initialized an object with a given c-style
	 *  array points and its size (n).
	 *  One need to allocate dynamically the internal array to the size of a given array.
	 *  Note that const Point points[] clause is equal to const Point* points
	 */
	PointArray::PointArray(const Point points[], Uint n)
	{
		_arr = new Point[n];
		_size = n;
		for (Uint i = 0; i < n; i++)
		{
			_arr[i] = points[i];
		}
	}

	/// Constructor creates a copy of a given PointArray
	PointArray::PointArray(const PointArray& pv)
	{
		_size = pv.getSize();
		_arr = new Point[getSize()];
		for (Uint i = 0; i < _size; i++)
			_arr[i] = *pv.get(i);
	}

	/// Destructor that deletes the internal array of the PointArray (frees the allocated memory)
	PointArray::~PointArray()
	{
		delete[] _arr;
		_size = 0;
	}

	/// Adds a Point to the end of the array 
	void PointArray::append(const Point& pt)
	{
		resize(getSize() + 1);
		_arr[getSize() - 1] = pt;
	}


	/** \brief Inserts a Point at a given position of the array, shifting the
	 *  elements past pos to the right.
	 *
	 *  If pos == 0, inserts a point into the beginning of the array.
	 *  If pos is bigger then the number of elements, put the point to the end.
	 */
	void PointArray::insert(const Point& pt, Uint pos)
	{
		if (pos >= getSize())
			append(pt);
		else
		{
			resize(getSize() + 1);
			for (Uint i = pos + 1; i < getSize(); i--)
				_arr[i] = _arr[i - 1];
			_arr[pos] = pt;
		}
	}


	/** \brief Removes a Point at a given position of the array, shifting the
	 *  remaining elements to the left .
	 *
	 *  If pos is bigger then the number of elements, does nothing.
	 *  If the removed element is the last one, no more underlying array is presented
	 *  after removing.
	 */
	void PointArray::remove(Uint pos)
	{
		if (pos < getSize())
		{
			for (Uint i = pos; i < getSize() - 1; i++)
				_arr[i] = _arr[i + 1];
			resize(getSize() - 1);
		}
	}

	/// Removes all elements from the array and sets its size to 0 
	void PointArray::clear()
	{
		delete[] _arr;
		_arr = nullptr;
		_size = 0;
	}

	/// \return The sum of distances between neighbouring points in the array.
	double PointArray::computePath() const
	{
		double sum = 0;
		for (Uint i = 1; i < getSize(); i++)
			sum += _arr[i].dist(_arr[i - 1]);
		return sum;
	}
	/// Gets the size of the array 
	Uint PointArray::getSize() const
	{
		return _size;
	}

	/** \brief Gets a pointer to the element at a given position of the array
	 *
	 *  If the array contains no given element, returns nullptr
	 */
	Point* PointArray::get(Uint pos)
	{
		if (pos >= getSize())
			return nullptr;
		return &_arr[pos];
	}

	const Point* PointArray::get(Uint pos) const
	{
		if (pos >= getSize())
			return nullptr;
		return &_arr[pos];
	}

	/// Allocates a new array of size n, copies the first min (previous array
	/// size, n) existing elements into it, and deallocates the old array.
	void PointArray::resize(Uint n)
	{
		if (n == 0)
		{
			clear();
		}
		{
			Point *newArr = new Point[n];
			for (int i = 0; i < std::min(getSize(), n); i++)
				newArr[i] = _arr[i];
			delete[] _arr;
			_arr = new Point[n];
			_size = n;
			for (int i = 0; i < n; i++)
				_arr[i] = newArr[i];
			delete[] newArr;
		}
	}

}