//Akshar Patel in consideration for 
//software engineer intern at Yodle 
//in New York
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<double> > triangle; 
	double val; 
	double row_length = 1; 
	//input the triangle increasing the vector size by one everytime the for loop ends
	while(!(cin.eof()))
	{
		vector<double> row; 
		//cout<<"doing things "<<endl;
		for(int i = 0; i < row_length; i++)
		{
			cin>>val;
			//cout<<"val is "<<val<<endl;
			if(!cin.eof())row.push_back(val); 
		}
		if(!cin.eof())
		{
			row_length++;
			//cout<<"enters "<<row_length<<endl;
			triangle.push_back(row); 
		}
	}
	//cout<<"rowlength is "<<triangle.size()<<endl;
	
	//assumption is made that the triangle is indeed a triangle 
	//and therefore the calculations start in row 2 and not row 1 
	
	double above = 0;
	double above_left = 0;
	for(unsigned int i = 1; i < triangle.size(); i++)
	{
		vector<double> row_up = triangle[i - 1]; //get the two vectors
		vector<double> row = triangle[i]; 
		for (unsigned int j = 0; j < row.size(); j++)
		{
			//the two corner cases being the first and last number in the row
			//only look at the one number above it
			if(j == 0) 
			{
				triangle[i][j] += row_up.front(); 
			}
			else if(j + 1 == row.size())
			{
				triangle[i][j] += row_up.back();
			}
			else //otherwise look at the two indices and add the bigger number to itself
			{
				above = row_up[j];
				above_left = row_up[j-1];
				if (above > above_left)
				{
					triangle[i][j] += above; 
				}
				else 
				{
					triangle[i][j] += above_left; 
				}
			}
		}
	}
	//find the max amongst the last row
	vector<double> final_row = triangle.back(); 
	double final_result = 0;
	for (unsigned int i = 0; i < final_row.size(); i++)
	{
		if(final_result < final_row[i])
		{
			final_result = final_row[i];
		}
	}
	//output the final result
	cout<<"The maximum sum down the entire triangle with adjacent numbers on the number below is "<< final_result <<endl;
}