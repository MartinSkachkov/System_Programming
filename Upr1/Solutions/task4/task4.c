#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
char buff[512];
int r;

if(argc == 1){
 while((r=read(0,buff,512)) > 0){
  if(write(1,buff,r) != r){
    printf("error in writing");
    exit(1);
  }
 }
}

//if(argc < 2){
// printf("Usage: tee f1 .. fN");
// exit(1);
//}

if(argc > 1){

//отваряме всички файлове за писане
int num_files = argc-1;
int fd[num_files];

for(int i = 1; i < argc; i++){
  fd[i-1]=open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if(fd[i-1] == -1){
    printf("error in opening $s", argv[i]);
    exit(1);
  }
}

//прочитаме от стандартния вход и записваме във всички файлове
while((r=read(0,buff,512)) > 0){
  for(int i = 0; i < num_files; i++){
    int w=write(fd[i],buff,r);
    if(r != w){
      printf("error in writing");
      exit(1);
    }
  }
}

}
exit(0);
}
