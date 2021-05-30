#include <iostream>
#include <vector>
#include "svg.h"
#include "histogram.h"
#include <windows.h>
#include <string>
#include <sstream>
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
using namespace std;
 string
    make_info_text()
    {
        stringstream buffer;
        DWORD info = GetVersion();
        DWORD mask = 0x0000ffff;
        DWORD platform = info >> 16;
        DWORD mask2 = 0x000000ff;
        DWORD version =info & mask;
        if ((info & 0x80000000) == 0)
        {
            DWORD version_minor = version>>8;
            DWORD version_major = version &mask2;
            DWORD build = platform;
            printf("Windows v.%u.%u (build %u) \n",version_major,version_minor,build);
            char lpBuffer[MAX_COMPUTERNAME_LENGTH + 1];
            DWORD si = MAX_COMPUTERNAME_LENGTH+1;
            printf("Computer name: %s\n",lpBuffer);
            return buffer.str();
        }
    }
int main()
{
   /* string
    make_info_text()
    {
        stringstream buffer;
        DWORD info = GetVersion();
        DWORD mask = 0x0000ffff;
        DWORD platform = info >> 16;
        DWORD mask2 = 0x000000ff;
        DWORD version =info & mask;
        if ((info & 0xf0000000) == 0)
        {
            DWORD version_minor = version>>8;
            DWORD version_major = version &mask2;
            DWORD build = platform;
            printf("Windows v.%u.%u (build %u) \n",version_major,version_minor,build);
            char lpBuffer[MAX_COMPUTERNAME_LENGTH + 1];
            DWORD si = MAX_COMPUTERNAME_LENGTH+1;
            GetComputerNameA(lpBuffer,&si);
            printf("Computer name: %s\n",lpbuffer);
            return buffer.str();
        }
    }
    */
    make_info_text();
    return (0);
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    if (number_count == 0)
        return 1;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins);
    return 0;
}
