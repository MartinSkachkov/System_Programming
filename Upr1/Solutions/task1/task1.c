#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
int fd1=open(argv[1], O_RDONLY);
int fd2=open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

if(argc != 3){
 printf("Usage: cp .. ..");
 exit(1);
}

if(fd1 == -1){
 printf("Couldn't open file $f", argv[1]);
 exit(1);
}

if(fd2 == -1){
 printf("Couldn't open file $f", argv[2]);
 exit(1);
}

char buff[512];
int r;

while((r=read(fd1,buff,512)) != 0){
 if(write(fd2,buff,r) != r){
   printf("error in writing");
   exit(1);
 }
}

exit(0);
}
