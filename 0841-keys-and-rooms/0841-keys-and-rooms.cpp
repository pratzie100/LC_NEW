class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int currentroom=q.front();
            q.pop();
            for(int key:rooms[currentroom])
            {
                if(!visited[key])
                {
                    q.push(key);
                    visited[key]=true;
                }
            }
        }
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i]) return false;
        }
        return true;
        
        //fails for [[2],[],[1]]
        // bool ans=true;
        // for(int i=0;i<rooms.size()-1;i++)
        // {
        //     vector<int>v=rooms[i];
        //     bool keypresent=false;
        //     for(int j=0;j<v.size();j++)
        //     {
        //         if(v[j]==i+1)
        //         {
        //             keypresent=true;
        //         }
        //     }
        //     if(!keypresent) return false;
        // }
        // return true;
        
    }
};