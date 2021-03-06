/******************************************************************************
* File: Line2DImpl.h
*******************************************************************************
* Purpose: Interface to the class for the spatial data type Line2D
*
* Description: This file specifies interface to the class Line2D and to
*   several nested iterator classes that enable access to components (that is,
*   segments) of Line2D objects. The class Line2D contains
*   specifications of several constructors, a destructor, and several
*   type-specific unary methods of this spatial data type. Binary spatial
*   operations that involve Line2D objects are specified elsewhere. 
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 2 (Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef Line2DImpl_H
#define Line2DImpl_H

#include "Line2D.h"

class Line2DImpl : public Line2D 
{
  public:
    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2D object.
    Line2DImpl();

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2D object in the sense that it conforms to the
    // formal definition of this data type.
    Line2DImpl(std::vector<Seg2D> segs);

    // Constructor for complex region structure. It takes as input a string name that can represent either :
    // 1) file name which contains the vector of segments from which to construct the region object 
    // 2) string the textually represents the input vector of segments.
    //
    // The grammar for representing a segment vector in both cases 1 and 2 are structured as follows:
    // Expression := '(' Segment+ ')'
    // Segment:= '(' Point ',' Point ')'
    // Point:= '(' Number ',' Number ')'
    // Number := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign := ['+' | '-']
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit:= '0' | DigitWithoutZero
    //
    // example for segment list of seg1 and seg2 here is: (((1,2),(3,4)),((5,6),(7,8)))
    Line2DImpl(std::string textRepresentation);

    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2DImpl(Line2DImpl& source);

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2DImpl(Line2DImpl&& source);

    //Destructor
    virtual ~Line2DImpl();

    
    //++++++++++++++++++++++
    //++ Block iterator ++++
    //++++++++++++++++++++++
    // Constant block iterator type that allows to navigate through the blocks of
    // a Line2D object in forward and reverse direction. A change of the
    // blocks is not possible.
    class ConstBlockIterator
    {
      friend class Line2DImpl;

      public:
        // Default constructor that creates an empty constant block iterator.
        ConstBlockIterator();

        // Copy constructor that constructs a constant block iterator from a
        // given constant block iterator "source".
        ConstBlockIterator(const ConstBlockIterator& source);

        // Move constructor that moves a given constant block iterator "source"
        // to a constant block iterator. The constant block iterator "source"
        // gets the empty constant block iterator as its value.
        ConstBlockIterator(const ConstBlockIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // block iterator.
        ~ConstBlockIterator();

        // Assignment operator that assigns another constant block iterator
        // "rhs" to the constant block iterator.
        ConstBlockIterator& operator = (const ConstBlockIterator& rhs);

        // Predicate that tests whether a constant block iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstBlockIterator& operator ++ ();   // prefix
        ConstBlockIterator operator ++ (int); // postfix
        ConstBlockIterator& operator -- ();   // prefix
        ConstBlockIterator operator -- (int); // postfix

        // Dereferencing operators that return the value at the constant block
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a block. The dereferenced value cannot be changed.
        const Line2DImpl& operator *() const;
        const Line2DImpl* operator ->() const;

        // Comparison operators that compare a constant block iterator position
        // with another const block iterator position "rhs"
        bool operator == (const ConstBlockIterator& rhs) const;
        bool operator != (const ConstBlockIterator& rhs) const;
        bool operator <  (const ConstBlockIterator& rhs) const;
        bool operator <= (const ConstBlockIterator& rhs) const;
        bool operator >  (const ConstBlockIterator& rhs) const;
        bool operator >= (const ConstBlockIterator& rhs) const;

      private:
        // Forward struct declaration for the hidden implementation of a
        // constant block iterator
        struct ConstBlockIteratorImplementation;

        // Declaration of an opaque pointer
        ConstBlockIteratorImplementation* handlei;
    }; // class ConstBlockIterator

    // Method that returns a constant block iterator to the first block of a
    // Line2D object.
    ConstBlockIterator cbegin() const;

    // Method that returns a constant block iterator to the last block of a
    // Line2D object.
    ConstBlockIterator cend() const;

    // Method that returns a constant block iterator to the position before the
    // first block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    ConstBlockIterator chead() const;

    // Method that returns a constant block iterator to the position after the
    // last block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    ConstBlockIterator ctail() const;

}; // class Line2DImpl

#endif // Line2DImpl_H
