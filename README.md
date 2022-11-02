# ByteUtils

_A byte utils class to handle bytes with literals._

- [x] smooth calcualtion between decimal and binary suffixes.
- [x] fast readable and concise code.
- [x] fitting to literal.
- [x] compertibal with big integer types.

## Example:
```C++
    using namespace ByteUtils;
    auto zipFileSize = 2_GiB;
    std::cout << "zipFileSize: " << zipFileSize << std::endl;
    // zipFileSize: 2147483648

    auto newSize = zipFileSize - 1024_MB;
    std::cout << "newSize: " << newSize << std::endl;
    // newSize: 1123483648

    auto newSize2 = newSize - 512_KiB;
    std::cout << "newSize2: " << newSize2 << std::endl;
    // newSize2: 1122959360

    auto newSize3 = newSize2 - 256_B;
    std::cout << "newSize3: " << newSize3 << std::endl;
    // newSize3: 1122959104

    std::cout << fit_to_Literal(newSize3) << std::endl;
    // 1 Gib

    std::cout << to_MiB_as_string(newSize3) << std::endl;
    // 1070 MiB

    std::cout << to_MB(newSize3) << std::endl;
    // 1122
    
    std::cout << to_KiB_as_string(7168) << std::endl;
    // 7 KiB

    std::cout << to_KB(1122957168) << std::endl;
    // 1122957
