//
//  main.cpp
//  np
//
//  Created by sam on 2016/11/1.
//  Copyright © 2016年 sam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;


int isSpace(char c){
    if(c==' ' || c=='\t')
        return 1;
    return 0;
}
int isDigit(char c){
    if( (c-'0')>=0 &&  (c-'0')<=9)
        return 1;
    return 0;
}
int isReturn(char c){
    if(c=='\n' || c=='\r')
        return 1;
    return 0;
}

int isEnd(char c){
    if(c=='\0')
        return 1;
    return 0;
}

vector<string> split(string command){
    
    vector<string>result;
    string del=" ";
    int pos;
    for(int j=0;j<command.length();j++){
        pos=command.find(del,j);  //從引發find的字串物件第j個字元尋找是否有符合string的子字串。
        if(pos<command.length()){
            string temp=command.substr(j,pos-j); //substr(start,length) length是從start開始的長度（包括start)
            result.push_back(temp);
            j=pos+del.size()-1;
        }
        
    }
    return result;
    
}

void parseCmd(int &i,string in,string &command,string &filename,int &pipeNum, int &condition){
    
    
    string pipenum="";
    int have_command=0;
    
    
    while(i<in.length()){
        if(in[i]=='|'){
            condition=1;
            i++;
            if(isSpace(in[i])){            //把removetag test.html | number當成兩個command(removetag test.html和number)
                pipenum="1";
                have_command=1;
                break;
            }else{
                while(isDigit(in[i])){
                    pipenum=pipenum+in[i];
                    i++;
                }
            }
        }else if(in[i]=='>'){
            condition=2;
            while(isSpace(in[++i])){};
            while(!isSpace(in[i]) && !isReturn(in[i]) && !isEnd(in[i])){
                filename=filename+in[i];
                i++;
            }
        }else{
            command=command+in[i];
            i++;
        }
    }
    if(condition==1){
        if(pipenum!="")
            pipeNum=stoi(pipenum);
        else
            pipeNum=0;
    }
}

void processCmd(string command){
    char *tok;
    command=command.c_str();
    while(tok!=NULL){
        tok=strtok(command," ");
        tok=strtok(NULL," ");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while(1){
        string in;
        //string command;
        //string filename;
        //int pipeNum=0;

        getline(cin,in);
        int i=0;
        int condition=0;  //   '|' condition=1, '>' condition=2
        while(i<in.length()){
            string command;
            string filename;
            int pipeNum=0;
            while(isSpace(in[i])){
                i++;
            }
            parseCmd(i,in,command,filename,pipeNum,condition);
            processCmd(command);
            /*cout << "command is = "<< command <<endl;
            cout << "filename is = "<< filename <<endl;
            cout << "pipenum is = "<< pipeNum <<endl;*/
            
            if(condition==1){
                
            }else if(condition==2){
                
            }else{
                
            }

            
        }

    }
        
    

    return 0;
}
