#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

int main()
{
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;

    //read a file example.bmp and convert it to a pixel matrix
    image.open("machupicchu.bmp");
    bmp = image.toPixelMatrix();
              

    //take all the redness out of the top-left pixel
    rgb = bmp[0][0];
    rgb.red = 0; 

    //put changed image back into matrix, update the bitmap and save it
    bmp[0][0] = rgb;
    image.fromPixelMatrix(bmp);
    image.save("machupicchu.bmp");

    cout << "machupicchu.bmp has been loaded. It is " << bmp[0].size() << " pixels wide and " << bmp.size() << " pixels high" << endl;

    return 0;
}
