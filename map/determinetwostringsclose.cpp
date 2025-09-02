class Solution {
public:
    bool closeStrings(string word1, string word2) {

        int n = word1.size(); 
        int m = word2.size();

        if(n != m) return false;
        
        vector<int> freq1(26,0);

        vector<int> freq2(26,0);

         for(char ch : word1){
           freq1[ch-'a']++;
       }
       
       for(char ch : word2){
           
           freq2[ch-'a']++;
       }

      // check for same character are ther eot not 
      for(int i=0; i< 26; i++){
           if(freq1[i] !=0 && freq2[i] !=0) continue;
           if(freq1[i] ==0  && freq2[i] == 0) continue;
           else return false;
      }

      // step 2 check frequency;

      sort(freq1.begin(), freq1.end());
      sort(freq2.begin(), freq2.end());

      return (freq1==freq2);

    }
};