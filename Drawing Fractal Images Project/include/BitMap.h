#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class BitMap
{
    public:
        BitMap(int width, int height);
        virtual ~BitMap();
        void setPixel(int x = 0, int y = 0, 
                      uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0);
        bool write(string filename = "test.bmp");

    private:
        int _width{0};
        int _height{0};
        unique_ptr<uint8_t[]> _pixelArray{nullptr};

};

#endif