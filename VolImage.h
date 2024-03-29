//
// Created by Shaaheen on 3/4/2016.
//Header file for the VolImage class - All declarations

#ifndef ASSIGNMENT_2_SCRSHA001_VOLIMAGE_H
#define ASSIGNMENT_2_SCRSHA001_VOLIMAGE_H

#include <vector>
#include <string>

namespace SCRSHA001{
    class VolImage
    {
    private: // private members
        int width, height; // width and height of image stack
        std::vector<unsigned char**> slices; // data for each slice, in order

    public: // public members
        VolImage(); // default constructor - define in .cpp
        ~VolImage(); // destructor - define in .cpp file

        // populate the object with images in stack and
        //set member variables define in .cpp
        bool readImages(std::string baseName);



        // compute difference map and write out; define in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        // extract slice sliceId and write to output - define in .cpp
        void extract(int sliceId, std::string output_prefix);

        void extractRowFromVolume(int rowToExtract);

        // number of bytes uses to store image data bytes
        //and pointers (ignore vector<> container, dims etc)
        int volImageSize(void); // define in .cpp

        //To get the number of file
        int numOfImages(void);

        //Loads slices vector
        void loadInSliceFromRaw(int i, std::ifstream &rawFile);
    };

    //Outside class methods

    //Creates a default header file for any new raw files
    void createDefaultHeader(std::string outputPrefix);

    //Utility method to all int to be retrieved from command line params
    int getIntFromArgument(char* argumentValue);
}



#endif //ASSIGNMENT_2_SCRSHA001_VOLIMAGE_H
