///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   atof_ftoa.cpp
//  Author      :   Jimmy Han
//  Date        :   2014/07/07 17:09    v1    
//              :   2014/07/12 21:40    v2    
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h> // for print
#include <ctype.h> // for isspace, isdigit
#define ARRAY_MAX 20

/*
*atof        将字符串数组转换为double数字
*char s[]    输入字符数组
*double      输出浮点型
*/
double atof(char s[])
{
    int i, sign;
    int rate = 1;
    bool bDot = false;
    double ret;
 
    //skip the space
    for(i = 0; isspace(s[i]); i++)
        ;
 
    //get the sign
    sign = s[i] == '-' ? -1 : 1;
 
    //store the sign
    if(s[i] == '-' || s[i] == '+')
        i++;
 
    for(ret = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '.'){
            bDot = true;
            i++;
        }   
        //if interger part
        if(!bDot)
            ret = 10*ret + s[i] - '0';
        //if dot part
        else{
            rate*=10;
            //has to be explicit double cast, or int/int will not be right
            ret = ret + (double)((s[i] - '0'))/rate;
        }
    }
    return sign*ret;
}

/*
*ftoa   transfer double to char array
*dnum   input double number
*str    input char array
*len    input double length
*/
 
char *ftoa(double dnum,char *str,int len)
{
    int arrayNum[ARRAY_MAX];
    int pointPos=1;//the position of point
    int index=0;
    int i=0;
    if(dnum > 0)
    {
        //have only one bit for interger part
        while(dnum >= 10.0)
        {
            pointPos++;
            dnum/=10;
        }
 
        //convert to an integer array firstly
        for(i=0;i<len;i++)
        {
            if(i == pointPos)
            {
                //'0'-2 represent '.'
                arrayNum[i]=-2;
                //next for loop
                continue;
            }
            //get the integer part
            int num=dnum;
            arrayNum[i]=num;
            dnum-=num;
            dnum*=10;
        }
 
        //convert the integer to string
        for(i=0;i<len;i++)
        { 
            str[i]=arrayNum[i]+'0';
        }
        str[len]='\0';
    }
    return str;
}
 
int main()
{
    //atof test
    char s[] = "-92.5";
    double result = atof(s);
    printf("char=%s, double=%f\n",s, result);

    //ftoa test
    double flt=34.4324;
    char str[ARRAY_MAX];
    char *ret=ftoa(flt,str,7);
    printf("double=%f,char=%s\n",flt,ret);

    return 0;
}
