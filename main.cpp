//Created by Shaaheen Sacoor - SCRSHA001
// Driver class that houses the user interface and is used to run program
///

#include <iostream>
#include <sstream>
#include <bits/unique_ptr.h>
#include "VolImage.h"

using namespace std;
using namespace SCRSHA001;

//Take in arguments from command line
int main(int argc,char* argv[]) {
    cout << "Volumetric Image Manipulation Tool - SCRSHA001" << endl;
    cout << "Available commands = -x -d -g " << endl;

    //Check if right amount of arguments
    if (argc >6 || argc < 4){
        cout << "Incorrect arguments passed (Not enough or too little found) " <<endl;
    }
    else { //right amount of arguments
        //Check if valid arguments
        if (string(argv[2]) == "-x" || string(argv[2]) == "-d" || string(argv[2]) == "-g"){
            cout <<"Arguments validated." <<endl;
            cout <<endl;
            //Done here as the each command has the same start
            VolImage *volImage = new VolImage; //Create VolImage object
            (*volImage).readImages( string (argv[1])); //Read in all Images into vector inside VolImage
            cout << "Number of images: " << (*volImage).numOfImages() <<endl;
            cout << "Number of bytes required: "<< (*volImage).volImageSize() <<endl; //todo Find out how to get the number of bytes required
            cout <<endl;
            //If command is to extract
            if (string(argv[2]) == "-x"){
                cout<<"Extract option chosen"<<endl;
                //Get variables from the command line arguments
                int indexOfFile = getIntFromArgument(argv[3]);

                stringstream getOutputFileName(argv[4]);
                string outputName;
                getOutputFileName >> outputName;

                cout<< "Extracting slice "<< indexOfFile << " into file " << outputName << ".raw"<<endl;
                volImage->extract(indexOfFile,outputName);
            }
            else if (string(argv[2]) == "-d"){
                cout<<"Difference Map option chosen"<<endl;
                //Get variables from the command line arguments
                int indexOfFile1 = getIntFromArgument(argv[3]);

                int indexOfFile2 = getIntFromArgument(argv[4]);

                stringstream getOutputFileName(argv[5]);
                string outputName;
                getOutputFileName >> outputName;

                cout <<"Differentiating slice "<<indexOfFile1<< " from slice "<< indexOfFile2<< " into new file "<<outputName<< ".raw"<<endl;
                //Call diffmap function
                volImage->diffmap(indexOfFile1,indexOfFile2,outputName);

            }
            else if (string(argv[2]) == "-g") {
                cout<<"Extracting row from whole volume option chosen [Extra Credit]"<<endl;
                int rowFromVolume = getIntFromArgument(argv[3]); //Get given row
                cout<<"Extracting row "<<rowFromVolume<< " from all slices in Volume into new file ExtraCreditOutput.raw"<<endl;
                volImage->extractRowFromVolume(rowFromVolume); //Call extractRow function
            }
            cout<<"Successful."<<endl;

            delete volImage;
        }
    }

    return 0;
}