Hey :)

To run: 
    1) Go into directory from terminal
    2) Run "make" command in terminal to compile the program
    3) run ./volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i] command from terminal
	(<imageBase> is the prefix name for all the raw files i.e MRI)
	4) Program should create a new raw data file in the same directory
	
eg: ./volimage MRI -d 5 7 differenceMapOutput
	
Choose only one of the arguments above; either -d, -x or -g.

EXTRA CREDIT
-g i :
		-g = extracts a row from the whole volume
		i = row that is going to be extracted

NORMAL
-d i j output_file_name :
						-d = differenceMap (Shows the differences between two raw files
						i = index of first file ;
						j = index of second file
						output_file_name = name of the output file that will be created

-x i output_file_name:
						-x = extract (Copies the raw data of a chosen file into a new raw data file)
						i = index of raw data file
						output_file_name = name of the output file that will be created

VolImage.cpp :
	Implementation of the VolImage class 
	Allows for operations - extract, -diffMap, -extractRowFromVolume
	
main.cpp:
	Driver class to run program

VolImage.h:
	Header file for the VolImage class declarations