class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hash;
        unordered_map<int,int> :: iterator it;
        int num = answers.size();
        if(!num) return 0;
        int sum = 0;
        for(int i = 0;i < num; i++){
            if(!hash.empty()){
                it = hash.find(answers[i]);
                if(it != hash.end()){
                    hash.at(answers[i])++;
                }
                else
                    hash.insert(make_pair(answers[i], 1));
            }
            else{
                hash.insert(make_pair(answers[i], 1));
            }
        }
        for(auto i : hash){
            sum+=((i.second-1) / (i.first+1)+1) * (i.first+1);
        }
        return sum;
    }
};