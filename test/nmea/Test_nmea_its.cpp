#include <gtest/gtest.h>
#include <marnav/nmea/its.hpp>
#include <marnav/nmea/nmea.hpp>

namespace
{

using namespace marnav;

class Test_nmea_its : public ::testing::Test
{
};

TEST_F(Test_nmea_its, contruction) { nmea::its its; }

TEST_F(Test_nmea_its, parse)
{
	auto s = nmea::make_sentence("$GPITS,1.0,M*3B");
	ASSERT_NE(nullptr, s);

	auto its = nmea::sentence_cast<nmea::its>(s);
	ASSERT_NE(nullptr, its);
}

TEST_F(Test_nmea_its, parse_invalid_number_of_arguments)
{
	EXPECT_ANY_THROW(nmea::its::parse("@@", {1, "@"}));
	EXPECT_ANY_THROW(nmea::its::parse("@@", {3, "@"}));
}

TEST_F(Test_nmea_its, empty_to_string)
{
	nmea::its its;

	EXPECT_STREQ("$GPITS,0,M*24", nmea::to_string(its).c_str());
}

}