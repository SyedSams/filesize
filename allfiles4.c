#include <stdio.h>
#include <dirent.h>

int main(void)
{
   int count = 0;
   int bytes;
   double kilobytes;

   FILE *fp;
       
    struct dirent *file;   
    DIR *dr = opendir("/home/user");
  
    if (dr == NULL)  
      {
             printf("no files is here" );
             return 0;
      }

    while ((file = readdir(dr)) != NULL)
      {
	     count++;
             printf(" %s \n",file->d_name);
	     printf("%d \n" , file->d_type);

	     fp = fopen(file->d_name, "r");

     if (fp == NULL) 
      {
	     printf("File Not Found!\n");
	     return -1;
      }
	     fseek(fp, 0L, SEEK_END);
	     long int size = ftell(fp);
     
      if (DT_DIR && (file->d_type == 8))
      
      {
	    printf("The size of the file is: %ld bytes\n", size);
              kilobytes=size/1024;
             printf("Kilobytes of the file is: %.2lf\n",kilobytes);
          
        } 
        }
             printf("Total file is:%d\n",count);
             closedir(dr);  
	     fclose(fp);  
             return 0;
}


