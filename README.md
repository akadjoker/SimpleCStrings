# SimpleCStrings
implementation of strings in c with memory management

String *newString(const char* str);
String *copyString(String *s)
String *Trim(String *s)
String *TrimLeft(String *s)
String *TrimRight(String *s)
String *UpperString(String *s)
String *LowerString(String *s)
String ** SplitString(String *s, const char* delim)
String *JoinString(String **s,const char* delim)

void free_strings()