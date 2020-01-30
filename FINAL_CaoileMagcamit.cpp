#include <iostream>
//fstream is a stream class to both read and write from/to files.
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;

int main()
{
    DIR *folder; //directory chuchu
    struct dirent *entry;
    int fileCount=0; 
    string file[100] = "";

	//this opens the folder where this file is saved
   folder = opendir("C:\\Users\\hp\\Desktop\\LBYCPD2\\MODULE 1.5\\folder");
   //folder = opendir(".");
    if(folder == NULL){
        perror("Unable to read directory"); //to check if the program reads the directory.
        return 1;
    }

    while(entry=readdir(folder)){
    	file[fileCount] += entry->d_name;  //adds the files into an array.
		fileCount++;
    }
    
    
    for(int f=0;f<fileCount;f++){
    	cout<<file[f]<<"\n";
	}
    closedir(folder);
    
    //this starts at 2 because the first two files from the directory are only period
    
	char file1[100000]; 
	char file2[100000];
	
	int counter = 0;
	
	for(int i=2; i<fileCount; i++){ 
		for(int j=2; j<fileCount; j++){ 
			strcpy(file1, file[i].c_str()); //copy
			cout<<"PSJFSKDJ"<<"\n";
			file1 = "C:\\Users\\hp\\Desktop\\LBYCPD2\\MODULE 1.5\\folder\\"+file1;
			cout<<file1;
			ifstream inFile(file1);
			string line1[10000];
			string line2[10000];
			int a=0;
			int b=0;
			
			//its not opening it grr
			if(inFile.is_open()){
				while(!inFile.eof()){
					getline(inFile, line1[a], '\n');
					//cout<<line1[a]<<'\n';
					cout<<"PUPU";
				}
				inFile.close();
			}
		
			cout<<"\n";
			
			strcpy(file2, file[j].c_str());
			ifstream inFile2(file2);
			if(inFile2.is_open()){
				while(!inFile2.eof()){
					getline(inFile2, line2[b], '\n');
				//	cout<<line2[b]<<'\n';
					b++;
				}
				
				cout<<b<<"\n";
				inFile2.close();
			}
			
			int counter1=0;
			double total1 = a+b, different1=0;//checkers
			double percent1=0;
		
			if(a>b){
				for(int x=0; x<a; x++){
					if(line1[x]==line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1);
				counter++;
				cout<<"\n";
				cout<<counter;
				cout<<" Similarity Percentage:";
				std::cout << std::fixed << std::setprecision(2) << percent1;
				cout<<'\n';
			}
			else{
				for(int x=0; x<b; x++){
					if(line1[x]==line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1);
				counter++;
				cout<<"\n";
				cout<<counter;
				cout<<" Similarity Percentage:";
				std::cout << std::fixed << std::setprecision(2) << percent1;
				cout<<'\n';
			}
			//cout<<"\n\nNEXT FILE!!\n\n";
		}	
	}
	
    return 0;
}
