
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mntent.h>

#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/vfs.h>

#define APP_VERSION   "0.0.3"
#define REPO_URL      "https://github.com/GentooXativa/json-disk"

typedef enum { false, true } bool;

int extractInfo( const char *filename ){
  struct mntent *ent;
  struct statfs vfs;
  FILE *aFile;
  bool first = true;

  aFile = setmntent(filename, "r");
  if (aFile == NULL) {
    perror("setmntent");
    exit(1);
  }

  printf("[");
  while (NULL != (ent = getmntent(aFile))) {
    statfs(ent->mnt_dir, &vfs);      
    
    if(vfs.f_blocks > 0 ){
      if( first != true ){
        printf(",");
      }else{
        first = false;
      }

      printf("{ \"mountpoint\": \"%s\", \"free\": %ld, \"total\": %ld, \"type\": \"%s\", \"fsname\": \"%s\", \"fsopts\": \"%s\" }",
        ent->mnt_dir, ( vfs.f_bsize * vfs.f_bfree ), ( vfs.f_bsize * vfs.f_blocks ), ent->mnt_type, ent->mnt_fsname, ent->mnt_opts );
    }
  }

  printf("]\n");
  endmntent(aFile);
  return 0;
}

int main (int argc, char *argv[])
{
  int i;
  char *fname = "/etc/fstab";

   /* iterate over all arguments */
   for (i = 0; i < argc; i++) {
    if (strcmp("-h", argv[i]) == 0) {
      printf("JSON-DISK v%s\n%s\n\n", APP_VERSION, REPO_URL );
      printf("Usage: json_disk [-h] [-m]\n");
      printf("\t-h\tShow this help\n");
      printf("\t-m\tUse /etc/mtab instead of /etc/fstab\n");
      return 0;
   }
   
   if (strcmp("-m", argv[i]) == 0) {
    fname = "/etc/mtab";
    continue;
 }
 
}  
  return extractInfo(fname);

}
