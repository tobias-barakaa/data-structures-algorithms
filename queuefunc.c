void addNums()
{
     char i;
     int n1, n2, n3, carry, digit;

     while((i = nextinput()) != EOF) /* 1st added*/
     addq1(i);

     while((i = nextinput()) != EOF) /* 2nd added*/
     addq2(i);

     /** loop until both ques are empty*/

     carry = 0;
     while(!emptyql() && !emptyq2())
     {
          n1 = delq1() - '0';
          n2 = delq2() - '0';
          digit = n1 + n2 + carry;
          push(digit % 10);
          carry = digit / 10;
     }

     if (carry > 0)
     push(carry);

     while(!empty())
     printf("%d", pop());

     printf("\n")
}