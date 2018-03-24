#include <iostream>
#include <cstdlib>//for "exit()" on some systems
#include <vector>
#include <string>

using namespace std;

//sorting algorithms
void bubbleSort(auto& data);
void selectionSort(auto& data);
void insertSort(auto& data);

int main()
{
	vector<string> inputs;
	string input;

	cout<<"Welcome to \"sort it\". We first need some input data."<<endl;
	cout<<"We'll assume the inputs do not have any spaces."<<endl<<endl;
	cout<<"To end input type the #-character (followed by Enter)"<<endl<<endl;

	cin>>input;

	while(input != "#")//read an unknown number of inputs from keyboard
	{
		inputs.push_back(input);
		cin>>input;
	}

	cout<<endl<<"["<<inputs.size()<<" values read from input source]"<<endl<<endl;

	if(inputs.size() == 0)//no input
	{
		cout<<endl<<"No input received, quiting..."<<endl<<endl;
		exit(1);//nothing to do but quit program
	}


	selectionSort(inputs);

	cout<<endl<<endl<<"Program \"sort it\" is now finished."<<endl<<endl;

	return 0;
}

void bubbleSort(auto& data)
{
	unsigned passes = 0;
	
	for(unsigned i = 0; i < data.size(); i++)
	{
		for(unsigned j = 0; j < data.size()-1; j++)
			if(data[j] > data[j+1])
				swap(data[j], data[j+1]);
		
		if((i+1) % 20000 == 0)
		{
			passes += 20000;
			cout << "Passes completed = " << passes << endl;
		}
	}
}

void selectionSort(auto& data)
{
	unsigned passes = 0;
	
	for(unsigned i = 0; i < data.size(); i++)
	{
		int small = i;
		
		for(unsigned j = i+1; j < data.size(); j++)
			if(data[j] < data[small])
				small = j;
		
		swap(data[i], data[small]);
		
		if((i+1) % 20000 == 0)
		{
			passes += 20000;
			cout << "Passes completed = " << passes << endl;
		}
	}
}

void insertSort(auto& data)
{
	unsigned passes = 0;
	
	for(unsigned i = 0; i < data.size()-1; i++)
	{
		int j = i+1;
		
		while(j > 0 and data[j] < data[j-1])
		{
			swap(data[j], data[j-1]);
			j--;
		}
		
		if((i+1) % 20000 == 0)
		{
			passes += 20000;
			cout << "Passes completed = " << passes << endl;
		}
	}
}
