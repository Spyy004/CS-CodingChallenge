class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>pickup,drop;
        for(int i=0;i<trips.size();i++)
        {
            pickup.push_back({trips[i][1],trips[i][0]});
            drop.push_back({trips[i][2],trips[i][0]});
        }
        sort(pickup.begin(),pickup.end());
        sort(drop.begin(),drop.end());
        int currentSize=0;
        int i=1,j=0;
        currSize+=pickup[0].second;
        while(i<pickup.size() && j<drop.size())
        {
            if(currSize>=capacity)
                return false;
            if(pickup[i].first<drop[j].first)
            {
                currSize+=pickup[i].second;
                i++;
            }
            else
            {
                currSize-=drop[j].second;
                j++;
            }
        }
        return true;
    }
};