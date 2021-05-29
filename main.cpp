#include <iostream>
#include <vector>
#include "svg.h"
#include "histogram.h"
#include <curl/curl.h>
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
using namespace std;
int main(int argc, char* argv[])
{
    if(argc>1)
    {
        cerr<<argc<<endl;
        for(int i=0;i<argc;i++)
            cerr<<argv[i]<<" ";
        return 0;
    }
    curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
}
