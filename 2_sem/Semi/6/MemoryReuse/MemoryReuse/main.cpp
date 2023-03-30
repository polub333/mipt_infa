#include <iostream>
#include <iomanip>

using namespace std;

using u64 = uint64_t;
using u16 = uint16_t;
using u8 = uint8_t;

int main()
{
    u64 val = 0xabcdef;
    u16* p = reinterpret_cast<u16*>(&val);
    std::cout << val << " " << std::hex << (u16)p[0] << " " << (u16)p[1] << " " << (u16)p[2] << std::endl;
    return 0;
}
