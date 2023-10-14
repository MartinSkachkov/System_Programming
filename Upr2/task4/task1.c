#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
int fd=open("aa1", O_RDONLY);
char buff[16];

if(fd == -1){
 printf("error in opening\n");
 exit(1);
}

for(int i = 8; i >= 1; i--){
 read(fd, buff, i);
 printf("%s\n", buff);
}

}
