
class Solution {
public:
    bool splitString(string s) {
        
        
        int i=0;
        while(s[i]){
            if(s[i]=='0')
                i++;
            else{
                break;
            }
        }
        
        int size=s.size();
        
        
        //cout<<"New :"<<s<<endl;
        i=0;
        
        while(i<(1<<size)){
            
            bool space =false;
            
            int number=i;
            
            vector<bool>arr;
            
            int times=0;
            
            while(times<32){
                arr.push_back((number&(1<<times))==0);
                
                times++;
            }
            
            
            int j=0;
            
            vector<long long>splittedNum;
            
            
            while(j<32){
                
                int k=j;
                string childS;
                
                while(k<32){
                    
                    if(arr[j]==arr[k])k++;
                    else break;
                    
                }
                
                
                if(j!=size){
                    childS=s.substr(j,k-j);
                
                    int ind=0;

                    string newChildS;


                    //cout<<"input :"<<childS<<"--";
                    
                    int index=0;
                    for(auto ele:childS){
                        if(!(ele>='0'&&ele<='9')){
                            break;
                        }
                        index++;
                    }
                    
                    childS=childS.substr(0,index);
                    splittedNum.push_back(stoll(childS,nullptr,10));

                }
                j=k;
                
                
            }
            
            int I=1;
            bool flag=true;
            //cout<<"\nhere :"<<splittedNum.size()<<endl;
            
            reverse(splittedNum.begin(),splittedNum.end());
            
            
            while(I<splittedNum.size()){
                //cout<<splittedNum[I]<<" "<<splittedNum[I-1]<<"--";
                if(splittedNum[I]-splittedNum[I-1]!=1)
                {
                    flag=false;
                    break;
                }
                I++;
            }
            
            if(flag&&splittedNum.size()>1&&!space)
                return true;
            
            
            //cout<<endl;
            
                
            
            
            i++;
        }
        
        return false;
        
    }
};