#define OK 0
#define ERR -1

int check_paren(char data[])
{
     int i;
     for (i = 0; data[i] != NULL; i++)
     {
      switch (data[i]){
          case '{':
          case '[':
          case '(':
            push (data[i]);
            break;
          case '}':
          if(empty() || pop() != '{')
          return (ERR);
          break;
          case ']':
          if(empty() || pop() != '[')
          return (ERR);
          case ')':
          if(empty() || pop() != '(')
          return (ERR);
      }
     }
     if(empty())
     return (OK);
     return (ERR);
}