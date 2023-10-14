#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
int fd=open(argv[1], O_RDONLY);
char buff[15];
int r;

if(argc == 1){
 printf("need options\n");
 exit(1);
}

if(fd == -1){
 printf("error in opening\n");
 exit(1);
}

while((r=read(fd, buff, 10)) > 0){
 if(r != write(1, buff, r)){
  printf("error in writing\n");
  exit(1);
 }

 printf("\n");
}

}
