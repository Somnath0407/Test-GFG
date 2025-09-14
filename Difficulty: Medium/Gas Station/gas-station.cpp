class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
    int totGas = 0, totCost = 0;
    for(int i = 0; i < gas.size(); i++) {
        totGas += gas[i];
    }
    for(int i = 0; i < cost.size(); i++) {
        totCost += cost[i];
    }
    if(totGas < totCost) {
        return -1;
    }

    int start = 0, currGas = 0;

    for(int i = 0; i < gas.size(); i++) {
        currGas += (gas[i] - cost[i]);

        if(currGas < 0) {
            start = i + 1;
            currGas = 0;
        }
    }

    return start;
        
    }
};