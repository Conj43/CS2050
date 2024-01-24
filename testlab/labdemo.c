#include "labdemo.h"
/* REQUIRED CODE GOES HERE */
/*
This function prints the values in between min_val
and max_val. It returns 0 in success and -1 in error.
*/
int printNumbers(int min_val, int max_val) {
if(min_val<max_val){
printf("Printing:\n");
}else{
printf("Check your parameters!");
return -1;
}
for(int i=min_val;i<max_val;i++){
printf("%d\n",i);
}
return 0;
}