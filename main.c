
#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>

#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/vfs.h>

typedef enum { false, true } bool;

int main (int argc, char *argv[])
{
    struct mntent *ent;
    struct statfs vfs;
    FILE *aFile;
    bool first = true;

    aFile = setmntent("/etc/fstab", "r");
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

        printf("{ mountpoint: \"%s\", total: %ld, free: %ld, type: \"%s\", fsname: \"%s\", fsopts: \"%s\" }",
          ent->mnt_dir, ( vfs.f_bsize * vfs.f_bfree ), ( vfs.f_bsize * vfs.f_blocks ), ent->mnt_type, ent->mnt_fsname, ent->mnt_opts );
      }
    }

    printf("]\n");
    endmntent(aFile);
    return 0;
}
