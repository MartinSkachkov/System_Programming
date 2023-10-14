#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
int fd=open(argv[1], O_RDONLY);
char buff[16];

if(fd == -1){
 printf("error in opening\n");
 exit(1);
}

for(int i = 5; i >= 1; i--){
 printf("Executing wc -c command...\n");  
 execlp("wc", "wc", "-c", argv[1], 0);
}

}
