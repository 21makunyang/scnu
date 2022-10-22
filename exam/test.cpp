#include<iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outfile("data1.txt", ios::out|ios::binary);
	for(float i = 0; i<10; i++)
	{
		outfile.write((char*)&i,sizeof(float));
	}
	outfile.close();
	ifstream infile("data1.txt", ios::in|ios::binary);

	float nums[10];
	infile.read((char*)&nums[0],sizeof(int));
	float max = nums[0], min = nums[0], sum = nums[0];

	for (int i = 1; i < 10; i++)
	{
		infile.read((char*)&nums[i],sizeof(float));
		if (max < nums[i]) max = nums[i];
		if (min > nums[i]) min = nums[i];
		sum += nums[i];
	}
	infile.close();

	outfile.open("data1.txt", ios::app|ios::binary);
	outfile.write((char*)&max,sizeof(float));
	outfile.write((char*)&min,sizeof(float));
	outfile.write((char*)&sum,sizeof(float));
	outfile.close();

	infile.open("data1.txt", ios::in|ios::binary);
	outfile.open("data2.txt", ios::out|ios::binary);
	float input= 0;
	double n=0;
	while (infile.read((char*)&input,sizeof(float)))
	{
		outfile.write((char*)&input,sizeof(float));
	}
	outfile.close();
	infile.close();
	return 0;
}
