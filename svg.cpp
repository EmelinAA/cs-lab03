#include <string>
#include "svg.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

bool svg_check(double block_width)
{
    if((block_width>30) ||(block_width<3))
        return (false);
    else
        return (true);
}

void svg_end()
{
    cout << "</svg>\n";
}
void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
string make_info_text()
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
        char lpBuffer[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD si = MAX_COMPUTERNAME_LENGTH+1;
        GetComputerNameA(lpBuffer, &si);
        buffer<<"Windows v."<<version_major<<"."<<version_minor<<"(build "<<build<<")"<<endl;
        buffer<<"Computer name:"<<lpBuffer;
        return buffer.str();
    }
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<<baseline<<"'>"<<text<<"</text>";

}
void svg_rect(double x, double y, double width, double height, string line_colour, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << line_colour << "' fill='#" << fill << "'/>";
}

void show_histogram_svg(const vector<size_t>& bins,double block_width)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    double top = 0;
    string colour="red";
    string fill="FFFFFF";
    //cerr << "Enter line colour: ";
   // cin >> colour;
    //cerr << "Enter column fill: ";
   // cin >> fill;
   /* while (svg_check(block_width) == false)
    {
        cerr << "Enter block_width(in range from 3 to 30): ";
        cin >> block_width;
        svg_check(block_width);
    }*/
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    size_t max_count = 0;
    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }
    double scaling_factor = 1;
    const bool scaling_needed = max_count*block_width > IMAGE_WIDTH;
    if (scaling_needed)
        scaling_factor = (double)((IMAGE_WIDTH - TEXT_WIDTH) / block_width) / max_count;
    for (size_t bin : bins)
    {
        double bin_width = block_width * bin * scaling_factor;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, colour, fill);
        top += BIN_HEIGHT;
    }
    svg_text(TEXT_LEFT, top + TEXT_BASELINE,make_info_text());
    svg_end();
}
