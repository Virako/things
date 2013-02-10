#define BOOST_TEST_MODULE charactertests
#include <boost/test/included/unit_test.hpp>

#include "character.hpp"

BOOST_AUTO_TEST_SUITE (character_movements)

BOOST_AUTO_TEST_CASE (move_x)
{
    character c;
    core::vector3d<float> *v1 = new core::vector3d<float>(1,0,0);
    c.move(v1);
    BOOST_CHECK(*v1 == *c.get_position());
}

BOOST_AUTO_TEST_CASE (move_x_inv)
{
    character c;
    core::vector3d<float> *v1 = new core::vector3d<float>(-1,0,0);
    c.move(v1);
    BOOST_CHECK(*v1 == *c.get_position());
}

BOOST_AUTO_TEST_CASE (move_y)
{
    character c;
    core::vector3d<float> *v1 = new core::vector3d<float>(0,1,0);
    c.move(v1);
    BOOST_CHECK(*v1 == *c.get_position());
}

BOOST_AUTO_TEST_CASE (move_y_inv)
{
    character c;
    core::vector3d<float> *v1 = new core::vector3d<float>(0,-1,0);
    c.move(v1);
    BOOST_CHECK(*v1 == *c.get_position());
}

BOOST_AUTO_TEST_SUITE_END( )



BOOST_AUTO_TEST_SUITE (character_level)

BOOST_AUTO_TEST_CASE (level_up1)
{
    character c;
    c.up_level();
    BOOST_REQUIRE_EQUAL(2, c.get_level());
}

BOOST_AUTO_TEST_SUITE_END( )
