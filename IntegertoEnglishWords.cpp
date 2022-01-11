class Solution {
public:
    
    unordered_map<int, string> list;
    
    string mapnumber(int num){
        int temp = num;
        num = num/100;
        string str_val = "";
        if(num>0){
            str_val += list[num];
            str_val += "Hundred ";
            
        }
        num = temp % 100;
        temp = num;
        if(num>0){
            if(num/10 == 1){
                str_val += list[num];
            }
            else if (num/10 == 0){
                str_val += list[num%10];
            }
            else{
                num /= 10;
                num *= 10;
                str_val += list[num];
                num = temp%10;
                if(num>0){
                   str_val += list[num]; 
                }
            }
        }
        return str_val;
    }
       
    string numberToWords(int num) {
        //init the list
        list[0] = "Zero ";
        list[1] = "One ";
        list[2] = "Two ";
        list[3] = "Three ";
        list[4] = "Four ";
        list[5] = "Five ";
        list[6] = "Six ";
        list[7] = "Seven ";
        list[8] = "Eight ";
        list[9] = "Nine ";
        list[10] = "Ten ";
        list[11] = "Eleven ";
        list[12] = "Twelve ";
        list[13] = "Thirteen ";
        list[14] = "Fourteen ";
        list[15] = "Fifteen ";
        list[16] = "Sixteen ";
        list[17] = "Seventeen ";
        list[18] = "Eighteen ";
        list[19] = "Nineteen ";
        list[20] = "Twenty ";
        list[30] = "Thirty ";
        list[40] = "Forty ";
        list[50] = "Fifty ";
        list[60] = "Sixty ";
        list[70] = "Seventy ";
        list[80] = "Eighty ";
        list[90] = "Ninety ";
        
        string str_val = "";
        
        if(num == 0){
            str_val += list[num];
        }    
        
        int temp = num;
        num /= 1000000000;
        if (num>0){
            str_val += mapnumber(num);
            str_val += "Billion ";
        }
        
        num = temp % 1000000000;
        temp = num;
        num /= 1000000;
        if (num>0){
            str_val += mapnumber(num);
            str_val += "Million ";
        }
        
        num = temp % 1000000;
        temp = num;
        num /= 1000;
        if (num>0){
            str_val += mapnumber(num);
            str_val += "Thousand ";
        }
        
        num = temp % 1000;
        if (num>0){
            str_val += mapnumber(num);
        }
         
        str_val.erase (str_val.end()-1);
        return str_val;
    }
};
