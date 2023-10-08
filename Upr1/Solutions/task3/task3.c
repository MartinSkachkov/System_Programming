#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
int fd1=open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
char buff[512];
int r;

if(argc != 2){
 printf("Usage: ./task3 file");
 exit(1);
}

while((r=read(0,buff,512)) != 0){
 if(write(fd1,buff,r) != r){
   printf("error in writing");
   exit(1);
 }
}

exit(0);
}

