#include <gtest/gtest.h>
#include <ais/message_01.hpp>
#include <ais/ais.hpp>

namespace
{

class Test_message_01 : public ::testing::Test
{
};

TEST_F(Test_message_01, parse)
{
	std::vector<std::pair<std::string, int>> v;
	v.push_back(std::make_pair("133m@ogP00PD;88MD5MTDww@2D7k", 0));

	auto result = ais::make_message(v);
	ASSERT_TRUE(result != nullptr);

	auto m = ais::message_cast<ais::message_01>(result);
	ASSERT_TRUE(m != nullptr);

	EXPECT_EQ(0u, m->get_repeat_indicator());
	EXPECT_EQ(205344990u, m->get_mmsi());
	EXPECT_EQ(-128, m->get_rot());
	EXPECT_EQ(0u, m->get_sog());
	EXPECT_EQ(true, m->get_position_accuracy());
	EXPECT_NEAR(4.40705, m->get_longitude(), 4e-5);
	EXPECT_NEAR(51.2296, m->get_latitude(), 4e-5);
	EXPECT_EQ(1107u, m->get_cog());
	EXPECT_EQ(511u, m->get_hdg());
	EXPECT_EQ(52u, m->get_timestamp());
	EXPECT_EQ(0u, m->get_maneuver_indicator());
	EXPECT_EQ(true, m->get_raim());
	EXPECT_EQ(82419u, m->get_radio_status());
}

}