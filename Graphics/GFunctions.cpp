/* *******************
 * File name : GFunctions.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    21:49
 * Brief : See GFunction.h
 * *******************
 */

#include "GFunctions.h"

/*  Function
    *@brief This function read file and saves it to variable.
    *@param const char *FileName: File name.
    *@param char **Source: Data in file.
    *@param long &Length: Length of file.
    *@retval bool: True if file is readed successly, false otherwise.
    */
bool ReadSource(const char *FileName, char **Source, long &Length)
{
	FILE *File;

	File= fopen( FileName, "rb");

	if( File == NULL)
		{
		std::cout << "Error opening file " << FileName << "\n";
		return false;
		}

    /** Set position indicator to ending of file **/
	fseek(File, 0, SEEK_END);

    /** Get current position indicator **/
	Length = ftell(File);

    /** Set position indicator to beginning of file **/
	fseek(File, 0, SEEK_SET);

    /** Allocate memory for Source object **/
	*Source = new char[Length + 1];

    /** Reading file, "1" parametr is size (1 byte) **/
	fread(*Source, 1, Length, File);

    /** Setting end of file charater (NULL) **/
	(*Source)[Length] = 0;

    /** Closing file **/
	fclose(File);

    /** Changing carriage return and new line character for 0 **/
	for(long i = 0; i < Length; i++)
        {
		if((*Source)[i] == '\r' || (*Source)[i] == '\n') (*Source)[i] = 0;
        }

	return true;
}
