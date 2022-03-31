///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab11a_fatCat - EE 205 - Spr 2022
///
/// @file test_Weight.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "../src/Weight.h"

using namespace std;

BOOST_AUTO_TEST_CASE( test_Weight_Constructor1 ) {
// Weight w1 = Weight();
   Weight w1;
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), false );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), false );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::POUND );
   BOOST_CHECK_EQUAL( w1.getWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK( w1.validate() );
}

BOOST_AUTO_TEST_CASE( test_Weight_Constructor2 ) {
// Weight w1 = Weight( 100 );
   Weight w1( 100 );

   BOOST_CHECK_EQUAL( w1.isWeightKnown(), true );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), false );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::POUND );
   BOOST_CHECK_EQUAL( w1.getWeight(), 100 );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK( w1.validate() );
}

BOOST_AUTO_TEST_CASE( test_Weight_Constructor3 ) {
   Weight w1 = Weight( Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), false );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), false );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK( w1.validate() );
}

BOOST_AUTO_TEST_CASE( test_Weight_Constructor4 ) {
   Weight w1 = Weight( 100, Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), true );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), false );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), 100 );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK( w1.validate() );
}


BOOST_AUTO_TEST_CASE( test_Weight_Constructor5 ) {
   Weight w1 = Weight( 100, 1000 );
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), true );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), true );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::POUND );
   BOOST_CHECK_EQUAL( w1.getWeight(), 100 );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), 1000 );
   BOOST_CHECK( w1.validate() );
}


BOOST_AUTO_TEST_CASE( test_Weight_Constructor6 ) {
   Weight w1 = Weight( Weight::SLUG, 1000 );
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), false );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), true );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), 1000 );
   BOOST_CHECK( w1.validate() );
}


BOOST_AUTO_TEST_CASE( test_Weight_Constructor7 ) {
   Weight w1 = Weight( 100, Weight::SLUG, 1000 );
   BOOST_CHECK_EQUAL( w1.isWeightKnown(), true );
   BOOST_CHECK_EQUAL( w1.hasMaxWeight(), true );
   BOOST_CHECK_EQUAL( w1.getWeightUnit(), Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), 100 );
   BOOST_CHECK_EQUAL( w1.getMaxWeight(), 1000 );
   BOOST_CHECK( w1.validate() );
}


BOOST_AUTO_TEST_CASE( test_Weight_Illegal_Constructors ) {
   BOOST_CHECK_THROW( Weight( 0 ), out_of_range );
   BOOST_CHECK_THROW( Weight( -1 ), out_of_range );

   BOOST_CHECK_THROW( Weight( 0, Weight::KILO), out_of_range );

   BOOST_CHECK_THROW( Weight( 0, 1000), out_of_range );
   BOOST_CHECK_THROW( Weight( 100, 0), out_of_range );
   BOOST_CHECK_THROW( Weight( 0, 0), out_of_range );
   BOOST_CHECK_THROW( Weight( 100, 50), out_of_range );

   BOOST_CHECK_THROW( Weight( Weight::KILO, 0), out_of_range );

   BOOST_CHECK_THROW( Weight( 0, Weight::KILO, 1000), out_of_range );
   BOOST_CHECK_THROW( Weight( 100, Weight::KILO, 0), out_of_range );
   BOOST_CHECK_THROW( Weight( 0, Weight::KILO, 0), out_of_range );
   BOOST_CHECK_THROW( Weight( 100, Weight::KILO, 99), out_of_range );
}


BOOST_AUTO_TEST_CASE( test_Weight_Max_Constructors ) {
   BOOST_CHECK( Weight( 100, 100).validate() );
   BOOST_CHECK( Weight( 100, Weight::KILO, 100).validate() );
}


BOOST_AUTO_TEST_CASE( test_Weight_Get_With_Units ) {
   Weight w1 = Weight( 100, Weight::SLUG, 1000 );

   BOOST_CHECK_EQUAL( w1.getWeight( Weight::POUND ), (float) 100 / Weight::SLUGS_IN_A_POUND );
   BOOST_CHECK_EQUAL( w1.getWeight( Weight::KILO ), (float) 100 / Weight::SLUGS_IN_A_POUND * Weight::KILOS_IN_A_POUND );
}


BOOST_AUTO_TEST_CASE( test_Weight_Set_Weight ) {
   Weight w1 = Weight( 100, Weight::KILO, 1000 );

   BOOST_CHECK_THROW( w1.setWeight( -1 ), out_of_range );
   BOOST_CHECK_THROW( w1.setWeight( 0 ), out_of_range );

   w1.setWeight( 0.001 );
   BOOST_CHECK_EQUAL( w1.getWeight(), (float) 0.001 );

   w1.setWeight( 999.999 );
   BOOST_CHECK_EQUAL( w1.getWeight(), (float) 999.999 );

   w1.setWeight( 1000 );
   BOOST_CHECK_EQUAL( w1.getWeight(), (float) 1000 );

   BOOST_CHECK_THROW( w1.setWeight( 1000.001 ), out_of_range );
}


BOOST_AUTO_TEST_CASE( test_Weight_Set_Weight_With_Units ) {
   Weight w1 = Weight( 100, Weight::KILO, 1000 );

   BOOST_CHECK_THROW( w1.setWeight( -1, Weight::SLUG ), out_of_range );
   BOOST_CHECK_THROW( w1.setWeight( 0, Weight::SLUG ), out_of_range );

   w1.setWeight( 0.001, Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), (float) 0.001 / Weight::SLUGS_IN_A_POUND * Weight::KILOS_IN_A_POUND );

   // 1000kg = 68.5218slug
   w1.setWeight( 68.52, Weight::SLUG );
   BOOST_CHECK_EQUAL( w1.getWeight(), (float) 68.52 / Weight::SLUGS_IN_A_POUND * Weight::KILOS_IN_A_POUND );

   BOOST_CHECK_THROW( w1.setWeight( 68.53, Weight::SLUG ), out_of_range );

   Weight w2 = Weight( 100, Weight::KILO );  // No max Weight
   w2.setWeight( 1000, Weight::SLUG );
   BOOST_CHECK_EQUAL( w2.getWeight(), (float) 1000 / Weight::SLUGS_IN_A_POUND * Weight::KILOS_IN_A_POUND );
}


BOOST_AUTO_TEST_CASE( test_Weight_Conversions )
{
   BOOST_CHECK_EQUAL( Weight::convertWeight(1, Weight::POUND, Weight::POUND), 1 );
   BOOST_CHECK_EQUAL( Weight::convertWeight(1, Weight::KILO, Weight::KILO), 1 );
   BOOST_CHECK_EQUAL( Weight::convertWeight(1, Weight::SLUG, Weight::SLUG), 1 );

   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::POUND, Weight::KILO), (float) 3.14 * Weight::KILOS_IN_A_POUND );
   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::POUND, Weight::SLUG), (float) 3.14 * Weight::SLUGS_IN_A_POUND );

   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::KILO, Weight::POUND), (float) 3.14 / Weight::KILOS_IN_A_POUND );
   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::KILO, Weight::SLUG), (float) 3.14 / Weight::KILOS_IN_A_POUND * Weight::SLUGS_IN_A_POUND );

   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::SLUG, Weight::POUND), (float) 3.14 / Weight::SLUGS_IN_A_POUND );
   BOOST_CHECK_EQUAL( Weight::convertWeight(3.14, Weight::SLUG, Weight::KILO), (float) 3.14 / Weight::SLUGS_IN_A_POUND * Weight::KILOS_IN_A_POUND  );
}
