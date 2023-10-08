#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
char buff[512];
int r;

if(argc != 1){
 printf("cat without params");
 exit(1);
}

while((r=read(0,buff,512)) != 0){
 if(write(1,buff,r) != r){
   printf("error in writing");
   exit(1);
 }
}

exit(0);
}
