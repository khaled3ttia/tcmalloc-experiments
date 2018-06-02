#include <stdio.h>
#include <stdlib.h>
#define k (60)
#define PAGE_SIZE (4*1024)

int main(){
    int sz1=0, sz2=0, sz3=0;
    int ps1=0, ps2=0, ps3=0;
    int pn1=0, pn2=0, pn3=0;

    sz1 = k;
    char* p = malloc(sz1);
    printf("Created a string with size: %d and address: %p and page number is %d\n", sz1, p, (int)p>>12);
    pn1 = (int)p >> 12;
    ps1 = sz1;
	

    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 
    sz2 = k;
    char* p1 = malloc(sz2);
    printf("Created a string with size: %d and address: %p and page number is %d\n", sz2, p1, (int)p1>>12);
    pn2 = (int)p1 >> 12;
    if (pn1 == pn2) {
	ps1 += sz2;
    }else {
	ps2 = sz2;
    }


    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 

    sz3 = k;
    char* p2 = malloc(sz3);
    printf("Created a string with size: %d and address: %p and page number is %d\n", sz3, p2, (int)p2>>12);
    pn3 = (int)p2 >> 12;    
    if (pn1 == pn3) {
	ps1 += sz3;
    }else if (pn2 == pn3) {
 	ps2 += sz3;
    }else {
	ps3 = sz3;
    }

  
    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 

    free(p);
    printf("Freed string at location: %p and page number %d\n", p , (int)p>>12);
    ps1 -= sz1; 


    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 

    free(p1);
    printf("Freed string at location: %p and page number %d\n", p1 , (int)p1>>12);
    ps2 -= sz2;


    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 
    free(p2);
    printf("Freed string at location: %p and page number %d\n", p2 , (int)p2>>12);
    ps3 -= sz3;


    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100));  
 
    return 0;
}
