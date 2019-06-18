#include "Image.h"
#include <assert.h>
#include "mathUtil.h"
#include <fstream>

Image::Image():_ppRaster(NULL), _nx(0),_ny(0)
{
    //test
    std::cout << "Construct image" << std::endl;
}

Image::Image(int width, int height):_nx(width), _ny(height)
{
    alloc();
}

Image::Image(int width, int height, rgb background):_nx(width), _ny(height)
{
    assert(_nx > 0);
    _ppRaster = new rgb*[_nx];
    for (int i = 0; i < _nx; i++)
    {
        assert(_ny > 0);
        _ppRaster[i] = new rgb[_ny];
        for (int j = 0; i < _ny; j++)
        {
            _ppRaster[i][j] = background;
        }
    }
}

bool Image::set(int x, int y, const rgb & color)
{
    if(x < 0 || x >= _nx || y < 0 || y >= _ny)
    {
        return false;
    }
    _ppRaster[x][y] = color;
    return true;
}

void Image::gammaCorrect(float gamma)
{
    if (isZero(gamma))
    {
        return;
    }
    rgb temp;
    float power = 1.0f/gamma;
    for (int i = 0; i < _nx; i++)
    {
        for (int j = 0; j < _ny; j++)
        {
            temp = _ppRaster[i][j];
            _ppRaster[i][j].setRed(pow(temp.r(), power));
            _ppRaster[i][j].setGreen(pow(temp.g(), power));
            _ppRaster[i][j].setBlue(pow(temp.b(), power));
        }
    }
}

unsigned int clampColor255(float val)
{
    assert(val > TOL && val - TOL < 1.0f);
    unsigned int ret = val;
    ret = (unsigned int)(val * 255);
    if (ret > 255)
    {
        ret = 255;
    }
    return ret;
}

void Image::writePPM(std::ostream& out)
{
    //header
    out << "P6\n";
    out << _nx << ' ' << _ny << '\n';
    out << "255\n";

    int i = 0, j = 0;
    unsigned char col = 0;
    for (i = _ny - 1; i >= 0; i--)
    {
        for (j = 0; i < _nx; j++)
        {
            col = (unsigned char)clampColor255(_ppRaster[i][j].r());
            out.put(col);
            col = (unsigned char)clampColor255(_ppRaster[i][j].g());
            out.put(col);
            col = (unsigned char)clampColor255(_ppRaster[i][j].b());
            out.put(col);
        }
    }
}

bool Image::readPPM(std::string fileName)
{
    std::ifstream in;
    in.open(fileName.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error -- Couldn't open file \'" << fileName << "\'.\n";
        return false;
    }
    
    char ch, type;
    int cols = 0, rows = 0, num = 0;

    in.get(ch);
    in.get(type);
    in >> cols >> rows >> num;

    _nx = cols;
    _ny = rows;

    alloc();

    in.get(ch);
    for (int i = _ny -1; i > 0; i--)
    {
        for (int  j = 0; j < _nx; j++)
        {
            rgb col;
            in.get(ch);
            col.setRed((unsigned char)(ch/255.0f));
            in.get(ch);
            col.setGreen((unsigned char)(ch/255.0f));
            in.get(ch);
            col.setBlue((unsigned char)(ch/255.0f));
        }
    }
    return true;
}

void Image::alloc()
{
    assert(_nx > 0);
    _ppRaster = new rgb*[_nx];
    for (int i = 0; i < _nx; i++)
    {
        assert(_ny > 0);
        _ppRaster[i] = new rgb[_ny];
    }
}