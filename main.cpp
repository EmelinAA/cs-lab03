#include <iostream>
#include <vector>
#include "svg.h"
#include "histogram.h"
#include <windows.h>

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
using namespace std;

int main()
{
    DWORD info = GetVersion();
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;
    printf("16x version is %08x \n", version );
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
