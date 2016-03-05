//
// Created by Shaaheen on 3/4/2016.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "VolImage.h"

using namespace std;

namespace SCRSHA001{


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