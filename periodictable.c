#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Function prototypes*/

int get_option(void);
int atomic_number(void);
int atomic_symbol(void);
int atomic_name(void);
int atomic_weight(void);
char block(int);
char property(int);
void show (int, char, char);

/*Global Array Declarations and initialization.*/

char name [40] [10]={"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Flourine", "Neon", "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc","Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton","Rubidium", "Strontium", "Yttrium", "Zirconium"};

char symbol [40] [10]={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne","Na", "Mg", "A1", "Si", "P", "S", "Cl", "Ar","K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr","Rb", "Sr", "Y", "Zr"};

 double weight[40]={1.00,4.00,6.94,9.01, 10.81,12.01, 14.00, 16.00, 19.00, 20.18, 23.00, 24.31, 26.99, 28.08, 30.97, 32.06,35.45,39.09,39.94,51.99,54.93,55.84,58.69,58.93,63.54,65.39,69.7,72.64,74.92,78.96,79.90,83.80,85.46,87.62,88.90,91.22);

/*Main method*/

3int main(void)
{
int i=99, option;
do{
option=get_option();
char ch1, ch2;
switch (option)
{
   case 1: i=atomic_number();
           break;
   case 2: i=atomic_symbol(); 
           break;
   case 3: i-atomic_name();
           printf("%d", i); 
           break;
   case 4: i=atomic_weight();
           break;
   case 5: return (0);
   default: system("cls");
}           printf("\n\n\t\t\t\tInvalid option!\n");
if (i== -1)
{
system("cls");
printf("\n\n\t\t\t\tInvalid option!\n");
}
[*] Untitled1

57

58

system("cls");

printf("\t\t\t\t\t\t\t\t\tWrong Choice !\n");
}
else if (i==99)
continue;
else
{
system("cls");
ch1=block(i);
ch2=property(i);
show(i, ch1, ch2);
}
i=99;
}
while (option!=5);
return (0);
}

/*Gets the choice of search from the user*/

int get_option(void)
{
int option;
printf("\n\nEnter the corresponding number:\n\n");
printf("1. Search by ATOMIC NUMBER\n");
printf("2. Search by ATOMIC SYMBOL\n");
printf("3. Search by ATOMIC NAME\n");
printf("4. Search by ATOMIC WEIGHT\n");
printf("5. QUIT\n");
printf("\nEnter Your Choice: ");
scanf("%d",&option);
return option;
}

/*Method to search element by atomic number*/

int atomic_number(void)
{
int n;
printf("\nEnter the Atomic Number you want to search for: ");
scanf("%d",&n);
n--;
if (n>=0 && n<40)
   return n;
else
   return -1;
}

/*Method to search element by atomic name*/

int atomic_name(void)
{
char x[40];
int i, flag=0;
printf("\nEnter the Atomic Name you want to search for: ");
scanf("%s",x);
for (i=0;i<40;i++)
{
if (strcmp(x,name[i])==0)
{
flag=1;
break;
}
}
if (flag==1)
return i;
else
return -1;
}

/*Method to search element by atomic symbol*/

int atomic_symbol(void)
{
char x[40];
int i, flag=0;
printf("\nEnter the Atomic Symbol you want to search for: ");
scanf("%s",x);
for (i=0;i<40;i++)
{
if (strcmp(x, symbol[i])==0)
{
flag=1;
break;
}
}
if (flag==1)
return i;
else
return -1;
}

 /*Method to search element by their corresponding atomic weight */

int atomic_weight(void)
{
double x;
int i, flag=0;
printf("\nEnter the Atomic Weight you want to search for: ");
scanf("%f",&x);
for (i=0;i<40;i++)
{
if (weight[i]==x)
{
flag=1;
break;
}
}
if (flag==1)
return i;
else
return -1;
}

 /*Method to find the block in which the element falls*/

char block(int i)
{
char ch=' ';
int n=i+1;
if(n==1 || n==3 || n==4 || n==11 || n==12 || n==19 || n==20 || n==37 || n==38)
ch = 's';
else if(n==2 || (n>=5 && n<=10) || (n>=13 && n<=18) || (n>=31 && n<=36))
ch = 'p';
else if((n>=21 && n<=30) || (n>=39 && n<=48))
ch = 'd';
else
ch='f';
return ch;
}
 /*Method to find the metallic property of the element*/

char property (int i)
{
int n=i+1;
char ch=' ';
if (n==1 || n==2 || (n>=6 && n<=10) || (n>=15 && n<=18) || (n>=34 && n<=36))
ch='n';
else if (n==5 || n==14 || n==32 || n==33)
ch='s';
else
ch='m';
return ch;
}

/*Displays the search result*/

void show(int i, char ch1, char ch2)
{
printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
 printf("\n\t\t\t\t\tAtomic Number : %d\n", (i+1));
printf("\t\t\t\t\tAtomic Symbol:%s\n",symbol[i]);
 printf("\t\t\t\t\tAtomic Name : %s\n",name[i]);
printf("\t\t\t\t\tAtomic Weight : %.2f\n", weight[i]);
printf("\t\t\t\t\tBlock : %c\n",ch1);
if (ch2=='n')
printf("\t\t\t\t\tMetallic property: ");
printf("Non-Metal\n");
else if (ch2=='s')
printf("Metalloid\n");
else
printf("Metal\n");
printf("\n\t\t\t\t\t\tThank You ! \n\n\n");
}
