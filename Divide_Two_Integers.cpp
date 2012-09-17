/*******************************
Divide two integers without 
using multiplication, 
division and mod operator. 
*******************************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      if (divisor == 0)
	return -1;
      if (dividend == 0)
	return 0;
      if (dividend == divisor)
	return 1;
      //avoid result overflow
      if (divisor == 1)
	return dividend;
      if (divisor == -1)
	return -dividend;
      int result = 0;
      int sign = 1;
      if (dividend < 0)
      {
	if (divisor < 0)
	{
	  if (dividend > divisor)
	    return 0;
	  else
	  {
	    divisor = -divisor;
	    dividend = -(dividend + divisor);  //avoid dividend overflow
	    result += 1;
	  }
	}
	else   //different sign
	{
	  if (dividend + divisor > 0)
	    return 0;
	  else
	  {
	    dividend = -(dividend + divisor);
	    sign = -1;
	    result += 1;
	  }
	}
      }
      else
      {
	if (divisor > 0)
	{
	  if (dividend < divisor)
	    return 0;
	}
	else  //different sign
	{
	  if (dividend + divisor < 0)
	    return 0;
	  else
	  {
	    divisor = -divisor;
	    sign = -1;
	  }
	}
      }
      while (dividend >= divisor)
      {
	int mul = 1;
	int sub = divisor;
	while (dividend -sub >= sub)
	{
	  sub += sub;
	  mul += mul;
	}
	dividend -= sub;
	result += mul;
      }
      return (sign < 0) ? -result: result;
    }
};
