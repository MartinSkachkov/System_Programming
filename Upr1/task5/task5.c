#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

if(argc == 1){
 char buff[1];
 int c=0, w=0, l=0;
 int r;

 while((r=read(0,buff,1)) > 0){
   c++;

   if(buff[0] == ' '){
     w++;
   }

   if(buff[0] == '\n'){
     l++;
     w++;
   }
 }

 printf("chars: %d\n", c);
 printf("words: %d\n", w);
 printf("lines: %d\n", l);

}else{

 char buff[1];
 int r;
 int tc=0, tw=0, tl=0;

 for(int i = 1; i < argc; i++){
  int c=0, w=0, l=0;
  int fd=open(argv[i], O_RDONLY);

  while((r=read(fd, buff,1)) > 0){
   c++;
   if(buff[0] == '\n'){
      l++; w++;
   }

   if(buff[0] == ' '){
     w++;
   }
  }

  tc+=c;
  tw+=w;
  tl+=l;

 printf("%s chars: %d\n",argv[i],c);
 printf("%s words: %d\n",argv[i],w);
 printf("%s lines: %d\n",argv[i],l);
 }

 printf("total chars: %d\n",tc);
 printf("total words: %d\n",tw);
 printf("total lines: %d\n",tl);

}

exit(0);
}
