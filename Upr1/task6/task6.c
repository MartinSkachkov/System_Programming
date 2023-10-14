#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

if(argc != 2){
 printf("Usage: head file");
 exit(1);
}

int fd=open(argv[1], O_RDONLY);
if(fd == -1){
 printf("Couldn't open the file $s", argv[1]);
 exit(1);
}

int lines = 1;
char buff[1];
int r;

while(lines <=10){
 while((r=read(fd,buff,1)) > 0){
  if(write(1,buff,r) != r){
    printf("error in writing");
    exit(1);
  }

  if(buff[0] == '\n'){
    lines++;
    if(lines > 10){
	break;
    }
  }
 }

 lines++;
}

exit(0);
}
