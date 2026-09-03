#pragma once

#include <cstdint>

namespace edgescore {

std::int32_t dot4(std::uint32_t lhs, std::uint32_t rhs);
std::uint32_t sad4(std::uint32_t lhs, std::uint32_t rhs);

}  // namespace edgescore