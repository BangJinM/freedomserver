#pragma once

#include <array>

namespace xtea
{

    using key = std::array<uint32_t, 4>;
    using round_keys = std::array<uint32_t, 64>;

    round_keys expand_key(const key &k);
    void encrypt(uint8_t *data, size_t length, const round_keys &k);
    void decrypt(uint8_t *data, size_t length, const round_keys &k);

} // namespace xtea
