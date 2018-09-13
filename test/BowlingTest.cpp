#include "../inc/Bowling.hpp"
#include "mocks/BowlingMock.hpp"
#include <gtest/gtest.h>

struct BowlingTest : public testing::Test
{
};

TEST_F(BowlingTest, iterating_through_files)
{
    // GIVEN
    std::string games_directory("../results");
    // WHEN
    BowlingWithNumberOfGames data(games_directory);
    // THEN
    ASSERT_EQ(data.getGamesNumber(), 5);
}

TEST_F(BowlingTest, wrong_directory_path)
{
    // GIVEN
    std::string games_directory("../resultssssss");
    // WHEN
    BowlingWithNumberOfGames data(games_directory);
    // THEN
    ASSERT_EQ(data.getGamesNumber(), 0);
}
