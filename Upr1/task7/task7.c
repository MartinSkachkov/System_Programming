#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
char buff[3];
int char_counter = 0;

// четем m и n и от string -> int (./cut m n file)
int m=atoi(argv[1]);
int n=atoi(argv[2]);
int fd=open(argv[3], O_RDONLY);

if(fd == -1){
 printf("error in opening the file\n");
 exit(1);
}

while(read(fd, buff, 1) > 0){
 // свършили сме с този ред
 if(buff[0] == '\n'){
   write(1, "\n", 1);
   char_counter = 0;
 }else{ // местим да cut-нем по-навътре
   char_counter++;
 }

 // в зоната за cut сме
 if(char_counter >= m && char_counter <= n){
   write(1, buff, 1);
 }

}

}
