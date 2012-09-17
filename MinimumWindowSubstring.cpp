class Solution {
public:
  string minWindow(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    // two histogram: a for S and b for T
    int a[256], b[256];
    for(int i = 0; i < 256; i++) {
      a[i] = b[i] = 0;   
    }
    for(int i = 0; i < T.size(); i++) {
      b[T[i]]++;
    }
    int start = 0;
    int end = 0;
    string result = "";
    while(start < S.size()) {
      // create histogram for a
      // if it covers b, start++; else end++
      if(cover(a, b)) {
	string validString = S.substr(start, (end - start));
	if(result == "") {
	  result = validString;
	} else {
	  if(validString.size() < result.size()) {
	    result = validString;
	  }
	}
	a[S[start]]--;
	start++;
      } else {
	if(end < S.size()) {
	  a[S[end]]++;
	  end++;
	} else {
	  break;
	}
      }
    }
    return result;
  }
     
  bool cover(int a[], int b[]) { // n is 256
    for(int i = 0; i < 256; i++) {
      if(b[i] > a[i]) {
	return false;
      }
    }
    return true;
  }
};
