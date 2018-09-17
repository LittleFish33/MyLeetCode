class Solution {
public:
    string frequencySort(string s) 
    {
        vector<pair<int,char> > a(128);
        for(int i=0;i<128;i++)
            a[i] = make_pair(0,char('0'-48+i));
        for (int i=0;i<s.length();i++)
            a[s[i]].first++;
        sort(a.begin(),a.end());
        string res="";
        for(int i=127;i>=0;i--)
        {
            if(a[i].first==0)
                break;
            else
            {
                for(int j=0;j<a[i].first;j++)
                    res+=a[i].second;
            }
        }
        return res;
        
    }
};