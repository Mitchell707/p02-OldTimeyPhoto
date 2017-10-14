#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"
#include <cstdlib>

using namespace std;

string imgName;

int temp = 0;

int redEffect = 1;
int greenEffect = 1;
int blueEffect = 1;

string editMode;

bool chooseMode = true;

int main()
{
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;

    do{

    cout << "Enter the name of the file you wish to edit.\n";
    cin >> imgName;
        
    image.open(imgName); //opens chosen bitmap image
    
    }while ( imgName[imgName.length() - 4] != '.' || imgName[imgName.length() - 3] != 'b' || imgName[imgName.length() - 2] != 'm' || imgName[imgName.length() - 1] != 'p' || image.isImage() == 0);

    while (chooseMode == true)
    {        
        cout << "Enter the number of the effect you would you like to add to your image?" << endl << "1. Gray Scale\n" << "2. Film Grain\n";
        cin >> editMode;

        if(editMode == "1" || editMode == "2")
        { 
            chooseMode = false;
        }
    }

    bmp = image.toPixelMatrix(); //
              
    //Make a multi if statement and have user input to edit the photo how they want, i.e. grayscale, film grain, negative, red, green, blue, purple, yellow, tiel, mirror.
    for(int r = 0; r < bmp.size(); r++)
    {
        for(int c = 0; c < bmp[r].size(); c++)
        {
            rgb = bmp[r][c]; //set rgb to the designated pixel in the array
            
            if(editMode == "1")
            {
                temp = (rgb.red + rgb.green + rgb.blue) / 3; //takes average of all colors in the pizel
                rgb.red = temp; //sets all colors to the average
                rgb.green = temp;
                rgb.blue = temp;
            }
            else if(editMode == "2")
            {
                if(rand() % 12 == 0) //will make roughly 1 in every 12 pixels black
                {
                    temp = 0; 

                    rgb.red = temp;
                    rgb.green = temp;
                    rgb.blue = temp;
                }
            }
            bmp[r][c] = rgb; //sets the pixel to the resulting color
        }
    }
    
    image.fromPixelMatrix(bmp); //puts changed image back into matrix
    
    cout << "What name would you like to save this image with.\n";
    cin >> imgName;

    image.save(imgName + ".bmp"); //saves the image with the name given by the user.

    return 0;
}
