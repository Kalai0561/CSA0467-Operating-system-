#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    int file_desc;
    char buffer[100],file[100];
	printf("Enter the file name : ");
	scanf("%c",&file);
    file_desc = open(file, O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if (file_desc < 0) {
        printf("Error in opening the file.\n");
        return 1;
    }

    if (write(file_desc, "Hello, World!\n", 14) != 14) {
        printf("Error in writing to the file.\n");
        return 1;
    }

    if (lseek(file_desc, 0, SEEK_SET) < 0) {
        printf("Error in lseek.\n");
        return 1;
    }
    
    if (read(file_desc, buffer, 14) != 14) {
        printf("Error in reading from the file.\n");
        return 1;
    }

    printf("Content read from file: %s", buffer);

    close(file_desc);

    return 0;
}

