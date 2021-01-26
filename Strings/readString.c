#include <stdio.h>


int main(void){
    char delimiters[] = " \".,;:!?)(";      // Prose delimiters  
    char buf[100];         // Buffer for a line of keyboard input  
    char str[1000];       // Stores the prose to be tokenized  
    char* ptr = NULL;    // Pointer used by strtok_s() 
    str[0] = '\0';      // Set 1st character to null
    size_t str_len = sizeof(str); 
    size_t buf_len = sizeof(buf);
    printf("Enter some prose that is less than %zd characters.\n"      
        "Terminate input by entering an empty line:\n", str_len);
    fgets(buf,buf_len,stdin);
    printf("This is what was entered: \"%s\"", buf);
    
}