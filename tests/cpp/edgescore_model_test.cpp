#include "edgescore/edgescore_model.hpp"

#include <array>
#include <cstdint>
#include <random>

#include <gtest/gtest.h>

namespace {

std::uint32_t pack(const std::array<std::int8_t, 4>& lanes) {
  std::uint32_t value = 0;
  for (unsigned lane = 0; lane < lanes.size(); ++lane) {
    value |= static_cast<std::uint32_t>(static_cast<std::uint8_t>(lanes[lane]))
             << (lane * 8);
  }
  return value;
}

std::int32_t expected_dot(const std::uint32_t lhs, const std::uint32_t rhs) {
  std::int32_t result = 0;
  for (unsigned lane = 0; lane < 4; ++lane) {
    const auto a = static_cast<std::int8_t>(lhs >> (lane * 8));
    const auto b = static_cast<std::int8_t>(rhs >> (lane * 8));
    result += static_cast<std::int32_t>(a) * static_cast<std::int32_t>(b);
  }
  return result;
}

std::uint32_t expected_sad(const std::uint32_t lhs, const std::uint32_t rhs) {
  std::uint32_t result = 0;
  for (unsigned lane = 0; lane < 4; ++lane) {
    const auto a = static_cast<std::int32_t>(static_cast<std::int8_t>(lhs >> (lane * 8)));
    const auto b = static_cast<std::int32_t>(static_cast<std::int8_t>(rhs >> (lane * 8)));
    const auto difference = a - b;
    result += static_cast<std::uint32_t>(difference < 0 ? -difference : difference);
  }
  return result;
}

}  // namespace

TEST(EdgeScoreModel, Dot4HandlesRepresentativeVectors) {
  EXPECT_EQ(edgescore::dot4(0, 0), 0);
  EXPECT_EQ(edgescore::dot4(pack({1, 1, 1, 1}), pack({1, 1, 1, 1})), 4);
  EXPECT_EQ(edgescore::dot4(pack({1, 2, 3, 4}), pack({5, 6, 7, 8})), 70);
  EXPECT_EQ(edgescore::dot4(pack({-1, 2, -3, 4}), pack({5, -6, 7, -8})), -70);
  EXPECT_EQ(edgescore::dot4(pack({-128, -128, -128, -128}), pack({1, 1, 1, 1})), -512);
  EXPECT_EQ(edgescore::dot4(pack({127, 127, 127, 127}), pack({127, 127, 127, 127})), 64516);
  EXPECT_EQ(edgescore::dot4(pack({-128, 127, -128, 127}), pack({127, -128, 127, -128})), -65024);
}

TEST(EdgeScoreModel, Dot4MatchesDeterministicRegressionOracle) {
  std::mt19937 generator(0xED6C0DEU);
  for (unsigned iteration = 0; iteration < 1000; ++iteration) {
    const auto lhs = generator();
    const auto rhs = generator();
    EXPECT_EQ(edgescore::dot4(lhs, rhs), expected_dot(lhs, rhs));
  }
}

TEST(EdgeScoreModel, Sad4HandlesRepresentativeVectors) {
  EXPECT_EQ(edgescore::sad4(0, 0), 0U);
  EXPECT_EQ(edgescore::sad4(pack({0, 0, 0, 0}), pack({1, 1, 1, 1})), 4U);
  EXPECT_EQ(edgescore::sad4(pack({1, 2, 3, 4}), pack({5, 6, 7, 8})), 16U);
  EXPECT_EQ(edgescore::sad4(pack({-1, -2, -3, -4}), pack({1, 2, 3, 4})), 20U);
  EXPECT_EQ(edgescore::sad4(pack({-128, -128, -128, -128}), pack({127, 127, 127, 127})), 1020U);
}

TEST(EdgeScoreModel, Sad4MatchesDeterministicRegressionOracle) {
  std::mt19937 generator(0x5AD40001U);
  for (unsigned iteration = 0; iteration < 1000; ++iteration) {
    const auto lhs = generator();
    const auto rhs = generator();
    EXPECT_EQ(edgescore::sad4(lhs, rhs), expected_sad(lhs, rhs));
  }
}