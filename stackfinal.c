void itop()
{
     int item;
     int temp;

     while((item = nextinput()) != EOF)
     {
          switch(item) {
               case '^':
               case '*':
               case '/':
               case '/':
               case '+':
               case '-':
               case '(':
               /* pop operators*/
               while(!empty() && isp(top_of_stk()) >= icp(item))
               putchar(pop());

               /* push new operator onto stack*/
               push(item);
               break;

               case ')':
               /* unstack until matching '('*/
               while((temp = pop()) != '(')
               putchar(temp);
               break;
               default:
               /* operand */
               putchar(item);
               break;

          }
     }

     while(!empty()) /* empty the rest of stack*/
     putchar(pop());
}