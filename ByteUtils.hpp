//
// Created by Christoph Rohde on 31.10.22.
//

#pragma once
#include <iostream>

namespace ByteUtils{

    // literals
    consteval auto operator"" _B(const std::uint64_t bytes) -> std::uint64_t {
        return bytes;
    }

    consteval auto operator "" _KiB(const std::uint64_t value) -> std::uint64_t {
        return value * 1024_B;
    }

    consteval auto operator "" _MiB(const std::uint64_t value) -> std::uint64_t {
        return value * 1024_KiB;
    }

    consteval auto operator "" _GiB(const std::uint64_t value) -> std::uint64_t {
        return value * 1024_MiB;
    }

    consteval auto operator "" _TiB(const std::uint64_t value) -> std::uint64_t {
        return value * 1024_GiB;
    }

    consteval auto operator "" _KB(const std::uint64_t value) -> std::uint64_t {
        return value * 1000_B;
    }

    consteval auto operator "" _MB(const std::uint64_t value) -> std::uint64_t {
        return value * 1000_KB;
    }

    consteval auto operator "" _GB(const std::uint64_t value) -> std::uint64_t {
        return value * 1000_MB;
    }

    consteval auto operator "" _TB(const std::uint64_t value) -> std::uint64_t {
        return value * 1000_GB;
    }

    // calculation with literals
    auto to_KiB(const std::uint64_t value) -> std::uint64_t {
        return value / 1024_B;
    }

    auto to_MiB(const std::uint64_t value) -> std::uint64_t {
        return value / 1024_KiB;
    }

    auto to_GiB(const std::uint64_t value) -> std::uint64_t {
        return value / 1024_MiB;
    }

    auto to_TiB(const std::uint64_t value) -> std::uint64_t {
        return value / 1024_GiB;
    }

    auto to_KB(const std::uint64_t value) -> std::uint64_t {
        return value / 1000_B;
    }

    auto to_MB(const std::uint64_t value) -> std::uint64_t {
        return value / 1000_KB;
    }

    auto to_GB(const std::uint64_t value) -> std::uint64_t {
        return value / 1000_MB;
    }

    auto to_TB(const std::uint64_t value) -> std::uint64_t {
        return value / 1000_GB;
    }

    //   return with literals
    auto to_B_as_string(const std::uint64_t value) -> std::string {
        return std::to_string(value) + " B";
    }

    auto to_KiB_as_string (const std::uint64_t value) -> std::string {
        return std::to_string(to_KiB(value)) + " KiB";
    }

    auto to_MiB_as_string (const std::uint64_t value) -> std::string {
        return std::to_string(to_MiB(value)) + " MiB";
    }

    auto to_GiB_as_string (const std::uint64_t value) -> std::string {
        return std::to_string(to_GiB(value)) + " GiB";
    }

    /**
     * @brief Converts a given value in bytes to a string with the corresponding unit.
     * @param value The size in bytes.
     * @return std::string
     */
    auto fit_to_Literal(const std::uint64_t value) -> std::string {
        if (value < 1_KiB || value > 1_TiB) {
            return to_B_as_string(value);

        } else if (value < 1_MiB) {
            return to_KiB_as_string(value);

        } else if (value < 1_GiB) {
            return to_MiB_as_string(value);

        } else if (value < 1_TiB) {
            return to_GiB_as_string(value);
        }
        return "0 B";
    }

}
