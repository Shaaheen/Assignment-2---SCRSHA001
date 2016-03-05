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
        //(**slices)= nullptr;
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
        //delete slices;
        width = 0;
        height= 0;
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