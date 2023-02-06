#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    //FILE *file;
    int counter = 3;
    char *buffer = NULL;
    int bufferSize = 0;
    //char *textFile;

    if (argc > 3){
        printf("Too many arguments provided\n");
        return 0;
    }
    if(argc > 2 && (strcmp(argv[1], "-n") == 0)){
        counter = atoi(argv[2]);
        //textFile = argv[3];
    }

    //file = fopen(textFile, "rb+"); //open for reading (b+ because of line end)

    /*check if file exists
    if(!file){
        printf("Error opening file %s\n", textFile);
       return 1;
    }*/

    //start reading file from the end
    fseek(stdin, 0, SEEK_END); //take the file pointer to the end of the file, with offest of 0
    int lenght = ftell(stdin);
    int size = lenght;

    fseek(stdin, -1, SEEK_CUR); //move the file pointer 1 character back
    buffer = malloc(sizeof(char*) * bufferSize);

    while(lenght > 0){
        char c = fgetc(stdin); //read next character

        //printf("%c", c);

        if((c == '\n' || c == '\0') && lenght == size){
            //do not add anything to buffer
            size--;
        }else{
            //check if it encounters change of line
            if(c == '\n' || c == '\0'){
                counter--;
            }

            buffer[bufferSize] = c;
            bufferSize++;
            lenght--;

            if(counter == 0)
                break;

            buffer = realloc(buffer, bufferSize* sizeof(char*));

        }

        fseek(stdin, -2, SEEK_CUR); //keep moving file pointer back. -2 because fgetc moves by +1

    }

	if(lenght == 0){
		bufferSize -= 3;
    }

    for(int i = (bufferSize-2); i > 0; i--){
        printf("%c", buffer[i]);
    }

    printf("\n");

    free(buffer);
    fflush(stdin);
    //fclose(file); //release memory

    return 0;
}
