#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getMinSwaps(string nums, int k) {

            int size=nums.size();
            string cnums=nums;

            while (k--)
            {
                
                int i=size-2;
                multiset<char>dic;
                dic.insert(nums[i+1]);

                while(i>=0){

                    if(nums[i]<nums[i+1])
                        break;
                    dic.insert(nums[i]);
                    i--;
                }

                if(i==-1)
                    break;
                auto it=upper_bound(dic.begin(),dic.end(),nums[i]);
                char ele=nums[i];
                nums[i]=*it;
                dic.erase(it);
                dic.insert(ele);
                i++;

                for(auto ele:dic){
                    nums[i]=ele;
                    i++;
                }


            //cout<<cnums<<" "<<nums<<endl;
                /* code */
            }
            
            int count=0;

            int i;
            for(int i=0;i<size;){

                if(cnums[i]!=nums[i]){

                    int j=i+1;
                    while(j<size){
                        if(nums[j]==cnums[i])
                            break;
                        j++;
                    }

                    int k=j-1;
                    while (k>=i)
                    {
                        auto t=nums[k];
                        nums[k]=nums[k+1];
                        nums[k+1]=t;
                        count++;
                        k--;
                        //cout<<"updating :"<<cnums<<" "<<nums<<endl;
            
                        /* code */
                    }
                    
                    i++;

                }
                else{
                    i++;
                }


            }
            
            return count;


    }
};