#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>

int main(){
  printf("Statistics for directory: .\n");

  struct stat buf;
  stat(".",&buf);

  printf("Total Diectory Size: %lu Bytes\n",buf.st_size);

  DIR *dir = opendir(".");

  struct dirent *entry = readdir(dir);
  while (entry != NULL){
    if (entry->d_type &DT_DIR){
      printf("Directory | ");}
    else {
      printf("Regular File | ");}
    printf("%s\n", entry->d_name);
    entry = readdir(dir);
  }

  closedir(dir);
  return 0;
}
