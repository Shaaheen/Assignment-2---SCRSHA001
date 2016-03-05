//
// Created by Shaaheen on 3/4/2016.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "VolImage.h"

using namespace std;

namespace SCRSHA001{

    VolImage::VolImage() {
        width = 0;
        height =0;
    }

    VolImage::~VolImage() {

        for (int i = 0; i < slices.size(); ++i) {
            for (int j = 0; j < height ; ++j) {
                for (int k = 0; k < width ; ++k) {
                    //delete [] slices[i][j][k];
                    slices[i][j][k] = 0;
                }
                delete [] slices[i][j];
            }
            delete [] slices[i];
        }
        slices.clear();
        width = 0;
        height= 0;
    }

    bool VolImage::readImages(std::string baseName) {

        string fileDirectory = "brain_mri_raws/"; //Directory where raw files are kept
        ifstream headerFile(fileDirectory + baseName + ".data"); //Access header file
        string headerInfo;
        getline(headerFile,headerInfo); //Get first line from header
        stringstream streamOfHeaderInfo (headerInfo); //Take in header info as string stream to manipulate

        //Store info from header
        int numOfFiles;
        streamOfHeaderInfo >> width;
        streamOfHeaderInfo >> height;
        streamOfHeaderInfo >> numOfFiles;

        cout << "Loading raw files into program..." <<endl;
        //Insert binary data from raw files into slices array
        for (int i = 0; i < numOfFiles; i++) {
            //cout<< fileDirectory + baseName   + to_string(i) +  ".raw" <<endl;
            //Access raw file as binary
            ifstream rawFile(fileDirectory + baseName   + to_string(i) +  ".raw",ios::binary);

            if (rawFile.is_open()){ //Check if open
                //Create a pointer char array representing a whole Image (slice) - add pointer to this array into slices vector
                slices.push_back( (unsigned char **) new char**[height]);
                for (int j = 0; j < height; ++j) {
                    //Create a char array for each row in the image (height)
                    slices[i][j] = (unsigned char *) new char*[width];
                    for (int k = 0; k < width; ++k) {
                        //cout <<rawFile.get() <<" ";
                        //Add binary data to each element in the row
                        slices[i][j][k] = (unsigned char) char(rawFile.get());
                    }
                }
            }
            else{ //If ever can't open a raw data file - return false
                return false;
            }
            //cout << "Done with File"<<endl;
        }
       // cout<< to_string(slices[0][1][2]) << endl;
        cout <<"Loaded all Raw files"<<endl;
        return true; //If could open all files -return true
    }

    void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
        //Create a default header for new raw file
        createDefaultHeader(output_prefix);

        //Create new output raw file in binary and for writing
        ofstream outputFileOfSlice(output_prefix + ".raw",ios::out | ios::binary);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                //Calculate difference between slices
                unsigned char diffValue = (unsigned char) ( (abs( (float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j] ) )/2);
                //Write char in slice array into new slice image
                outputFileOfSlice.write((const char *) &diffValue, sizeof(char));
            }
        }
        outputFileOfSlice.close();

    }

    //Function to create a default header for any new raw data created
    void createDefaultHeader(string output_prefix) {
        fstream outputHeader;
        outputHeader.open(output_prefix + ".data",ios::out); //Create and open file for writing
        outputHeader << "1 1 1" << endl; //New default header file
        outputHeader.close();
    }


    //Method to copy a specific image slice into a new output file
    void VolImage::extract(int sliceId, std::string output_prefix) {
        //Create a header file for the new output raw
        createDefaultHeader(output_prefix);

        //Create new output raw file in binary and for writing
        ofstream outputFileOfSlice(output_prefix + ".raw",ios::out | ios::binary);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                //Write char in slice array into new slice image
                outputFileOfSlice.write((const char *) &slices[sliceId][i][j], sizeof(char));
            }
        }
        outputFileOfSlice.close();
    }

    int VolImage::volImageSize(void) {
        return 0;
    }


    int VolImage::numOfImages(void) {
        return slices.size();
    }


    int getIntFromArgument(char *argumentValue) {
        stringstream getIntFromArg(argumentValue);
        int argumentInt;
        getIntFromArg >> argumentInt;

        return argumentInt;
    }
}