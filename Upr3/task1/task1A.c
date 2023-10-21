#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]){
int fd1 = open("fff1", O_RDONLY | O_CREAT, 0644);
int fd2 = open("fff1", O_WRONLY);
int fd3 = open("fff1", O_RDWR);

if(fd1 == -1 || fd2 == -1 || fd3 == -1){
 printf("error in opening the file\n");
 exit(1);
}

char buff[15];

write(fd2, "Hello world", 11);

int r1=read(fd3, buff, 6);
write(1, buff, r1); 

int r2=read(fd1, buff, 5);
write(1, buff, r2);

write(fd3, "chil", 4);
write(fd2, "!!!", 3);

int r3=read(fd1, buff, 9);
write(1, buff, r3);
}

