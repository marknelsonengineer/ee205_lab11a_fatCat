///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab11a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once


/// Every Animal has a Weight.
///
/// C++ maintains Weight as a float, however, weights in the physical world
/// have certain constraints (i.e. you can't have a negative weight).
class Weight {
public:  //////////////////////// Enumerations /////////////////////////////////
    /// A unit of measure for weight
   enum UnitOfWeight { POUND, KILOGRAM, SLUG };

private:  ////////////////////// Member Variables //////////////////////////////
   bool bIsKnown = false ;  ///< `true` if Weight is known.  Defaults to `false`.
   bool bHasMax = false ;   ///< `true` if Weight has a maximum weight defined.  Defaults to `false`.
   enum UnitOfWeight unitOfWeight = POUND ;  ///< How the weight is held and displayed.  Defaults to POUND.
                                             ///< The unit of weight can only be set when the Weight is constructed.

   float weight ;      ///< The weight
   float maxWeight ;   ///< The maximum weight.  The maximum weight can only be set when the Weight is constructed.

public:   //////////////////////// Constructors ////////////////////////////////
   Weight();  ///< A default weight
   Weight( float newWeight );   ///< A weight with a value
   Weight( UnitOfWeight newUnitOfWeight );  ///< A weight with a unit of measure
   Weight( float newWeight, UnitOfWeight newUnitOfWeight );  ///< A weight with a value and unit of measure
   Weight( float newWeight, float newMaxWeight );  ///< A weight with a value and a maximum weight
   Weight( UnitOfWeight newUnitOfWeight, float newMaxWeight );  ///< A weight with a unit of measure and a maximum weight
   Weight( float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight );  ///< A weight with a value, unit of measure and a maximum weight

public:   ////////////////////// Getters & Setters /////////////////////////////
   bool isWeightKnown() ;   ///< `true` if the weight is known
   float getWeight();       ///< Return the value of the weight in the Weight's units
   float getWeight( UnitOfWeight weightUnits );  ///< Get the weight in a specified unit
   float getMaxWeight();    ///< Return the maximum weight
   UnitOfWeight getWeightUnit();  ///< Return the UnitOfWeight for this Weight

   void setWeight( float newWeight );  ///< Set the weight
   void setWeight( float newWeight, UnitOfWeight weightUnits );  ///< Set the weight as a specified unit

public:   /////////////////////// Static Methods ///////////////////////////////
   static bool isWeightValid( float checkWeight );  ///< Check the weight

public:   ////////////////////////// Methods //////////////////////////////////
   bool validate();   ///< Check the weight class to ensure it's healthy
   void dump();       ///< Print the weight class
};
