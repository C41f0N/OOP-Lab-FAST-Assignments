#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Image
{
    int height, width;
    int **imageData;

public:
    // Constructor
    Image(int height, int width, int **imageData)
    {
        this->height = height;
        this->width = width;

        // Allocating memory
        this->imageData = new int *[height];
        for (int i = 0; i < height; i++)
        {
            this->imageData[i] = new int[width];
        }

        // Copying data
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                this->imageData[i][j] = imageData[i][j];
            }
        }
    }

    // Copy Constructor
    Image(Image &image)
    {
        this->height = image.height;
        this->width = image.width;

        // Allocating memory
        this->imageData = new int *[height];
        for (int i = 0; i < height; i++)
        {
            imageData[i] = new int[width];
        }

        // Copying data
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                this->imageData[i][j] = image.imageData[i][j];
            }
        }
    }

    // Destructor
    ~Image()
    {
        delete[] this->imageData;
    }

    // Display Image Data
    void display()
    {
        cout << "Displaying image data" << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << imageData[i][j] << ", ";
            }
            cout << "\b\b" << endl;
        }
    }

    void updateData()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (imageData[i][j] < 0)
                {
                    imageData[i][j] = (rand() + 1) % 256;
                }
            }
        }
    }
};

int main()
{
    srand(time(NULL));

    // Allocate Image Data
    int **imageData1 = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        imageData1[i] = new int[3];
    }

    // Set data
    imageData1[0][0] = 234;
    imageData1[0][1] = 34;
    imageData1[0][2] = 23;
    imageData1[1][0] = -10;
    imageData1[1][1] = 12;
    imageData1[1][2] = 103;

    Image image1(2, 3, imageData1);
    Image image2(image1);

    image1.display();
    image2.display();

    image2.updateData();

    image2.display();
}