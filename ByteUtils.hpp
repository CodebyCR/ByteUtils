//
// Created by Christoph Rohde on 31.10.22.
//

#pragma once
#include <iostream>

namespace ByteUtils{

    // literals
    constexpr auto operator"" _B(unsigned long long int bytes) -> unsigned long long int {
        return bytes;
    }

    constexpr auto operator "" _KiB(unsigned long long int value) -> unsigned long long int {
        return value * 1024_B;
    }

    constexpr auto operator "" _MiB(unsigned long long int value) -> unsigned long long int {
        return value * 1024_KiB;
    }

    constexpr auto operator "" _GiB(unsigned long long int value) -> unsigned long long int {
        return value * 1024_MiB;
    }

    constexpr auto operator "" _TiB(unsigned long long int value) -> unsigned long long int {
        return value * 1024_GiB;
    }

    constexpr auto operator "" _KB(unsigned long long int value) -> unsigned long long int {
        return value * 1000_B;
    }

    constexpr auto operator "" _MB(unsigned long long int value) -> unsigned long long int {
        return value * 1000_KB;
    }

    constexpr auto operator "" _GB(unsigned long long int value) -> unsigned long long int {
        return value * 1000_MB;
    }

    constexpr auto operator "" _TB(unsigned long long int value) -> unsigned long long int {
        return value * 1000_GB;
    }

    // calculation with literals
    auto to_KiB(uintmax_t value) -> uintmax_t {
        return value / 1024_B;
    }

    auto to_MiB(uintmax_t value) -> uintmax_t {
        return value / 1024_KiB;
    }

    auto to_GiB(uintmax_t value) -> uintmax_t {
        return value / 1024_MiB;
    }

    auto to_TiB(uintmax_t value) -> uintmax_t {
        return value / 1024_GiB;
    }

    auto to_KB(uintmax_t value) -> uintmax_t {
        return value / 1000_B;
    }

    auto to_MB(uintmax_t value) -> uintmax_t {
        return value / 1000_KB;
    }

    auto to_GB(uintmax_t value) -> uintmax_t {
        return value / 1000_MB;
    }

    auto to_TB(uintmax_t value) -> uintmax_t {
        return value / 1000_GB;
    }

    //   return with literals
    auto to_B_as_string(uintmax_t value) -> std::string {
        return std::to_string(value) + " B";
    }

    auto to_KiB_as_string (uintmax_t value) -> std::string {
        return std::to_string(to_KiB(value)) + " KiB";
    }

    auto to_MiB_as_string (uintmax_t value) -> std::string {
        return std::to_string(to_MiB(value)) + " MiB";
    }

    auto to_GiB_as_string (uintmax_t value) -> std::string {
        return std::to_string(to_GiB(value)) + " GiB";
    }

    /**
     * @brief Converts a given value in bytes to a string with the corresponding unit.
     * @param value The size in bytes.
     * @return std::string
     */
    auto fit_to_Literal(uintmax_t value) -> std::string {
        if (value < 1_KiB || value > 1_TiB) {
            return to_B_as_string(value);

        } else if (value < 1_MiB) {
            return to_KiB_as_string(value);

        } else if (value < 1_GiB) {
            return to_MiB_as_string(value);

        } else if (value < 1_TiB) {
            return to_GiB_as_string(value);
        }
    }

}
