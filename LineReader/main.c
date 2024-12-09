#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
    int fd;
    fd = open("test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}
// void run_tests() {
//     int fd;
//     char *line;

//     // Test 1: Normal case with multiple lines
//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("Error opening file");
//         return;
//     }
    
//     printf("Test 1: Normal case\n");
//     while ((line = get_next_line(fd))) {
//         printf("%s", line);
//         free(line); // Free the allocated memory for each line
//     }
//     close(fd);
    
//     // Test 2: Read from an empty file
//     fd = open("empty.txt", O_RDONLY); // Make sure this file exists and is empty
//     if (fd < 0) {
//         perror("Error opening empty file");
//         return;
//     }
    
//     printf("\nTest 2: Empty file\n");
//     line = get_next_line(fd);
//     if (line == NULL) {
//         printf("No lines to read (as expected).\n");
//     }
//     free(line);
//     close(fd);

//     // Test 3: Read until EOF
//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("Error opening file");
//         return;
//     }
    
//     printf("\nTest 3: Read until EOF\n");
//     while ((line = get_next_line(fd))) {
//         printf("%s", line);
//         free(line);
//     }
    
//     close(fd);

//     // Test 4: Check behavior with BUFFER_SIZE = 1
//     // #define BUFFER_SIZE 1
//     // fd = open("test.txt", O_RDONLY);
    
//     // printf("\nTest 4: BUFFER_SIZE = 1\n");
//     // while ((line = get_next_line(fd))) {
//     //     printf("%s", line);
//     //     free(line);
//     // }
    
//     // close(fd);

// }

// int main() {
//     run_tests();
    
//     return 0;
// }