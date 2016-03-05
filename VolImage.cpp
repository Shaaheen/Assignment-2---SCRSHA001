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

        string fileDirectory = "brain_mri_raws/";
        ifstream headerFile(fileDirectory + baseName + ".data");
        string headerInfo;
        getline(headerFile,headerInfo);
        stringstream streamOfHeaderInfo (headerInfo);

        int numOfFiles;
        streamOfHeaderInfo >> width;
        streamOfHeaderInfo >> height;
        streamOfHeaderInfo >> numOfFiles;

        cout <<"Gets hernkje " << (width) <<" " << height << " " << numOfFiles<<endl;

        for (int i = 0; i < numOfFiles; i++) {
            cout<< fileDirectory + baseName   + to_string(i) +  ".raw" <<endl;
            ifstream rawFile(fileDirectory + baseName   + to_string(i) +  ".raw",ios::binary);
            if (rawFile.is_open()){
                slices.push_back( (unsigned char **) new char**[height]);
                for (int j = 0; j < height; ++j) {
                    slices[i][j] = (unsigned char *) new char*[width];
                    for (int k = 0; k < width; ++k) {
                        //cout <<rawFile.get() <<" ";

                        slices[i][j][k] = (unsigned char) char(rawFile.get());
                    }
                    //cout << endl;
                   // cout << "loop" <<endl;
                }
            }
            cout << "Done with File"<<endl;
        }
        cout<< slices[0][1][2];
        cout <<"end of loop"<<endl;
        //todo Read in as in binary format
        return false;
    }

    void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {

    }

    void VolImage::extract(int sliceId, std::string output_prefix) {
        //todo extracts
    }

    int VolImage::volImageSize(void) {
        return 0;
    }


    int VolImage::numOfImages(void) {
        return slices.size();
    }
}