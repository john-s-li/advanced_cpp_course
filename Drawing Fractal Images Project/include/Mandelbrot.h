#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
    public:
        Mandelbrot();
        virtual ~Mandelbrot();
        static int getIterations(double x, double y);

        // the more iterations per pixel = higher quality of image
        static const int MAX_ITERATIONS = 1000;
};

#endif