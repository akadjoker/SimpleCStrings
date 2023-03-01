# SimpleCStrings
implementation of strings in c with memory management

String *newString(const char* str); <br>
String *copyString(String *s) <br>
String *Trim(String *s) <br>
String *TrimLeft(String *s)<br>
String *TrimRight(String *s)<br>
String *UpperString(String *s)<br>
String *LowerString(String *s)<br>
String ** SplitString(String *s, const char* delim)<br>
String *JoinString(String **s,const char* delim)<br>
bool    StringStartsWith(String *s,const char *find)<br>
bool    StringEndsWith(String *s,const char *find)<br>
String *SubString(String *s, int start, int end)<br>
bool    StringFind(String *s, String *find)<br>
int StringCompare(String *s, String *find)<br>

<br>
void free_strings()<br>
