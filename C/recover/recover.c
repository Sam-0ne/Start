#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    // Create buffer to read into source file
    BYTE buffer[512];

    // Open file on command line argument
    FILE *infile = fopen(argv[1], "r");

    // Check for successful input file open
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Initialize a file_count variable
    int file_count = -1;

    // Initialize a filename variable
    char file_name[8];

    // Initialize output FILE variable, pointing to null
    FILE *output = NULL;

    // Read through file and loads on to buffer
    while (fread(&buffer, 512, 1, infile))
    {

        // If initial bytes correspond to a new jpeg file identification
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // Close previous output file if variable is pointing to a file
            if (output != NULL)
            {
                fclose(output);
            }

            // Add to the file counter
            file_count++;

            // Generate new jpeg filename
            sprintf(file_name, "%03i.jpg", file_count);

            // Open new file with file_name
            output = fopen(file_name, "w");

            // Check for successful output file open
            if (output == NULL)
            {
                printf("Could not open outputfile.\n");
                return 3;
            }
        }

        // Write data to file if variable is pointing to a file
        if (output != NULL)
        {
            fwrite(&buffer, 512, 1, output);
        }
    }

    // After data read close output file if variable is pointing to a file
    if (output != NULL)
    {
        fclose(output);
    }

    // Close input file
    fclose(infile);
}
