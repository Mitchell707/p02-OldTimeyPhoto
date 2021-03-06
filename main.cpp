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
string again;

bool chooseMode = true;

const int RGB_MAX = 255;

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
        cout << "Enter the number of the effect you would you like to add to your image?" << endl << "1. Gray Scale\n" << "2. Film Grain\n" << "3. Red Scale\n" << "4. Green Scale\n" << "5. Blue Scale\n" << "6. Magenta Scale\n" << "7. Yellow Scale\n" << "8. Cyan Scale\n" << "9. Negative\n";
        cin >> editMode;

        if(editMode == "1" || editMode == "2" || editMode == "3" || editMode == "4" || editMode == "5" || editMode == "6" || editMode == "7" || editMode == "8" || editMode == "9")
        { 
            chooseMode = false;
        }
    }

    //Under code will set the appropriate colors in the rgb to 0 to make a total of 7 color scale combinations.
    if(editMode == "1")
    {
        redEffect = 1;
        greenEffect = 1;
        blueEffect = 1;
    }
    else if(editMode == "3")
    {
        redEffect = 1;
        greenEffect = 0;
        blueEffect = 0;
    }
    else if(editMode == "4")
    {
        redEffect = 0;
        greenEffect = 1;
        blueEffect = 0;
    }
    else if(editMode == "5")
    {
        redEffect = 0;
        greenEffect = 0;
        blueEffect = 1;
    }
    else if(editMode == "6")
    { 
        redEffect = 1;
        greenEffect = 0;
        blueEffect = 1;
    }
    else if(editMode == "7")
    {
        redEffect = 1;
        greenEffect = 1;
        blueEffect = 0;
    }
    else if(editMode == "8")
    {
        redEffect = 0;
        greenEffect = 1;
        blueEffect = 1;
    }

    bmp = image.toPixelMatrix(); //
              
    for(int r = 0; r < bmp.size(); r++)
    {
        for(int c = 0; c < bmp[r].size(); c++)
        {
            rgb = bmp[r][c]; //set rgb to the designated pixel in the array
            
            if(editMode == "1" || editMode == "3" || editMode == "4" || editMode == "5" || editMode == "6" || editMode == "7" || editMode == "8")
            {
                //next line will take the sum of the wanted colors by multiplying the value by the effectors that will be 0 or 1 and divide them by the the sum of the effectors to get the average.
                int avg = ((rgb.red * redEffect) + (rgb.green * greenEffect) + (rgb.blue * blueEffect)) / (redEffect + greenEffect + blueEffect);

                //Sets each rgb value to avg times the effect to keep each rgb color from being the same number making it gray.
                rgb.red = avg * redEffect;
                rgb.green = avg * greenEffect;
                rgb.blue = avg * blueEffect;
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
            else if(editMode == "9")
            {
                //each section sets the rgb color to 255 - the rgb color making the present pixel color its opposite i.e black to white, orange to blue, green to magenta...
                rgb.red = RGB_MAX - rgb.red;
                rgb.green = RGB_MAX - rgb.green;
                rgb.blue = RGB_MAX - rgb.blue;
            }
            
            bmp[r][c] = rgb; //sets the pixel to the resulting color
        }
    }
    
    image.fromPixelMatrix(bmp); //puts changed image back into matrix
    
    cout << "What name would you like to save this image with.\n";
    cin >> imgName;

    image.save(imgName + ".bmp"); //saves the image with the name given by the user and the suffix .bmp
    
    return 0;
}
