#include <sys/stat.h>

int main()
{
    // Change file permissions
    chmod("file.txt", 0666);

    // Read file permissions
    struct stat st;
    stat("file.txt", &st);
    int permissions = st.st_mode & 0777;
}

