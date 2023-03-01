#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct String
{
    int size;
    char *str;
    struct String *next;
}String;

int ft_isSpace(char c)
{
    return (c==32) || (c >=9 && c<=13);
}

int ft_size(const char* str)
{
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;        
}

char *ft_strdup(const char *str)
{
    int size = ft_size(str)+1;
    char *s = malloc(size *sizeof(char));
    int i=0;
    while (str[i]!='\0')
    {
        s[i]=str[i];
        i++;
    }
   s[i]='\0';
   return s;
}
String *root =NULL;


String *newString(const char* str)
{
   String *n = malloc(sizeof(String));
   n->next=NULL;
   n->size = ft_size(str);
   n->str  = ft_strdup(str);
    if (root==NULL)
        root=n;
     else
     {
        n->next=root;
        root=n;
     }
   return n;
}

String *copyString(String *s)
{
    if (!s)
        newString("");
    if (!s->str)
        newString("");

    return newString(s->str);
}

String *Trim(String *s)
{
    char buffer[256]={0};
    int i=0;
    int j=0;
    if (!s)
        return newString("null");
    if (!s->str)
        return newString("null");
    while (s->str[i])
    {
         if (!ft_isSpace(s->str[i])) 
         {
             buffer[j]=s->str[i];
             j++;
         }
        i++;
    }
    buffer[j] = '\0';
    return newString(buffer);
}

String *TrimLeft(String *s)
{
    char buffer[256]={0};
    int i=0;
    int j=0;
    if (!s)
        return newString("null");
    if (!s->str)
        return newString("null");

    while(s->str[i] && ft_isSpace(s->str[i]))
        i++;
    while (s->str[i])
    {
        buffer[j]=s->str[i];
        j++;
        i++;
    }
    buffer[j] = '\0';
    return newString(buffer);
}

String *TrimRight(String *s)
{
    char buffer[256]={0};
    if (!s)
        return newString("null");
    if (!s->str)
        return newString("null");

    
    int last = s->size-1;
    while(last > 0)
    {
        if (!ft_isSpace(s->str[last]))
            break;
        last--;
    }
    int i=0;
    int j=0;
    last++;
    while (i < last)
    {
        buffer[j] = s->str[i];
        j++;
        i++;
    }
    
    buffer[j] = '\0';
    return newString(buffer);
}

String *UpperString(String *s)
{
    char buffer[256]={0};
    if (!s)
        return newString("null");
    if (!s->str)
        return newString("null");
    int i=0;
    while(s->str[i] !='\0')
    {
        char c =  s->str[i];
        if (c >= 97 && c <= 122)
            buffer[i] =  c - ('a' - 'A');
        else
            buffer[i] =  c;
        i++;
    }
    buffer[i] = '\0';
    return newString(buffer);
}

String *LowerString(String *s)
{
    char buffer[256]={0};
    if (!s)
        return newString("null");
    if (!s->str)
        return newString("null");
    int i=0;
    while(s->str[i] !='\0')
    {
        char c =  s->str[i];
        if (c >= 65 && c <= 90)
            buffer[i] =  c + ('a' - 'A');
        else
            buffer[i] =  c;
        i++;
    }
    buffer[i] = '\0';
    return newString(buffer);
}

unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}


int count_delim(const char* src, const char*delim)
{
    int i=0;
    int count=0;
    int k=0;
    int len = ft_size(delim);
    while(src[i])
    {
        if(is_delim(src[i], delim))
        {
            k++;
            i++;
            continue;
        }
        if (k==len)
        {
            count++;
            k=0;
        }
        i++;
    }
    return count;
}

char *StrTok(const char *src, char *delim)
{
    static char *backup_string;
    char * srcString = src;
    if(!srcString)
        srcString = backup_string;
    while(1)
    {
        if(is_delim(*srcString, delim))
        {
            srcString++;
            continue;
        }
        if(*srcString == '\0')
            return NULL; 
        break;
    }
    char *ret = srcString;
    while(1)
    {
        if(*srcString == '\0')
        {
            backup_string = srcString;
            return ret;
        }
        if(is_delim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
    return NULL;
}



String ** SplitString(String *s, const char* delim)
{
    int count =0;
    int i = 0;
    int j= 0;
    int index=0;
    const char *str = s->str;
    count = count_delim(str, delim) ;
    String **list =(String**) malloc((count + 2) * sizeof(String*));
    char *token = StrTok(str, delim);
    while(token)
    {
        list[index] = newString(token);
        index++;
        token = StrTok(NULL, delim);
    }
    list[index]=NULL;
    return list;
}

String *JoinString(String **s,const char* delim)
{
    int len =0;
    int index=0;
    int count=0;
    int i=0;
    int j=0;
    int d_size=ft_size(delim);
    char buffer[512] ={'\0'};
    while(s[index])
    {
        count++;
        index++;
    }
    index=0;
    while(s[index])
    {
        len += s[index]->size;
        const char *str = s[index]->str;
        i=0;
        while(str[i])
        {
            buffer[j]=str[i];
            j++;
            i++;
        }
        if (d_size>=1 && index < count-1)
        {   
            i=0;
            while(delim[i])
            {
                buffer[j]=delim[i];
                j++;
                i++;
            }
        }
        index++;
    }
    buffer[j] ='\0';
    return newString(buffer);
}


void free_strings()
{
    if (!root)
        return;
    String * current;
    String * next;
    current = root;
    while (current)
    {
        next = current->next;
        free(current->str);
        current->str = NULL;
        free(current);
        current = next;
    }
   root=NULL;
}




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


free_strings();

  

    return 0;
}


