#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STRING_IMPLEMNT
#include "String.h"


int main()
{
    char *str = "    Luis    ";

    String *s =newString(str);
    
    String *ls =TrimLeft(s);

    String *rs =TrimRight(s);

    String *ts =Trim(s);

    String *us =UpperString(s);

    String *los  = LowerString(s);
    



printf("Original [%s] (%d)\n", s->str,s->size);
printf("Ltrim    [%s] (%d)\n",ls->str,ls->size);
printf("Rtrim    [%s] (%d)\n",rs->str,rs->size);
printf("Trim     [%s] (%d)\n",ts->str,ts->size);
printf("Upper    [%s] \n",us->str);
printf("Lower    [%s] \n",los->str);


String **list = SplitString(newString("luis|miguel|rosa|dos|santos"),"|");
int i=0;
printf("Split\n");
while(list[i])
{
    printf("[%s] (%d)\n", list[i]->str,i);
    i++;
}

String *j =JoinString(list," ");

free(list);

printf("Join    [%s] \n",j->str);

if (StringEndsWith(newString("google.com"),".com"))
    printf(" ends with (.com)\n");
else
    printf("don't wnds with (.com)\n");

if (StringStartsWith(newString("www.google.com"),"www."))
    printf(" start with (www)\n");
else
    printf("don't start with (www)\n");


if (StringFind(newString("luis miguel rosa dos santos"),newString("rosas")))
    printf("find (txt)\n");
else
    printf("din't find(txt)\n");


String *sub=SubString(newString("luis miguel rosa dos santos"),5,6);

printf("Sub string (%s) \n",sub->str);



free_strings();

  

    return 0;
}


