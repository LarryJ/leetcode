/*******************************
Given an array S of n integers, 
are there elements a, b, c, and d 
in S such that 
a + b + c + d = target? Find all 
unique quadruplets in the array 
which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) 
must be in non-descending order. 
(ie, a ≤ b ≤ c ≤ d)
The solution set must not contain 
duplicate quadruplets.

For example, given array 
S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*******************************/
struct TwoSum
{
  int value;
  int pos1;
  int pos2;
};

typedef vector<vector<int> > vec_int;
typedef vector<TwoSum> vec_ts;

bool my_compare(TwoSum a, TwoSum b)
{
  if (a.value != b.value)
    return a.value < b.value;
  else
  {
    if (a.pos1 != b.pos1)
      return a.pos1 < b.pos1;
    else
      return a.pos2 < b.pos2;
  }
}

class Solution {
public:
    vec_ts v;
    vec_int result;
    size_t my_binary_search_begin(int value, int begin, int end)
    {
      int middle = 0;
      while (begin <= end)
      {
	middle = (begin + end) / 2;
	if (v[middle].value >= value)
	  end = middle - 1;
	else
	  begin = middle + 1;
      }
      return end + 1;
    }

    size_t my_binary_search_end(int value, int begin, int end)
    {
      int middle = 0;
      while (begin <= end)
      {
	middle = (begin + end) / 2;
	if (v[middle].value > value)
	  end = middle - 1;
	else
	  begin = middle + 1;
      }
      return begin - 1;
    }

    void cut_the_tail(int target)
    {
      //remove elements at tail
      while (!v.empty())
      {
	if (v[v.size() - 1].value + v[0].value <= target)
	  break;
	else
	  v.pop_back();
      }
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (num.size() < 4)
	return result;
      //O(n ^ 2)
      v.clear();
      result.clear();
      for (size_t i = 0; i < num.size(); ++i)
      {
	for (size_t j = i + 1; j < num.size(); ++j)
	{
	  TwoSum t;
	  t.value = num[i] + num[j];
	  t.pos1 = i;
	  t.pos2 = j;
	  v.push_back(t);
	}
      }
      //O(n ^ 2 log (n ^ 2))
      sort(v.begin(),  v.end(), my_compare);
      //O(n)
      cut_the_tail(target);
      for (size_t i = 0; i < v.size(); ++i)
      {
	//O(log (n ^ 2))
	size_t begin = my_binary_search_begin(target - v[i].value, i + 1, v.size() - 1);   //reduce the running time
	size_t end = my_binary_search_end(target - v[i].value, i + 1, v.size() - 1);     //reduce the running time
	//O(n ^ 2)
	for (size_t j = begin; j <= end; ++j)
	{
	  
	  if (v[i].pos1 == v[j].pos1 || v[i].pos2 == v[j].pos1
	      || v[i].pos1 == v[j].pos2 || v[i].pos2 == v[j].pos2)    //v[m] and v[n] share a same element
	    continue;
	  else
	  {
	    vector<int> temp;
	    temp.push_back(num[v[i].pos1]);
	    temp.push_back(num[v[i].pos2]);
	    temp.push_back(num[v[j].pos1]);
	    temp.push_back(num[v[j].pos2]);
	    sort(temp.begin(), temp.end());
	    if (find(result.begin(), result.end(), temp) == result.end())
	      result.push_back(temp);
	  }
	}
      }
      return result;
    }
};
