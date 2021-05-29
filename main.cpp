#include <iostream>
#include <vector>
#include "svg.h"
#include "histogram.h"
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
using namespace std;
int main()
{
    size_t number_count;
    size_t bin_count;
    Input data = read_input(cin);
    const auto bins = make_histogram(data);
    show_histogram_text(bins);
    //show_histogram_svg(bins);
    return 0;
}
