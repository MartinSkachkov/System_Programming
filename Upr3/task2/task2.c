#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
int fd1 = open("f1", O_RDONLY);
int fd2 = open("f1", O_WRONLY);

if(fd1 == -1 || fd2 == -1){
 printf("error in opening the file\n");
 exit(1);
}

lseek(fd2, -3, SEEK_END);
write(fd2, "wxyz", 4);

lseek(fd2, 4, 0);
write(fd2, "12", 2);
 
char buff[15];
int r;

while((r=read(fd1, buff, 15)) > 0){
 if(r != write(1, buff, r)){
   printf("error in printing\n");
   exit(1);
 }
}
}
