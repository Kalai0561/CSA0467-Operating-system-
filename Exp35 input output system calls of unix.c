#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int file_desc;
    char buffer[100];
    struct stat file_stat;
    DIR *dir;
    struct dirent *dir_entry;

    file_desc = open("test.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
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

    if (fstat(file_desc, &file_stat) < 0) {
        printf("Error in fstat.\n");
        return 1;
    }
    printf("File size: %ld\n", file_stat.st_size);

    close(file_desc);

    dir = opendir(".");
    if (dir == NULL) {
        printf("Error in opening the directory.\n");
        return 1;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    closedir(dir);

    return 0;
}

