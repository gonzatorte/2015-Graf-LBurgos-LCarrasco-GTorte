#ifndef SCREEN_H
#define SCREEN_H

#include "Pixel.h"
#include "Ray.h"

using namespace std;

class Screen
{
    public:
        Screen();
        void createScreen();
        virtual ~Screen();
    protected:
    private:
};

#endif // SCREEN_H
