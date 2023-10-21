#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
int line = atoi(argv[1]);
int fd = open(argv[2], O_RDONLY);
char buff[2];

if(fd == -1){
 printf("error in opening the file\n");
 exit(1);
}

int counter = 1; // counter for the current line
bool done = false;
bool one_print = true;

while(read(fd, buff, 1) > 0){
 if(buff[0] == '\n'){
   counter++;
 }

 if(counter == line){
   if(line == 1 && one_print){ // don't skip the first symbol of line 1 
     write(1, buff, 1);
     one_print = false;
   }

   while(read(fd, buff, 1) > 0){
     if(buff[0] == '\n'){
        write(1, buff, 1);
	done = true;
	break;
     }else{
        write(1, buff, 1);
     }
   }
 }

 if(done){
   break;
 }

}
}
