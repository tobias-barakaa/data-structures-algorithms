int eval()
{
     int temp, item;
     while((item = nextitem()) != EOF)
     {
          switch(item){
               case '+':
               /*watch order of operands*/
               temp = pop();
               push(pop() + temp);
               break;
               case '-':
               temp = pop();
               push(pop() - temp);
               break;
               case '/':
               temp = pop();
               push( pop()/ temp);
               break;
               case '^':
               temp = pop();
               push(power(pop(), temp) );
               break;
               default:
               push(item);
               break;
          }
     }
     return (pop());
}