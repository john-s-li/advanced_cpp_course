#include "BitMap.h"
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include <fstream>
#include <iostream>

using namespace std;

BitMap::BitMap(int width, int height) : 
    _width(width), _height(height), _pixelArray(new uint8_t[width*height*3]{})
{}

BitMap::~BitMap()
{}

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t* pixelPtr = _pixelArray.get();

    pixelPtr += (3*y)*_width + (3*x);

    pixelPtr[0] = blue;
    pixelPtr[1] = green;
    pixelPtr[2] = red;
}

bool BitMap::write(string filename)
{
    // Init info
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) +
                          _width*_height*3;
    fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

    infoHeader.width = _width;
    infoHeader.height = _height;

    // Create object to write binary file
    ofstream file;
    file.open(filename, ios::out | ios::binary);

    if(!file)
    {
        cout << "File not found.\n";
        return false;
    }

    file.write((char*)&fileHeader, sizeof(fileHeader));
    file.write((char*)&infoHeader, sizeof(infoHeader));
    file.write((char*)(_pixelArray.get()), _width*_height*3);

    return true;
}