#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
int writer(const char* writefile, const char* writestr){
    //open syslog for debug
    openlog(NULL, 0, LOG_USER);
    int return_value_int = 0;
    //check the arguments
    if(writefile == NULL){
        //print warning or error
        printf("Error: invalid path file\n");
        return_value_int = 1;
        syslog(LOG_ERR, "Error: Invalid path file\n");
    }
    else {
        if(writestr == NULL){ // if the string is null, assume that there is no content to write to the file
            printf("Warning: writestring is empty, no content to be written to file\n");
        }
        //find the file
        int file_descriptor_int = 0;
        file_descriptor_int = open(writefile, O_RDWR | O_CREAT | O_TRUNC, 0777);
        if (file_descriptor_int == -1){ // error in open, create the file
            printf("Error: cannot open the specified file, please check the file path again\n");    
            perror("Return error");
            return_value_int = 1;
            syslog(LOG_ERR, "Error: Cannot get the file path\n");
        }
        else {
            printf("The file has been opened successfully\n");
            //write the file with writestr
            size_t writestr_len_u32 = strlen(writestr);
            ssize_t nr_32 = 0;
            nr_32 = write(file_descriptor_int, writestr, writestr_len_u32);
            if (nr_32 == -1)
            {
                printf("Error while writing content to the file");
                perror("Returned eroor");
                syslog(LOG_ERR, "Error: Cannot writing to the file\n");
                return_value_int = 1;
            }
            else {
                printf("Writing successfully\n");
                syslog(LOG_DEBUG, "Writing successfully\n");
            } 
        }
    }
    closelog();
    return return_value_int; 
}

int main(int argc, char* argv[])
{
	//create variable
	int return_value_int = 0;
	//check the number of arguments
	if(argc != (int)3){
		printf("Error: invalid number of arguments.\n"
			"The number of arguments should be 2.\n"
			"The order of arguments should be: \n"
			"1. The path of the file you want to create (place in the "")\n"
			"2. The string or content you want to write to the file (place in the "")\n");
		openlog("writer program", 0, LOG_USER);
		syslog(LOG_ERR, "Error: invalid numbers of arguments\n");
		closelog();
		return_value_int = 1;
	}
	else{
		//create variables
		char* writefile_char_ptr = argv[1];
		char* writestr_char_ptr = argv[2];
		//call the write function
		return_value_int = writer(writefile_char_ptr, writestr_char_ptr);
	}
	return return_value_int; 
}