#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

string imgName;

int main()
{
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;
    
    //read a file example.bmp and convert it to a pixel matrix
    do{

    cout << "Enter the name of the file you wish to edit.\n";
    cin >> imgName;
    
    //cout << imgName[imgName.length() - 4] << imgName[imgName.length() - 3] << imgName[imgName.length() - 2] << imgName[imgName.length() - 1] << endl;
    
    image.open(imgName);
    
    //cout << image.isImage();

    }while ( imgName[imgName.length() - 4] != '.' || imgName[imgName.length() - 3] != 'b' || imgName[imgName.length() - 2] != 'm' || imgName[imgName.length() - 1] != 'p' || image.isImage() == 0);



    //image.open("machupicchu.bmp");
    //image.open(imgName);
    bmp = image.toPixelMatrix();
              
    /*
    //take all the redness out of the top-left pixel
    rgb = bmp[0][0];
    rgb.red = 0; 
    */
    
    /*
    //put changed image back into matrix, update the bitmap and save it
    bmp[0][0] = rgb;
    image.fromPixelMatrix(bmp);
    image.save("machupicchu.bmp");
    */

    //cout << "machupicchu.bmp has been loaded. It is " << bmp[0].size() << " pixels wide and " << bmp.size() << " pixels high" << endl;
    
    for(int r = 0; r < bmp.size(); r++)
    {
        for(int c = 0; c < bmp[r].size(); c++)
        {
            rgb = bmp[r][c];
            //convert to black and white
    
            int temp = (rgb.red + rgb.green + rgb.blue) / 3;
            
            rgb.red = temp;
            rgb.green = temp;
            rgb.blue = temp;
            
            //cout << temp << endl;

            bmp[r][c] = rgb;
        }
    }
    
    image.fromPixelMatrix(bmp);
    
    cout << "What name would you like to save this image with.\n";
    cin >> imgName;

    image.save(imgName + ".bmp");
    //image.save("machupicchuBlackAndWhite.bmp");
    



    return 0;
}
