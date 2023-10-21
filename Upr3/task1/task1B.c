#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]){
int fd1 = open("fff2", O_RDONLY | O_CREAT, 0644);
int fd2 = open("fff2", O_WRONLY);
int fd3 = open("fff2", O_RDWR);

if(fd1 == -1 || fd2 == -1 || fd3 == -1){
 printf("error in opening the file\n");
 exit(1);
}

char buff[15];

write(fd3, "Hello", 5);
write(fd2, "worlds", 6);

int r1=read(fd1, buff, 6);
write(1, buff, r1);

close(fd2);

write(fd3, "oops", 4);

int r2=read(fd1, buff, 6);
write(1, buff, r2);
}
