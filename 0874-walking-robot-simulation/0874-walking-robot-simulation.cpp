class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction=1;
        int x=0;
        int y=0;
        int c=0;
        set<pair<int,int>>obs;
        for(auto i:obstacles){
            obs.insert({i[0],i[1]});
        }
        int maxid=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                if(direction==1) direction=2;
                else if(direction==2) direction=3;
                else if(direction==3) direction=4;
                else if(direction==4) direction=1;
            }
            else if(commands[i]==-2){
                if(direction==1) direction=4;
                else if(direction==2) direction=1;
                else if(direction==3) direction=2;
                else if(direction==4) direction=3;
            }
            else{
                int com=commands[i];
                if(direction==1){
                    if(c>0 && obs.count({x,y}))continue;
                    while(com--){
                        c=1;
                        y+=1; 
                        if(obs.count({x,y})){ y-=1;break;};
                        int j=pow(x,2)+pow(y,2);
                        maxid=max(maxid,j);
                        cout<<x<<","<<y<<endl;
                        
                    }
                }
                else if(direction==2){
                    if(c>0 && obs.count({x,y})) continue;
                    while(com--){
                        c=1;
                        x+=1;
                        if(obs.count({x,y})) { x-=1;break;};
                        int j=pow(x,2)+pow(y,2);
                        maxid=max(maxid,j);
                        cout<<x<<","<<y<<endl;
                        
                    }
                }
                else if(direction==3){
                    if( c>0 && obs.count({x,y})) continue;
                    while(com--){
                        c=1;
                        y-=1;
                        if(obs.count({x,y})) { y+=1;break;};
                        int j=pow(x,2)+pow(y,2);
                        maxid=max(maxid,j);
                        cout<<x<<","<<y<<endl;
                        
                    }
                }
                else if(direction==4){
                    if( c>0 &&  obs.count({x,y})) continue;
                    while(com--){
                        c=1;
                        x-=1;
                        if(obs.count({x,y})) { x+=1;break;};
                        int j=pow(x,2)+pow(y,2);
                        maxid=max(maxid,j);
                        cout<<x<<","<<y<<endl;
                        
                    }
                }
            }
        }
        return maxid;
    }
};