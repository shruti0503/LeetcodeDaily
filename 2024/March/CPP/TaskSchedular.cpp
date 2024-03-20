#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
      // step 1: find freq 
      for(char c: tasks)
      freq[c-'A']++;

      // step 2: Insert freq in a max heap
      priority_queue<int> pq;
      for(int f: freq)
      pq.push(f);
     

      // step 3: find max freq - at last index after sorting
      int maxFreq= pq.top()-1;

      // step 4: find num of idle slots initially
      // pop the task with high freq because we are already allocating that task and in between those tasks we are bufferring with isle slots to maintain cool down time
      int idleSlots = maxFreq*n;
       pq.pop();
       
      // step 5: fill idle slots with other tasks
      // pop the next largest task
      // subtract those many tasks from idle slots
      // continue till all tasks in queue has been alloted in idle slots
      while(!pq.empty()){
      auto p = pq.top();
      pq.pop();
      idleSlots -= min(maxFreq, p);
    
      if(idleSlots<=0) 
      break;
      }
      
      // step 6: if there are any idle slots left even after filling all the tasks return idleSlots + total tasks else return total tasks count
      return idleSlots > 0 ? idleSlots + tasks.size(): tasks.size();
  
        
    }
};