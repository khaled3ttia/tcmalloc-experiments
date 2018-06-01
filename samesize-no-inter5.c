#include <stdio.h>
#include <stdlib.h>
#define k (50)
#define PAGE_SIZE (4*1024)

int main(int argc, char **argv){


    int sz1=0, sz2=0, sz3=0, sz4=0, sz5=0;
    int ps1=0, ps2=0, ps3=0, ps4=0, ps5=0;
    int pn1=0, pn2=0, pn3=0, pn4=0, pn5=0;

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
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100),pn4,ps4,(((float)ps4/(float)PAGE_SIZE)*100)); 

    sz4 = k;
    char* p3 = malloc(sz4);
    printf("Created a string with size: %d and address: %p and page number is %d\n", sz4, p3, (int)p3>>12);
    pn4 = (int)p3 >> 12;    
    if (pn1 == pn4) {
	ps1 += sz4;
    }else if (pn2 == pn4) {
 	ps2 += sz4;
    }else if (pn3 == pn4) {
        ps3 += sz4;
    }
    else {
	ps4 = sz4;
    }

  
    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100),pn4,ps4,(((float)ps4/(float)PAGE_SIZE)*100));  


    sz5 = k;
    char* p4 = malloc(sz5);
    printf("Created a string with size: %d and address: %p and page number is %d\n", sz5, p4, (int)p4>>12);
    pn5 = (int)p4 >> 12;    
    if (pn1 == pn5) {
	ps1 += sz5;
    }else if (pn2 == pn5) {
 	ps2 += sz5;
    }else if (pn3 == pn5) {
        ps3 += sz5;
    }else if (pn4 == pn5) {
    	ps4 += sz5;
    }
    else {
	ps5 = sz5;
    }
 
    printf("\npage:      allocated_space\n");
    printf("%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n%d:      %d(%f%)\n",pn1,ps1,(((float)ps1/(float)PAGE_SIZE)*100),pn2,ps2,(((float)ps2/(float)PAGE_SIZE)*100),pn3,ps3,(((float)ps3/(float)PAGE_SIZE)*100),pn4,ps4,(((float)ps4/(float)PAGE_SIZE)*100),pn5,ps5,(((float)ps5/(float)PAGE_SIZE)*100));  

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

    free(p3);

    free(p4);
 
    return 0;
}
