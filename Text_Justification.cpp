/*******************************
Given an array of words and a 
length L, format the text such 
that each line has exactly L 
characters and is fully 
(left and right) justified.

You should pack your words in a 
greedy approach; that is, pack 
as many words as you can in each 
line. Pad extra spaces ' ' when 
necessary so that each line has 
exactly L characters.

Extra spaces between words should 
be distributed as evenly as 
possible. If the number of spaces 
on a line do not divide evenly 
between words, the empty slots on 
the left will be assigned more 
spaces than the slots on the right.

For the last line of text, it 
should be left justified and no 
extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", 
"of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed 
not to exceed L in length. 

Corner Cases:

A line other than the last line 
might contain only one word. 
What should you do in this case?
In this case, that line should 
be left-justified.
*******************************/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<string> result;
      result.clear();
      if (words.size() == 0)
	return result;
      if (words.size() == 1)
      {
      	string s(words[0]);
      	for (size_t i = s.size(); i < L; ++i)
      	  s += ' ';
      	result.push_back(s);
      	return result;
      }
      typedef pair<int, int> my_pair;
      vector<my_pair> v;
      v.clear();
      int length = 0;
      for (size_t i = 0; i < words.size(); ++i)
      {
	if (length == 0)
	  length = words[i].size();  //no word exceeds L in length
	else
	{
	  if (length + words[i].size() + 1 > L)
	  {
	    --i;
	    v.push_back(my_pair(i, length));
	    length = 0;
	  }
	  else
	    length += words[i].size() + 1;
	}
      }
      if (length > 0)
	v.push_back(my_pair(words.size() - 1, length));
      int pos = 0;
      for (size_t i = 0; i < v.size(); ++i)
      {
	string s = words[pos++];
	v[i].second -= s.size();
	while (pos <= v[i].first)
	{
	  //append spaces
	  int n = v[i].first - pos + 1;  //number of words left
	  if (n == 0)
	    break;
	  if (i != v.size() - 1)   //last line
	  {
	    double space = (L - s.size() - v[i].second) / (double)n;
	    for (int k = 0; k < int(space); ++k)
	      s += ' ';
	    if (space != int(space))  //add 1 more space
	      s += ' ';
	  }
	  s += ' ';   //space separate words
	  s += words[pos];
	  v[i].second -= words[pos].size() + 1;
	  ++pos;
	}
	//only one word in the line
	while (s.size() < L)
	  s += ' ';
	result.push_back(s);
      }
      return result;
    }
};
