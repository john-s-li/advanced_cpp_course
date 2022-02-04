#include "BitMap.h"
#include "Mandelbrot.h"
#include "progressbar.hpp"
#include <iostream>


using namespace std;

double fractalScale(int val, int oldMax, int oldMin=0)
{
    // converts one number from a range into a number within [-1,1]
    double newMax = 1; double newMin = -1;
    double scale = (newMax - newMin)/(oldMax - oldMin);
    return (val - oldMin)*scale + newMin;
}

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    BitMap bMap(WIDTH, HEIGHT);
    progressbar pBar(HEIGHT);

    // set fractal image pixels
    for(int y = 0; y < HEIGHT; ++y)
    {
        pBar.update();
        for(int x = 0; x < WIDTH; ++x)
        {
            double xFractal = fractalScale(x, WIDTH);
            double yFractal = fractalScale(y, HEIGHT);
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t red   = static_cast<uint8_t>(
                                256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);
            uint8_t green = static_cast<uint8_t>(
                                256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);
            uint8_t blue  = static_cast<uint8_t>(
                                256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

            bMap.setPixel(x, y, red, green, blue);
        }
    }

    bMap.write();

    return 0;
}