#ifndef _IMAGE_H_
#define _IMAGE_H_  1

#include "rgb.h"

class Image
{
public:
    Image();
    Image(int width, int height);
    Image(int width, int height, rgb background);

    bool set(int x, int y, const rgb & color);
    void gammaCorrect(float gamma);
    void writePPM(std::ostream& out);
    bool readPPM(std::string fileName);

protected:
    void alloc();

private:
    rgb** _ppRaster;
    int _nx;
    int _ny;
};

#endif