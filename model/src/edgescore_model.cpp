#include "edgescore/edgescore_model.hpp"

#include <cstdint>

namespace edgescore {

std::int32_t dot4(const std::uint32_t lhs, const std::uint32_t rhs) {
  std::int32_t result = 0;
  for (unsigned lane = 0; lane < 4; ++lane) {
    const auto lhs_lane = static_cast<std::int8_t>(lhs >> (lane * 8));
    const auto rhs_lane = static_cast<std::int8_t>(rhs >> (lane * 8));
    result += static_cast<std::int32_t>(lhs_lane) * rhs_lane;
  }
  return result;
}

std::uint32_t sad4(const std::uint32_t lhs, const std::uint32_t rhs) {
  std::uint32_t result = 0;
  for (unsigned lane = 0; lane < 4; ++lane) {
    const auto lhs_lane = static_cast<std::int32_t>(
        static_cast<std::int8_t>(lhs >> (lane * 8)));
    const auto rhs_lane = static_cast<std::int32_t>(
        static_cast<std::int8_t>(rhs >> (lane * 8)));
    const auto difference = lhs_lane - rhs_lane;
    result += static_cast<std::uint32_t>(difference < 0 ? -difference : difference);
  }
  return result;
}

}  // namespace edgescore