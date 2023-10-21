#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
int fdi, fdo,k,broi,i=0,status;
char buff[40],c;

if((fdi=open("fff",O_RDWR)) == -1){
printf("\n Cannot open\n");
exit(1);
}

read(fdi,buff,7);
write(1,buff,7);
write(1,"hap",3);
write(fdi,"teacher",7);
write(1,"py child",8);

}
