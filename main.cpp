#include <iostream>
#include <sstream>
#include "VolImage.h"

using namespace std;
using namespace SCRSHA001;

//Take in arguments from command line
int main(int argc,char* argv[]) {
    cout << "Hello, World!" << argc << endl;

    //Check if right amount of arguments
    if (argc >6 || argc < 5){
        cout << "Incorrect arguments passed (Not enough or too little found) " <<endl;
    }
    else { //right amount of arguments
        //Check if valid arguments
        if (string(argv[2]) == "-x" || string(argv[2]) == "-d" || string(argv[2]) == "-x"){
            cout << "Correc"<<endl;
            //Done here as the each command has the same start
            VolImage *volImage = new VolImage; //Create VolImage object
            (*volImage).readImages( string (argv[1])); //Read in all Images into vector inside VolImage
            cout << "Number of images: " << (*volImage).numOfImages() <<endl; //todo where to get this value
            cout << "Number of bytes required: "<< (*volImage).volImageSize() <<endl; //todo Find out how to get the number of bytes required

            //If command is to extract
            if (string(argv[2]) == "-x"){

                //Get variables from the command line arguments
                int indexOfFile = getIntFromArgument(argv[3]);

                stringstream getOutputFileName(argv[4]);
                string outputName;
                getOutputFileName >> outputName;

                volImage->extract(indexOfFile,outputName);
                cout << "Argv[3]: " << (indexOfFile + 1)<< " " << outputName <<endl; //todo CANT DO int(argv[3])
            }
            else if (string(argv[2]) == "-d"){
                //Get variables from the command line arguments
                int indexOfFile1 = getIntFromArgument(argv[3]);

                int indexOfFile2 = getIntFromArgument(argv[4]);

                stringstream getOutputFileName(argv[5]);
                string outputName;
                getOutputFileName >> outputName;

                volImage->diffmap(indexOfFile1,indexOfFile2,outputName);
            }
        }
    }
    return 0;
}